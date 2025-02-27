#include "settings.hpp"
#include "main.h"

void skills_v1() {
    arm_motor.move(127);
    pros::delay(300);
    arm_motor.move(-100);
    mogo.set_value(false);
    chassis.setPose(0, 0, -40);
    chassis.moveToPoint(9, -10.5, 1000, {.forwards = false, .maxSpeed = 38, .minSpeed = 35});
    chassis.waitUntilDone();
    //mogo
    arm_motor.move(0);
    pros::delay(20);
    mogo.set_value(true);
    pros::delay(70);
    intake_rollers_and_hooks.move(127);
    chassis.turnToHeading(-175, 1500, {.minSpeed = 85}); //prev 91
    chassis.waitUntilDone();
    chassis.moveToPoint(10, -30, 2500, {.minSpeed = 85, .earlyExitRange = 5});// prev 91
    chassis.waitUntilDone();
    //from here
    chassis.moveToPose(55, -62, 90, 2000, {.lead = 0.4, .maxSpeed = 68, .minSpeed = 66});
    chassis.waitUntilDone();
    chassis.moveToPoint(46, -62, 10000, {.forwards = false, .maxSpeed = 67, .minSpeed = 65});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000, {.maxSpeed = 35});
    chassis.waitUntilDone();
    chassis.moveToPoint(46, 5, 10000, {.maxSpeed = 40});
    chassis.waitUntilDone();
    pros::delay(30);
    chassis.moveToPose(32, -10, 90, 10000, {.forwards = false, .lead = 0.4, .maxSpeed = 78, .minSpeed = 77});
    chassis.waitUntilDone();
    chassis.moveToPoint(52, -10, 2000, {.maxSpeed = 45});
    chassis.waitUntilDone();
    pros::delay(90);
    chassis.turnToHeading(-170, 1000, {.maxSpeed = 65});
    chassis.waitUntilDone();
    chassis.moveToPoint(55, 2, 1000, {.forwards = false, .maxSpeed = 35});
    chassis.waitUntilDone();//dropoff
    mogo.set_value(false);
    chassis.moveToPose(-3, -8, -90, 10000, {.lead = 0.1, .minSpeed = 105});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(0);
    chassis.turnToHeading(90, 1000, {.maxSpeed = 80});
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -9, 5000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntilDone();
    mogo.set_value(true);
    intake_rollers_and_hooks.move(127);
    chassis.turnToHeading(-180, 1000, {.maxSpeed = 80, .minSpeed = 79});
    chassis.waitUntilDone();
    chassis.moveToPose(-23, -32, -135, 3000, {.lead = 0.4, .maxSpeed = 65, .minSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPose(-59, -54, -90, 3000, {.lead = 0.35, .maxSpeed = 62, .minSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPose(-47, -54, 0, 2000, {.forwards = false, .lead = 0.5, .maxSpeed = 65, .minSpeed = 62});
    chassis.waitUntilDone();
    chassis.moveToPoint(-47, 10, 4000, {.maxSpeed = 40});
    chassis.waitUntilDone();
    chassis.moveToPose(-45, -3, -90, 3000, {.forwards = false, .lead = 0.5, .maxSpeed = 75, .minSpeed = 70});
    chassis.waitUntilDone();
    chassis.moveToPoint(-56, -3, 3000, {.minSpeed = 30});
    chassis.waitUntilDone();
    chassis.turnToHeading(165, 3000, {.maxSpeed = 55, .minSpeed = 50});
    chassis.waitUntilDone();

    //chassis.moveToPoint(-55, -2, 3000, {.forwards = false, .minSpeed = 60});
    //chassis.waitUntilDone();
    /*intake_rollers_and_hooks.move(30);
    chassis.moveToPose(10, -80, -135, 10000, {.minSpeed = 110});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(0);*/

    

    //chassis.moveToPoint(-20, -10, 2000, {.forwards = false, .maxSpeed = 20});
    //chassis.waitUntilDone();



    /*Skills With 3 on WS
    chassis.turnToHeading(120, 1000, {.minSpeed = 91});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(-127);
    chassis.moveToPoint(36, -50, 800000, {.minSpeed = 80});
    chassis.waitUntilDone();
    chassis.moveToPoint(32, -50, 1000, {.maxSpeed = 30});
    chassis.waitUntilDone();
    chassis.turnToHeading(10, 1000, {.maxSpeed = 45});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(0);
    chassis.moveToPose(2, -72.875, 93, 10000, {.forwards = false, .lead = 0.675, .maxSpeed = 65, .minSpeed = 62});
    chassis.waitUntilDone();
    chassis.turnToHeading(165, 1000, {.maxSpeed = 70, .minSpeed = 68, .earlyExitRange = 3});
    chassis.waitUntilDone();
    chassis.moveToPose(35, -110, 90, 10000, {.lead = 0.2, .maxSpeed = 52, .minSpeed = 50});
    intake_rollers_and_hooks.move(127);
    chassis.waitUntilDone();
    chassis.turnToHeading(49, 1000, {.maxSpeed = 105, .minSpeed = 100});
    chassis.waitUntilDone();
    //wallstake loading
    chassis.moveToPoint(45, -67, 10000, {.maxSpeed = 80, .minSpeed = 78});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPose(60, -65, 90, 2000, {.maxSpeed = 25, .minSpeed = 20});
    chassis.waitUntilDone();

    //wallstake 2 rings w/ skidstake score
    //grab 3rd ring, wallstake that w/ skidstake score
    //chassis.turnToHeading(49, 1000, {.maxSpeed = 105, .minSpeed = 100});
    //chassis.waitUntilDone();*/
}

void autonomous() {
    skills_v1();
}
