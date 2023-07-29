#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
   

TEST_CASE("Die roll returns a value from 1 to 6", "[Die]") {
    Die die;
    die.roll();
    int rollResult = die.rolled_value();

    // Assert that the rollResult is within the valid range [1, 6]
    REQUIRE(rollResult >= 1);
    REQUIRE(rollResult <= 6);
}

TEST_CASE("Rolling a die 10 times gets values from 1 to 6", "[Die]") {
    Die die;

    // Roll the die 10 times and assert each roll result is within the range 1 to 6
    for (int i = 0; i < 10; ++i) {
        die.roll();
        int rollResult = die.rolled_value();

        // Assert the rollResult is within the valid range [1, 6]
        REQUIRE(rollResult >= 1);
        REQUIRE(rollResult <= 6);
    }
}