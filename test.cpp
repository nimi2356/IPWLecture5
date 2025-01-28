#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"

TEST_CASE("Sum function handles different vector scenarios", "[Sum]") {
    SECTION("Empty vector returns zero") {
        std::vector<int> emptyVec;
        REQUIRE(Sum(emptyVec) == 0);
    }

    SECTION("Vector with single element") {
        std::vector<int> singleElementVec = {42};
        REQUIRE(Sum(singleElementVec) == 42);
    }

    SECTION("Vector with multiple positive numbers") {
        std::vector<int> positiveVec = {1, 2, 3, 4, 5};
        REQUIRE(Sum(positiveVec) == 15);
    }

    SECTION("Vector with mixed positive and negative numbers") {
        std::vector<int> mixedVec = {-1, 2, -3, 4, -5};
        REQUIRE(Sum(mixedVec) == -3);
    }

    SECTION("Vector with large numbers") {
        std::vector<int> largeNumVec = {1000000, 2000000, -500000};
        REQUIRE(Sum(largeNumVec) == 2500000);
    }
}

TEST_CASE("VectorPlusN function handles different vector scenarios", "[VectorPlusN]") {
    SECTION("Empty vector returns empty vector") {
        std::vector<double> emptyVec;
        REQUIRE(VectorPlusN(emptyVec, 1) == emptyVec);
    }

    SECTION("Vector with single element") {
        std::vector<double> singleElem{5.0};
        std::vector<double> expected{7.0};
        REQUIRE(VectorPlusN(singleElem, 2.0) == expected);
    }

    SECTION("Positive n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{3.0, 4.0, 5.0};
        REQUIRE(VectorPlusN(vec, 2.0) == expected);        
    }

    SECTION("Decimal n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{1.5, 2.5, 3.5};
        REQUIRE(VectorPlusN(vec, 0.5) == expected);
    }

    SECTION("Negative n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{-1.0, 0.0, 1.0};
        REQUIRE(VectorPlusN(vec, -2.0) == expected);
    }

    SECTION("Large n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        double largeN = 1000000.0;
        std::vector<double> expected{
            1.0 + largeN,
            2.0 + largeN,
            3.0 + largeN
        };
        REQUIRE(VectorPlusN(vec, largeN) == expected);
    }
    
    SECTION("Small n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        double smallN = 0.000001;
        std::vector<double> expected{
            1.0 + smallN,
            2.0 + smallN,
            3.0 + smallN
        };
        REQUIRE(VectorPlusN(vec, smallN) == expected);
    }
}

TEST_CASE("VectorTimesN function handles different vector scenarios", "[VectorTimesN]") {
    SECTION("Empty vector returns empty vector") {
        std::vector<double> emptyVec;
        REQUIRE(VectorTimesN(emptyVec, 1) == emptyVec);
    }

    SECTION("Vector with single element") {
        std::vector<double> singleElem{5.0};
        std::vector<double> expected{10.0};
        REQUIRE(VectorTimesN(singleElem, 2.0) == expected);
    }

    SECTION("Positive n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{2.0, 4.0, 6.0};
        REQUIRE(VectorTimesN(vec, 2.0) == expected);        
    }

    SECTION("Decimal n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{.5, 1, 1.5};
        REQUIRE(VectorTimesN(vec, 0.5) == expected);
    }

    SECTION("Negative n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        std::vector<double> expected{-2.0, -4.0, -6.0};
        REQUIRE(VectorTimesN(vec, -2.0) == expected);
    }

    SECTION("Large n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        double largeN = 1000000.0;
        std::vector<double> expected{
            1.0 * largeN,
            2.0 * largeN,
            3.0 * largeN
        };
        REQUIRE(VectorTimesN(vec, largeN) == expected);
    }
    
    SECTION("Small n") {
        std::vector<double> vec{1.0, 2.0, 3.0};
        double smallN = 0.000001;
        std::vector<double> expected{
            1.0 * smallN,
            2.0 * smallN,
            3.0 * smallN
        };
        REQUIRE(VectorTimesN(vec, smallN) == expected);
    }
}