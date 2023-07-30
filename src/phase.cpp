#include "phase.h" 
#include "come_out_phase.h" 
#include "point_phase.h"
#include "roll.h" 

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int rollValue = roll->roll_value();
    if (rollValue == 7 || rollValue == 11) {
        return RollOutcome::natural;
    } else if (rollValue == 2 || rollValue == 3 || rollValue == 12) {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}

// Implementation of PointPhase class (derived from Phase)

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int rollValue = roll->roll_value();
    if (rollValue == point) {
        return RollOutcome::point;
    } else if (rollValue == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}
