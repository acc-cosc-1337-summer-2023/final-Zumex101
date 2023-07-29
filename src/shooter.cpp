#include "shooter.h"

// Constructor
Shooter::Shooter() {
    // Constructor implementation (if needed)
}

// Destructor
Shooter::~Shooter() {
    // Iterate through the rolls vector and delete each Roll instance
    for (Roll* roll : rolls) {
        delete roll;
    }
}

// Simulate shooting dice (pair of die)
Roll* Shooter::throw_die(Die& die1, Die& die2) {
    // Create a dynamic instance of Roll (heap allocation)
    Roll* roll = new Roll(die1, die2);

    // Roll the dice and add roll to the vector
    roll->roll_die();
    rolls.push_back(roll);

    // Return the roll instance
    return roll;
}

// Overload << operator to output vector of Roll*
std::ostream& operator<<(std::ostream& os, const Shooter& shooter) {
    // Output each roll in the vector
    for (Roll* roll : shooter.rolls) {
        os << "Roll Value: " << roll->roll_value() << std::endl;
    }
    return os;
}
