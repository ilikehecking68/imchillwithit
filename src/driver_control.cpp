#include "main.h"
#include "settings.hpp"
#include "arm_pid.hpp"
#include "colorsort.hpp"

void intake_and_hooks(){
    if ((USER_CONTROL_HOOK_AND_INTAKE_ROLLERS_IN_BUTTON)){
        intake_rollers.move(127);
        if (!intake_override){
            hooks.move(127);
        }
    } else if ((USER_CONTROL_HOOK_AND_INTAKE_ROLLERS_OUT_BUTTON)){
        intake_rollers.move(-127);
        if (!intake_override){
            hooks.move(-127);
        }
    } else {
        intake_rollers.move(0);
        if (!intake_override){
            hooks.move(0);
        }
    }
}

bool doinker_status_r = false;
bool doinker_status_l = false;
bool mogo_status = false;
void mogo_and_doinker(){
    if ((USER_CONTROL_DOINKER_RIGHT_BUTTON)){
        doinker_status_r = !doinker_status_r;
        dR.set_value(doinker_status_r);
    }
    if ((USER_CONTROL_DOINKER_LEFT_BUTTON)){
        doinker_status_l = !doinker_status_l;
        dL.set_value(doinker_status_l);
    }
    if ((USER_CONTROL_MOGO_BUTTON)){
        mogo_status = !mogo_status;
        mogo.set_value(mogo_status);
    }
}

u64 arm_pos_i = 0;
void arm_move(){
    if ((ARM_POSITION_TOGGLE_BUTTON)){
        arm_pos_i = arm_pos_i < (sizeof(arm_positions) / sizeof(arm_positions[0]) - 1) ? arm_pos_i + 1 : 0;
        arm::arm_pid_set_target(arm_positions[arm_pos_i]);
    }
    if (arm_pos_i == (ARM_I_FOR_SCORING)){
        hooks.move(-10);
    }
    if ((ARM_BUTTON_TO_TIP_MOGO)){
        arm::arm_pid_set_target(ARM_POSITION_ALLIANCE_STAKE_SKILLS);
    }
}

f80 drive_curve_max = (USER_CONTROL_DRIVE_CURVE((127)));
#define USER_CONTROL_DRIVE_CURVE_SCALED(original)(127 / drive_curve_max * (USER_CONTROL_DRIVE_CURVE((original))))
void opcontrol(){
    while (true){
        int straight_joystick_value = (USER_CONTROL_DRIVE_CURVE_SCALED(USER_CONTROL_DRIVE_JOYSTICK)) * (USER_CONTROL_DRIVE_SPEED_PERCENT) * 0.01;
        if (std::abs(straight_joystick_value) < USER_CONTROL_JOYSTICK_DEADZONE){
            straight_joystick_value = 0;
        }
        int turn_joystick_value = (USER_CONTROL_DRIVE_CURVE_SCALED(USER_CONTROL_TURN_JOYSTICK)) * (USER_CONTROL_TURN_SPEED_PERCENT) * 0.01;
        if (std::abs(turn_joystick_value) < USER_CONTROL_JOYSTICK_DEADZONE){
            turn_joystick_value = 0;
        }
        left_drive.move(straight_joystick_value + turn_joystick_value);
        right_drive.move(straight_joystick_value - turn_joystick_value);
        pros::lcd::print(6, "arm_rs read position: %lf", (f64)(ARM_PID_GET_DEGREES));
        pros::lcd::print(7, arm::reached_target() ? "arm pid has reached target position" : "arm pid is moving to target position");
        mogo_and_doinker();
        intake_and_hooks();
        arm_move();
        pros::delay(10);
    }
}
