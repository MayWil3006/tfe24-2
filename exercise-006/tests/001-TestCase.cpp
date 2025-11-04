#include <catch2/catch_test_macros.hpp>
#include "../point.hpp"
#include <type_traits>
#include <fmt/format.h>
#include <catch2/catch_approx.hpp>



TEST_CASE("Point<T>: Konstruktion & move (int)") {
  Point<int> p{2, 3};
  REQUIRE(p.x == 2);
  REQUIRE(p.y == 3);

  p.move(1, -4);
  REQUIRE(p.x == 3);
  REQUIRE(p.y == -1);
}

TEST_CASE("Point<T>: Konstruktion & move (double)") {
  Point<double> p{2.5, -3.75};
  p.move(0.5, 0.25);
  REQUIRE(p.x == Catch::Approx(3.0));
  REQUIRE(p.y == Catch::Approx(-3.5));
}

TEST_CASE("Point<T>: distance_to – Typ & Wert") {
  Point<int> a{0,0}, b{3,4};
  typedef decltype(a.distance_to(b)) dist_t;
  STATIC_REQUIRE(!std::is_same<dist_t, int>::value);
  REQUIRE(a.distance_to(b) == Catch::Approx(5.0).margin(1e-12));
  REQUIRE(b.distance_to(a) == Catch::Approx(5.0).margin(1e-12));
  REQUIRE(a.distance_to(a) == Catch::Approx(0.0).margin(1e-12));
}

TEST_CASE("Point<T>: fmt-Formatter") {
  Point<int> pi{1,2};
  REQUIRE(fmt::format("{}", pi) == "(1, 2)");
}

// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success

// Expected compact output (all assertions):
//
// prompt> 010-TestCase --reporter compact --success
// 010-TestCase.cpp:14: failed: Factorial(0) == 1 for: 0 == 1
// 010-TestCase.cpp:18: passed: Factorial(1) == 1 for: 1 == 1
// 010-TestCase.cpp:19: passed: Factorial(2) == 2 for: 2 == 2
// 010-TestCase.cpp:20: passed: Factorial(3) == 6 for: 6 == 6
// 010-TestCase.cpp:21: passed: Factorial(10) == 3628800 for: 3628800 (0x375f00) == 3628800 (0x375f00)
// Failed 1 test case, failed 1 assertion.