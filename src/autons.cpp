#include "settings.hpp"
#include "main.h"
#include "colorsort.hpp"
#include "arm_pid.hpp"

void skills_v1() {
    ARM_SET_AND_WAIT(ARM_POSITION_ALLIANCE_STAKE_SKILLS);
    pros::delay(1000);
    arm::arm_pid_set_target(ARM_POSITION_LOWEST);
    pros::delay(500);
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
    chassis.turnToHeading(-160, 1500, {.minSpeed = 85}); //prev 91
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
    chassis.moveToPoint(-25, -9, 2500, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntilDone();
    mogo.set_value(true);
    intake_rollers_and_hooks.move(127);
    chassis.turnToHeading(-180, 1000, {.maxSpeed = 80, .minSpeed = 79});
    chassis.waitUntilDone();
    chassis.moveToPose(-23, -32, -135, 3000, {.lead = 0.4, .maxSpeed = 65, .minSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPose(-64, -56, -85, 3000, {.lead = 0.5, .maxSpeed = 62, .minSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPose(-47, -55, 0, 2000, {.forwards = false, .lead = 0.5, .maxSpeed = 55, .minSpeed = 52});
    chassis.waitUntilDone();
    chassis.moveToPoint(-45, 10, 4000, {.maxSpeed = 40});
    chassis.waitUntilDone();
    chassis.moveToPose(-40, -2, -90, 3000, {.forwards = false, .lead = 0.5, .maxSpeed = 75, .minSpeed = 70});
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -5.5, 3000, {.maxSpeed = 32, .minSpeed = 30});
    chassis.waitUntilDone();
    chassis.turnToHeading(180, 1000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPoint(-63, 10, 1000, {.forwards = false, .minSpeed = 80});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake_rollers_and_hooks.move(50);
    chassis.moveToPose(22, -98, -135, 10000, {.lead = 0.2, .minSpeed = 110});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(11);
    chassis.turnToHeading(80, 1000, {.minSpeed = 95});
    chassis.waitUntilDone();
    chassis.moveToPose(-10, -101, 82, 4000, {.forwards = false, .lead = 0.3, .maxSpeed = 30});
    chassis.waitUntilDone();
    mogo.set_value(true);
    pros::delay(200);
    intake_rollers_and_hooks.move(127);
    pros::delay(100);
    chassis.moveToPose(-34, -74, -90, 4000, {.lead = 0.2, .maxSpeed = 72, .minSpeed = 70});
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -74, 2000, {.maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.moveToPoint(-55, -74, 1800, {.minSpeed = 80});
    chassis.waitUntilDone();
    chassis.moveToPoint(-53, -112, 1500, {.minSpeed = 60});
    chassis.waitUntilDone();
    chassis.turnToHeading(-90, 127);
    chassis.waitUntilDone();
    chassis.moveToPoint(-53, -112, 1000, {.minSpeed = 105});
    dL.set_value(true);
    pros::delay(200);
    chassis.turnToHeading(-190, 400);
    chassis.waitUntilDone();
    chassis.turnToHeading(40, 400);
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake_rollers_and_hooks.move(0);
    chassis.moveToPoint(-70, -130, 1000, {.forwards = false, .minSpeed = 127});
    chassis.waitUntilDone();
    dL.set_value(false);
    chassis.moveToPose(-30, -100, 110, 2000, {.lead = 0.35, .minSpeed = 120, .earlyExitRange = 2.5});
    chassis.waitUntilDone();
    chassis.moveToPoint(40, -120, 2500, {.minSpeed = 100});
    chassis.waitUntilDone();
    

    /*chassis.turnToHeading(165, 1000, {.maxSpeed = 52, .minSpeed = 50});
    chassis.moveToPose(32, -105, 90, 8000, {.lead = 0.4, .minSpeed = 100});
    chassis.waitUntilDone();
    /*racism = racist_to_blue;
    intake_helper_task.resume();
    chassis.moveToPoint(50, -105, 2000, {.maxSpeed = 54, .minSpeed = 52});
    chassis.waitUntilDone();
    chassis.moveToPose(30, -105, 0, 2000, {.lead = 0.3, .maxSpeed = 54, .minSpeed = 52});
    chassis.waitUntilDone();
    chassis.turnToHeading(90,600);
    chassis.moveToPoint(30,-120, 1000, {.minSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.turnToHeading(-90, 1000, {.minSpeed = 127});
    chassis.waitUntilDone();
    dR.set_value(true);
   chassis.moveToPoint(46, 75, 1900, {.maxSpeed = 60});
    chassis.waitUntilDone();
    chassis.turnToHeading(180, 1000, {.maxSpeed = 52, .minSpeed = 50});
    chassis.waitUntilDone();
    chassis.moveToPoint(36, -120, 2500, {.maxSpeed = 55});
    chassis.turnToHeading(-45, 800, {.maxSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPoint(55, -130, 2000, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntilDone();*/



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

void goal_rush_finals_blue(){
    intake_helper_task.resume();
    chassis.setPose(0.639, 7.095, 11.346);
    chassis.moveToPose(9.7406, 48.079, 11.02, 4000, {.lead = 0.07, .minSpeed = 127});
    chassis.waitUntilDone();
    dR.set_value(true); //down
    chassis.moveToPose(13.899, 24.25, -90, 3000, {.forwards = false, .lead = 0.7, .maxSpeed = 102, .minSpeed = 100, .earlyExitRange = 1.25});
    chassis.waitUntilDone();
    dR.set_value(false);
    chassis.moveToPose(35.936, 20.967, 11.9, 2000, {.forwards = false, .lead = 0.5, .minSpeed = 120});
    chassis.waitUntilDone();
}

void solo_awp(){
    racism = racist_to_red;
    intake_helper_task.resume();
    mogo.set_value(false);
    chassis.setPose(0, 0, -57);
    ARM_SET_AND_WAIT(ARM_POSITION_ALLIANCE_STAKE_SOLO_AWP_BLUE);
    pros::delay(870);
    chassis.moveToPoint(5, -5, 700, {.forwards = false, .maxSpeed = 90, .minSpeed = 88});
    chassis.waitUntilDone();
    arm::arm_pid_set_target(ARM_POSITION_LOWEST);
    pros::delay(250);
    chassis.moveToPose(12, -38, -15, 3000, {.forwards = false, .lead = 0.3, .maxSpeed = 76, .minSpeed = 74});
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(90, 1000, {.maxSpeed = 110, .minSpeed = 108});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(127);
    chassis.moveToPoint(25, -38, 2000, {.maxSpeed = 127, .minSpeed = 127});
    chassis.waitUntilDone();
    chassis.moveToPose(5, -7, 180, 2000, {.forwards = false, .lead = 0.25, .maxSpeed = 50});
    chassis.waitUntilDone();
    mogo.set_value(false);
    chassis.turnToHeading(-110, 1000, {.minSpeed = 110, .earlyExitRange = 15});
    chassis.waitUntilDone();
    intake_rollers_and_hooks.move(127);
    chassis.moveToPoint(-1, -7.0, 200, {.minSpeed = 115, .earlyExitRange = 2});
    chassis.waitUntilDone();
    chassis.moveToPose(-50, -7.0, 10, 1800, {.lead = 0.05, .maxSpeed = 40, .earlyExitRange = 2.5});
    chassis.waitUntilDone();
    pros::delay(320);
    intake_rollers_and_hooks.move(5);
    chassis.moveToPoint(-40, -33, 1300, {.forwards = false, .maxSpeed = 60, .minSpeed = 58});
    chassis.waitUntilDone();
    pros::delay(8);
    mogo.set_value(true);
    pros::delay(40);
    intake_rollers_and_hooks.move(127);
    chassis.turnToHeading(-90, 500, {.maxSpeed = 62, .minSpeed = 60});
    chassis.waitUntilDone();
    chassis.moveToPoint(-52, -30, 1300, {.minSpeed = 127});
    chassis.waitUntilDone();
    chassis.moveToPoint(-30, -20, 1000, {.minSpeed = 127});
    //chassis.moveToPoint(-15, -25, 1200, {.minSpeed = 120});
    //chassis.waitUntilDone();

    /*chassis.moveToPoint(-60, -40, 1500, {.minSpeed = 90, .earlyExitRange = 2});
    intake_rollers_and_hooks.move(127);
    chassis.waitUntilDone();
    chassis.moveToPoint(-65, -60, 1500, {.maxSpeed = 82, .minSpeed = 80, .earlyExitRange = 1.5});
    chassis.waitUntilDone();*/
    
    /*
    chassis.moveToPoint(11, -46, 2000, {.maxSpeed = 62, .minSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(150);
    chassis.moveToPose(-2.47, -44, 303, 3000, {.forwards = false, .lead = 0.4, .minSpeed = 70});
    chassis.waitUntilDone();
    chassis.moveToPose(8.3, -56, 365, 3000, {.forwards = false, .lead = 0.3, .maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.moveToPose(-7.8, -27.2, 292, 2500, {.lead = 0.2, .maxSpeed = 100});
    chassis.waitUntilDone();
    dR.set_value(true);
    chassis.turnToHeading(261, 800, {.maxSpeed = 102, .minSpeed = 100});
    pros::delay(20);
    dR.set_value(false);*/
}

ASSET(path_jerry_io)

void test_path(){
    chassis.setPose(0, 0, 0);
    chassis.follow(path_jerry_io, 15, 9999999, false);
}

void autonomous() {
    skills_v1();
    //goal_rush_finals_blue();
    //solo_awp();
}
