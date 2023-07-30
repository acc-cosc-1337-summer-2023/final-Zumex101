#ifndef PHASE_H
#define PHASE_H

enum class RollOutcome { 
    natural, // Result of rolling a 7 or 11 on the first roll
    craps,   // Result of rolling a 2, 3, or 12 on the first roll
    point,   // Result of establishing a point (4, 5, 6, 8, 9, or 10) on the first roll
    seven_out, // Result of rolling a 7 after establishing a point
    nopoint   // Result of rolling neither a point nor a 7 after the first roll
};

class Roll; // Forward declaration of Roll class

class Phase {
public:

    virtual ~Phase() {}

    virtual RollOutcome get_outcome(Roll* roll) = 0;
};

#endif 
