//
//  main.cpp
//  ccc_boost_test
//
//  Created by huangwei on 2020/9/23.
//
#define BOOST_TEST_MODULE AutoBrakeTestModule
#include <boost/test/included/unit_test.hpp>

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


// setup code 在外面

struct AutoBrakeTest {
    MockServiceBus bus{};
    AutoBrake auto_break{ bus };
};

BOOST_FIXTURE_TEST_CASE(InitialCarSpeedIsZero, AutoBrakeTest) {
  BOOST_TEST(0 == auto_break.get_speed_mps());
}

BOOST_FIXTURE_TEST_CASE(InitialSensitivityIsFive, AutoBrakeTest) {
  BOOST_TEST(5 == auto_break.get_collision_threshold_s());
}

BOOST_FIXTURE_TEST_CASE(SensitivityGreaterThanOne, AutoBrakeTest) {
  BOOST_REQUIRE_THROW(auto_break.set_collision_threshold_s(0.5L), exception);
}

BOOST_FIXTURE_TEST_CASE(SpeedIsSaved, AutoBrakeTest) {
  bus.speed_update_callback(SpeedUpdate{ 100L });
  BOOST_TEST(100 == auto_break.get_speed_mps());
  bus.speed_update_callback(SpeedUpdate{ 50L });
  BOOST_TEST(50 == auto_break.get_speed_mps());
  bus.speed_update_callback(SpeedUpdate{ 0L });
  BOOST_TEST(0 == auto_break.get_speed_mps());
}

BOOST_FIXTURE_TEST_CASE(NoAlertWhenNotImminent, AutoBrakeTest) {
  auto_break.set_collision_threshold_s(2L);
  bus.speed_update_callback(SpeedUpdate{ 100L });
  bus.car_detected_callback(CarDetected{ 1000L, 50L });
  BOOST_TEST(0 == bus.commands_published);
}

BOOST_FIXTURE_TEST_CASE(AlertWhenImminent, AutoBrakeTest) {
  auto_break.set_collision_threshold_s(10L);
  bus.speed_update_callback(SpeedUpdate{ 100L });
  bus.car_detected_callback(CarDetected{ 100L, 0L });
  BOOST_TEST(1 == bus.commands_published);
  BOOST_TEST(1L == bus.last_command.time_to_collision_s);
}
