#include "roll.h"

// Constructor
Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2), rolled(false), value(0) {

}

// Rolls the dice and saves the rolled values
void Roll::roll_die() {
    die1.roll();
    die2.roll();
    value = die1.rolled_value() + die2.rolled_value();
    rolled = true;
}

// Returns the sum of the rolled values
int Roll::roll_value() const {
    return value;
}
