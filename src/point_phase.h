#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h" 

class PointPhase : public Phase {
public:
    // Constructor
    PointPhase(int p);

    // Implementation of the get_outcome function from the base class
    RollOutcome get_outcome(Roll* roll) override;

private:
    int point;
};

#endif // POINT_PHASE_H
