#include "die.h"
#include <cstdlib>   // For rand() and srand() functions
#include <ctime>     // For time() function (to seed the random number generator)

void Die::roll() {
    // Seed the random number generator using the current time
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    // Generate a random value in the range of 1 to 6 (inclusive)
    roll_value = rand() % sides + 1;
}

int Die::rolled_value() const {
    return roll_value;
}
