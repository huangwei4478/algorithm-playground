//
//  main.cpp
//  ccc_smart_pointer
//
//  Created by huangwei on 2020/9/23.
//
#define CATCH_CONFIG_MAIN
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <catch2/catch.hpp>
#include <utility>

struct DeadMenOfDunharrow {
  DeadMenOfDunharrow(const char* m = "")
      : message{ m } {
    oaths_to_fulfill++;
  }
  ~DeadMenOfDunharrow() {
    oaths_to_fulfill--;
  }
  const char* message;
  static int oaths_to_fulfill;
};
int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to ") {
  SECTION("true when full") {
    ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
    REQUIRE(aragorn);
  }
  SECTION("false when empty") {
    ScopedOathbreakers aragorn;
    REQUIRE_FALSE(aragorn);
  }
}

TEST_CASE("ScopedPtr is an RAII wrapper") {
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
    ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    {
        ScopedOathbreakers legolas{ new DeadMenOfDunharrow{} };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    }
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}

TEST_CASE("ScopedPtr supports pointer semantics, like") {
  auto message = "The way is shut.";
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{ message } };
  SECTION("operator*") {
    REQUIRE((*aragorn).message == message);
  }
  SECTION("operator->") {
    REQUIRE(aragorn->message == message);
  }
  SECTION("get(), which returns a raw pointer") {
    REQUIRE(aragorn.get() != nullptr);
  }
}

TEST_CASE("ScopedPtr supports comparison with nullptr") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow{} };
  ScopedOathbreakers legolas{};
  SECTION("operator==") {
    REQUIRE(legolas == nullptr);
  }
  SECTION("operator!=") {
    REQUIRE(aragorn != nullptr);
  }
}

TEST_CASE("ScopedPtr supports swap") {
  auto message1 = "The way is shut.";
  auto message2 = "Until the time comes.";
  ScopedOathbreakers aragorn1{ new DeadMenOfDunharrow{ message1 } };
  ScopedOathbreakers aragorn2{ new DeadMenOfDunharrow{ message2 } };
  REQUIRE(aragorn1->message == message1);
  aragorn1.swap(aragorn2);
  REQUIRE(aragorn2->message == message1);
  REQUIRE(aragorn1->message == message2);
}

TEST_CASE("ScopedPtr.reset() ") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
  SECTION("destructs object.") {
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    aragorn.reset();
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
  }
  SECTION("can replace an object.") {
    auto message = "It was made by those who are Dead.";
    auto new_dead_men = new DeadMenOfDunharrow{ message };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    aragorn.reset(new_dead_men);
    REQUIRE(aragorn->message == message);
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
}

void by_ref(const ScopedOathbreakers&) {}
void by_val(ScopedOathbreakers) {}
TEST_CASE("ScopedPtr can") {
  ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
  SECTION("be passed by reference") {
    by_ref(aragorn);
  }
  SECTION("not be copied") {
    // DOES NOT COMPILE:
    // by_val(aragorn);
    // auto son_of_arathorn = aragorn;
  }
  SECTION("not be moved") {
    // DOES NOT COMPILE:
    // by_val(std::move(aragorn));
    // auto son_of_arathorn = std::move(aragorn);
  }
}

#include <boost/smart_ptr/scoped_array.hpp>

TEST_CASE("ScopedArray supports operator[]") {
    boost::scoped_array<int> squares{ new int[5]{1, 4, 9, 16, 25 }};
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}

#include <memory>
using UniqueOathBreakers = std::unique_ptr<DeadMenOfDunharrow>;
TEST_CASE("UniquePtr can be used in move") {
    auto aragorn = std::make_unique<DeadMenOfDunharrow>();
    SECTION("construction") {
        auto son_of_arathorn{ std::move(aragorn) };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment") {
        auto son_of_arathorn = std::make_unique<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = std::move(aragorn);
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}

TEST_CASE("UniquePtr to array supports operator[]") {
  std::unique_ptr<int[]> squares{ new int[5]{ 1, 4, 9, 16, 25 } };
  REQUIRE(squares[0] == 1);
  REQUIRE(squares[1] == 4);
  REQUIRE(squares[2] == 9);
}

using SharedOathbreakers = std::shared_ptr<DeadMenOfDunharrow>;

TEST_CASE("SharedPtr can be used in copy") {
  auto aragorn = std::make_shared<DeadMenOfDunharrow>();
  SECTION("construction") {
    auto son_of_arathorn{ aragorn };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
  SECTION("assignment") {
    SharedOathbreakers son_of_arathorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    son_of_arathorn = aragorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
  SECTION("assignment, and original gets discarded") {
    auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
    son_of_arathorn = aragorn;
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
  }
}

using WeakOathbreakers = std::weak_ptr<DeadMenOfDunharrow>;

TEST_CASE("WeakPtr") {
    auto message = "the way is shut";
    SECTION("lock() yields a shared pointer") {
        auto aragon = std::make_shared<DeadMenOfDunharrow>(message);
        WeakOathbreakers legolas { aragon };
        auto sh_ptr = legolas.lock();
        REQUIRE(sh_ptr -> message == message);
        REQUIRE(sh_ptr.use_count() == 2);
    }
    SECTION("lock() yields empty when shared pointer empty") {
        WeakOathbreakers legolas;
        {
            auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
            legolas = aragorn;
        }
        auto sh_ptr = legolas.lock();
        REQUIRE(sh_ptr == nullptr);
    }
}
