#include "settings.hpp"
#include "main.h"

void skills_v1() {
    arm_motor.move(127);
    pros::delay(300);
    arm_motor.move(-100);
    mogo.set_value(false);
    chassis.setPose(0, 0, -35.04);
    chassis.moveToPoint(8, -10, 10000, {.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
    arm_motor.move(0);
    pros::delay(20);
    mogo.set_value(true);
    pros::delay(70);
    chassis.turnToHeading(-170, 1500, {.minSpeed = 91});
    chassis.waitUntilDone();
    chassis.moveToPoint(15, -28, 2500, {.minSpeed = 91});
    chassis.waitUntilDone();
    chassis.turnToHeading(120, 1000, {.minSpeed = 91});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(127);
    chassis.moveToPoint(35.5, -80, 800000000, {.minSpeed = 91});
    chassis.waitUntilDone();
    //wallstake in loading
    chassis.moveToPoint(35,-71, 2000, {.forwards = false, .minSpeed = 96});
    chassis.waitUntilDone();
    chassis.turnToHeading(100, 750, {.minSpeed = 80});
    chassis.waitUntilDone();
    chassis.moveToPoint(45, -64, 2500, {.maxSpeed = 30});
    chassis.waitUntilDone();
    //wallstake
    chassis.moveToPoint(34, -75, 2000, {.forwards = false, .maxSpeed = 90, .minSpeed = 80});
    chassis.waitUntilDone();
    chassis.moveToPoint(50, 0, 10000, {.maxSpeed = 60});
    chassis.waitUntilDone();
}

void autonomous() {
    skills_v1();
}
