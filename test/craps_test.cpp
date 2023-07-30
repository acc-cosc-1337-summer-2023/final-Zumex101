#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h" 
#include "shooter.h" 
#include "come_out_phase.h"
#include "point_phase.h"

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



TEST_CASE("Die rolls return a value from 2 to 12", "[Roll]") {
    Die die1;
    Die die2;
    Roll roll(die1, die2);

    roll.roll_die();
    int rollResult = roll.roll_value();

    // Assert that the rollResult is within the valid range [2, 12]
    REQUIRE(rollResult >= 2);
    REQUIRE(rollResult <= 12);
}

TEST_CASE("Rolling the dice 10 times gets values from 2 to 12", "[Roll]") {
    Die die1;
    Die die2;
    Roll roll(die1, die2);

    // Roll the dice 10 times and assert each roll result is within the range 2 to 12
    for (int i = 0; i < 10; ++i) {
        roll.roll_die();
        int rollResult = roll.roll_value();

        // Assert the rollResult is within the valid range [2, 12]
        REQUIRE(rollResult >= 2);
        REQUIRE(rollResult <= 12);
    }
}

TEST_CASE("Shooter returns a Roll with value between 2 and 12", "[Shooter]") {
    // Create two dice
    Die die1;
    Die die2;

    // Create a shooter
    Shooter shooter;

    for (int i = 0; i < 10; ++i) {
        // Throw the dice and get the Roll result
        Roll* roll = shooter.throw_die(die1, die2);

        // Get the roll value
        int rollValue = roll->roll_value();

        // Assert that the rollValue is between 2 and 12
        REQUIRE(rollValue >= 2);
        REQUIRE(rollValue <= 12);
    }
}

TEST_CASE("Test ComeOutPhase get outcomes", "[come_out_phase]") {
    // Create Die objects with 6 sides each
    Die die1;
    Die die2;

    // Create a ComeOutPhase object
    ComeOutPhase comeOutPhase;

    // Create Roll objects with different rolled values using the Die objects
    Roll roll1(die1, die2); // Total value: 7 (natural)
    Roll roll2(die1, die2); // Total value: 11 (natural)
    Roll roll3(die1, die2); // Total value: 2 (craps)
    Roll roll4(die1, die2); // Total value: 3 (point)

    // Get the outcomes using the ComeOutPhase object
    RollOutcome outcome1 = comeOutPhase.get_outcome(&roll1);
    RollOutcome outcome2 = comeOutPhase.get_outcome(&roll2);
    RollOutcome outcome3 = comeOutPhase.get_outcome(&roll3);
    RollOutcome outcome4 = comeOutPhase.get_outcome(&roll4);

    // Check if the outcomes match the expected values
    REQUIRE(outcome1 == RollOutcome::natural);
    REQUIRE(outcome2 == RollOutcome::natural);
    REQUIRE(outcome3 == RollOutcome::craps);
    REQUIRE(outcome4 == RollOutcome::point);
}

TEST_CASE("Test PointPhase get outcomes", "[point_phase]") {
    // Create Die objects with 6 sides each
    Die die1;
    Die die2;

    // Create a PointPhase object with the point value set to 8
    PointPhase pointPhase(8);

    // Create Roll objects with different rolled values using the Die objects
    Roll roll1(die1, die2); // Total value: 8 (point)
    Roll roll2(die1, die2); // Total value: 7 (seven_out)
    Roll roll3(die1, die2); // Total value: 4 (nopoint)

    // Get the outcomes using the PointPhase object
    RollOutcome outcome1 = pointPhase.get_outcome(&roll1);
    RollOutcome outcome2 = pointPhase.get_outcome(&roll2);
    RollOutcome outcome3 = pointPhase.get_outcome(&roll3);

    // Check if the outcomes match the expected values
    REQUIRE(outcome1 == RollOutcome::point);
    REQUIRE(outcome2 == RollOutcome::seven_out);
    REQUIRE(outcome3 == RollOutcome::nopoint);
}
