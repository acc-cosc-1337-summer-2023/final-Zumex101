#include "point_phase.h"
#include "roll.h" // Include the Roll header to access Roll class

// Constructor
PointPhase::PointPhase(int p) : point(p) {
}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int rolledValue = roll->roll_value();

    if (rolledValue == point) {
        return RollOutcome::point;
    } else if (rolledValue == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}
