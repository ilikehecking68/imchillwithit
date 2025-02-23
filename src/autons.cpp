#include "settings.hpp"
#include "main.h"

void autonomous() {
    chassis.setPose(0, 0, 0);
    // move 48" forwards
    chassis.moveToPoint(0, 48, 10000);

}
