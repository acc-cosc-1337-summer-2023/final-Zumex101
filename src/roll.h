#ifndef ROLL_H
#define ROLL_H

#include "die.h" 

class Roll {
public:
    // Constructor
    Roll(Die& die1, Die& die2);

    // Rolls the dice and saves the rolled values
    void roll_die();

    // Returns the sum of the rolled values
    int roll_value() const;

private:
    Die& die1;
    Die& die2;
    bool rolled;
    int value;
};

#endif // ROLL_H
