#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    // Seed the random number generator using the current time
    srand(static_cast<unsigned int>(time(0)));

    // Create Die objects
    Die die1;
    Die die2;

    // Create Shooter instance
    Shooter shooter;

    // Create a pointer to Roll and set it equal to the return value of the shooter throw_die function
    Roll* roll = shooter.throw_die(die1, die2);

    // Create ComeOutPhase instance
    ComeOutPhase come_out_phase;

    // Create a loop that continues while come_out_phase get_outcome is RollOutcome::natural or RollOutcome::craps
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        // Display the value of the rolled value and the text "roll again"
        std::cout << "Rolled " << roll->roll_value() << " roll again" << std::endl;
        
        // Set roll equal to the return value of the shooter throw_die function
        roll = shooter.throw_die(die1, die2);
    }

    // Display rolled value with the text "start of point phase"
    std::cout << "Rolled " << roll->roll_value() << " start of point phase" << std::endl;

    // Display the text "Roll until rolled value or 7 is rolled"
    std::cout << "Roll until " << roll->roll_value() << " or a 7 is rolled" << std::endl;

    // Create an int point variable and set it to roll rolled_value
    int point = roll->roll_value();

    // Set roll equal to the return value of the shooter throw_die function
    roll = shooter.throw_die(die1, die2);

    // Create PointPhase instance
    PointPhase point_phase(point);

    // Create a loop that continues while point_phase get_outcome is not RollOutcome::point or RollOutcome::seven_out
    while (point_phase.get_outcome(roll) != RollOutcome::point && point_phase.get_outcome(roll) != RollOutcome::seven_out) {
        // Display the rolled value and the text "roll again"
        std::cout << "Rolled " << roll->roll_value() << " roll again" << std::endl;
        
        // Set roll equal to the return value of the shooter throw_die function
        roll = shooter.throw_die(die1, die2);
    }

    // Display rolled value and the text "end of point phase"
    std::cout << "Rolled " << roll->roll_value() << " end of point phase" << std::endl;

    // Use cout to display the shooter variable (ostream has been overloaded for it)
    std::cout << shooter;

    // Clean up the dynamically allocated memory
    delete roll;

    return 0;
}
