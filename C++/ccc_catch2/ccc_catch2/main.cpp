//
//  main.cpp
//  ccc_catch2
//
//  Created by huangwei on 2020/9/22.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <functional>
#include <stdexcept>

using namespace std;

struct SpeedUpdate {
    double velocity_mps;
};

struct CarDetected {
    double distance_m;
    double velocity_mps;
};

struct BreakCommand {
    double time_to_collision_s;
};

typedef function<void(const SpeedUpdate&)> SpeedUpdateCallBack;
typedef function<void(const CarDetected&)> CarDetectedCallBack;

// Interface
struct IServiceBus {
    virtual ~IServiceBus() = default;
    virtual void publish(const BreakCommand&) = 0;
    virtual void subscribe(SpeedUpdateCallBack) = 0;
    virtual void subscribe(CarDetectedCallBack) = 0;
};

struct MockServiceBus: IServiceBus {
    void publish(const BreakCommand &cmd) override {
        commands_published++;
        last_command = cmd;
    }
    
    void subscribe(CarDetectedCallBack callback) override {
        car_detected_callback = callback;
    }
    
    void subscribe(SpeedUpdateCallBack callback) override {
        speed_update_callback = callback;
    }
    BreakCommand last_command{};
    int commands_published{};
    SpeedUpdateCallBack speed_update_callback{};
    CarDetectedCallBack car_detected_callback{};
};

struct AutoBrake {
    AutoBrake(IServiceBus& bus)
    : collision_threadhold_s{ 5 },
    speed_mps{} {
        bus.subscribe([this](const SpeedUpdate& update) { speed_mps = update.velocity_mps; });
        bus.subscribe([this, &bus](const CarDetected& cd) {
            auto relative_velocity_mps = speed_mps - cd.velocity_mps;
            auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
            if (time_to_collision_s > 0 && time_to_collision_s <= collision_threadhold_s) {
                bus.publish(BreakCommand{ time_to_collision_s });
            }
        });
    }
    
    void set_collision_threadhold_s(double x) {
        if (x < 1) {
            throw  runtime_error("Collision less than 1");
        }
        collision_threadhold_s = x;
    }
    
    double get_collision_threadhold_s() const {
        return collision_threadhold_s;
    }
    
    double get_speed_mps() const {
        return speed_mps;
    }
private:
    double collision_threadhold_s;
    double speed_mps;
};


// 精华来了！开始Testing！

TEST_CASE("AutoBrake") {
    // setup code
    MockServiceBus bus{};
    AutoBrake auto_break{ bus };
    
    SECTION("initializes speed to zero") {
        REQUIRE(auto_break.get_speed_mps() == Approx(0));
    }
    
    SECTION("initializes sensitivity to five") {
        REQUIRE(auto_break.get_collision_threadhold_s() == Approx(5));
    }
    
    SECTION("throws when sensitivity less than one") {
        REQUIRE_THROWS(auto_break.set_collision_threadhold_s(0.5L));
    }
    
    SECTION("saves speed after update") {
        bus.speed_update_callback(SpeedUpdate{ 100L });
        REQUIRE(100L == auto_break.get_speed_mps());
        bus.speed_update_callback(SpeedUpdate{ 50L });
        REQUIRE(50L == auto_break.get_speed_mps());
        bus.speed_update_callback(SpeedUpdate{ 0L });
        REQUIRE(0L == auto_break.get_speed_mps());
    }
    
    SECTION("no alert when not imminent") {
        auto_break.set_collision_threadhold_s(2L);
        bus.speed_update_callback(SpeedUpdate{ 100L });
        bus.car_detected_callback(CarDetected{ 1000L, 50L });
        REQUIRE(bus.commands_published == 0);
    }
    
    SECTION("alert when imminent") {
        auto_break.set_collision_threadhold_s(10L);
        bus.speed_update_callback(SpeedUpdate{ 100L });
        bus.car_detected_callback(CarDetected{ 100L, 0L });
        assert(bus.commands_published == 1);
        assert(bus.last_command.time_to_collision_s == Approx(1));
    }
}
