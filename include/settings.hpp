#pragma once

#include "lemlib/api.hpp"
#include "short_type_names.h"
#include "main.h"

//Drive Train Settings
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);
#define USER_CONTROL_DRIVE_JOYSTICK controller.get_analog(ANALOG_LEFT_Y)
#define USER_CONTROL_TURN_JOYSTICK controller.get_analog(ANALOG_RIGHT_X)
#define USER_CONTROL_JOYSTICK_DEADZONE 12
#define USER_CONTROL_DRIVE_SPEED_PERCENT 100
#define USER_CONTROL_TURN_SPEED_PERCENT 80
#define USER_CONTROL_DRIVE_CURVE(original) original/*0.01 * std::fabs(original)*original*/
inline pros::MotorGroup right_drive(/*ports*/{19, 18, -20}, pros::MotorGears::blue, pros::MotorEncoderUnits::degrees);
inline pros::MotorGroup left_drive(/*ports*/{-13, -14, 12}, pros::MotorGears::blue, pros::MotorEncoderUnits::degrees);

//Arm + Arm-PID settings
inline pros::Motor arm_motor(10 /*port*/, pros::MotorGears::green, pros::MotorEncoderUnits::degrees);
inline pros::Rotation arm_rs(9);
#define ARM_PID_GET_DEGREES (double)(arm_rs.get_position() / 100)
#define ARM_PID_CONSTANTS /*kp*/ 4, /*ki*/ 0, /*kd*/ 17
#define ARM_PID_ERROR_DEADZONE 5
#define ARM_PID_INTEGRAL_LIMIT 999
#define ARM_PID_CYCLES_REQUIRED_IN_ERROR_FOR_EXIT 1
#define ARM_POSITION_TOGGLE_BUTTON controller.get_digital_new_press(DIGITAL_DOWN)
inline f64 arm_positions[] = {-110, 28, 350};
#define ARM_POSITION_LOWEST (arm_positions[0])
#define ARM_POSITION_LOADING (arm_positions[1])
#define ARM_POSITION_SCORING (arm_positions[2])
#define ARM_POSITION_ALLIANCE_STAKE_SKILLS 435
#define ARM_POSITION_ALLIANCE_STAKE_SOLO_AWP_BLUE 420
#define ARM_I_FOR_SCORING 2
#define ARM_SCORING_HOOKS_BACKSPEED -10
#define ARM_BUTTON_TO_TIP_MOGO controller.get_digital_new_press(DIGITAL_RIGHT)

//Intake + Hooks Settings
inline pros::MotorGroup intake_rollers_and_hooks({2, 1});
inline pros::Motor intake_rollers(2);
inline pros::Motor hooks(1);
#define USER_CONTROL_HOOK_AND_INTAKE_ROLLERS_IN_BUTTON controller.get_digital(DIGITAL_R1)
#define USER_CONTROL_HOOK_AND_INTAKE_ROLLERS_OUT_BUTTON controller.get_digital(DIGITAL_R2)

//Doinker + Mobile-Goal-Clamp Settings
inline pros::ADIDigitalOut dR(3, false);
inline pros::ADIDigitalOut dL(2, false);
#define USER_CONTROL_DOINKER_RIGHT_BUTTON controller.get_digital_new_press(DIGITAL_UP)
#define USER_CONTROL_DOINKER_LEFT_BUTTON controller.get_digital_new_press(DIGITAL_X)
inline pros::ADIDigitalOut mogo(1, false);
#define USER_CONTROL_MOGO_BUTTON controller.get_digital_new_press(DIGITAL_A)

//Color Sort + Optical Sensor Settings
inline pros::Optical optical(15);
#define COLOR_SORT_THRESHOLD 50

//Chassis + Lemlib Settings
inline pros::IMU imu(3);
inline pros::Rotation horizontal_encoder(-17);
inline pros::Rotation vertical_encoder(8);
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.0984);
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, -1.775);

inline lemlib::Drivetrain drivetrain(
    &left_drive, // left motor group
    &right_drive, // right motor group
    12.125, // 12.125 inch track width
    lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
    600, // drivetrain rpm is 360
    7.5 // horizontal drift is 2 (for now)
);

inline lemlib::OdomSensors sensors(
    &vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    &horizontal_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &imu // inertial sensor
);

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(3.875, // proportional gain (kP)
                                                        0.3, // integral gain (kI)
                                                        3, // derivative gain (kD)
                                                        3, // anti windup
                                                        1, // small error range, in inches
                                                        100, // small error range timeout, in milliseconds
                                                        3, // large error range, in inches
                                                        500, // large error range timeout, in milliseconds
                                                        20 // maximum acceleration (slew)
                                                                                                /*
                                              20, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              100, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
                                              */
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(4.875, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              32, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);


inline lemlib::Chassis chassis(drivetrain, // drivetrain settings
    lateral_controller, // lateral PID settings
    angular_controller, // angular PID settings
    sensors // odometry sensors
);

