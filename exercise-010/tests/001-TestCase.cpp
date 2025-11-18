// 001-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>
#include "myvector.hpp"

using namespace tfe24;

TEST_CASE("Konstruktor und Grundzustand", "[MyVector][basic]") {
    MyVector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);

    SECTION("push_back erhöht size und wächst geometrisch") {
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);

        // Kapazität sollte >= size() sein und darf nicht linear wachsen
        size_t old_cap = v.capacity();
        for (int i = 0; i < 100; ++i) v.push_back(i);
        REQUIRE(v.capacity() >= old_cap); // Wachstum vorhanden
    }

    SECTION("at() wirft bei Out-of-Range std::out_of_range") {
        v.push_back(42);
        REQUIRE_THROWS_AS(v.at(10), std::out_of_range);
    }

    SECTION("resize größer erzeugt Defaultwerte") {
        v.resize(5);
        REQUIRE(v.size() == 5);
        for (size_t i = 0; i < v.size(); ++i)
            REQUIRE(v[i] == int{}); // erwartet 0 bei int
    }

    SECTION("resize kleiner reduziert size") {
        v.resize(10);
        v.resize(3);
        REQUIRE(v.size() == 3);
        REQUIRE_THROWS_AS(v.at(5), std::out_of_range);
    }

    SECTION("clear setzt size auf 0, behält capacity") {
        v.push_back(10);
        v.push_back(20);
        auto old_cap = v.capacity();
        v.clear();
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == old_cap);
    }
}

TEST_CASE("Copy-Konstruktor und Copy-Zuweisung (Deep Copy)", "[MyVector][copy]") {
    MyVector<int> a;
    for (int i = 0; i < 5; ++i) a.push_back(i * 10);

    // Copy-Konstruktor
    MyVector<int> b = a;
    REQUIRE(b.size() == a.size());
    REQUIRE(b.capacity() == a.capacity());
    for (size_t i = 0; i < a.size(); ++i)
        REQUIRE(b[i] == a[i]);

    // Copy-Zuweisung
    MyVector<int> c;
    c = a;
    REQUIRE(c.size() == a.size());
    for (size_t i = 0; i < a.size(); ++i)
        REQUIRE(c[i] == a[i]);

    // Unabhängigkeit prüfen (Deep Copy)
    a[0] = 999;
    REQUIRE(b[0] != a[0]);
    REQUIRE(c[0] != a[0]);
}

TEST_CASE("Wachstumsstrategie und Amortisierung", "[MyVector][growth]") {
    MyVector<int> v;

    size_t prev_cap = 0;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
        if (v.capacity() > prev_cap) {
            // Kapazität wächst in Sprüngen (nicht bei jedem push_back)
            size_t diff = v.capacity() - prev_cap;
            REQUIRE(diff >= 1);
            prev_cap = v.capacity();
        }
    }

    REQUIRE(v.size() == 1000);
    REQUIRE(v.capacity() >= v.size());
}
