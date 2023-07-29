#ifndef DIE_H
#define DIE_H

class Die {
public:
    // Rolls the die and assigns a random value to roll_value
    void roll();

    // Returns the value obtained from the last roll
    int rolled_value() const;

private:
    int roll_value;
    const int sides = 6;
};

#endif // DIE_H
