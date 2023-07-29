#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h" 
#include <iostream>

class Shooter {
public:
    // Constructor
    Shooter();

    // Destructor
    ~Shooter();

    // Simulate shooting dice (pair of die)
    Roll* throw_die(Die& die1, Die& die2);

    // Overload << operator to output vector of Roll*
    friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);

private:
    std::vector<Roll*> rolls;
};

#endif // SHOOTER_H
