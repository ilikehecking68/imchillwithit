#include "arm_pid.hpp"

lemlib::PID arm::arm_pid(ARM_PID_CONSTANTS);
float arm::target = 0;
float arm::error = 0;

void arm::arm_pid_set_target(float new_target){
    pros::Mutex mut;
    mut.take();
    arm::target = new_target;
    mut.give();
}

float arm::arm_pid_get_target(){
    pros::Mutex mut;
    mut.take();
    float retreived_target = arm::target;
    mut.give();
    return retreived_target;
}

bool arm::reached_target(){
    pros::Mutex mut;
    mut.take();
    bool reached_target = arm::arm_pid.update(target - ARM_PID_GET_DEGREES);
    mut.give();
    return reached_target;
}

void arm::wait_until_reached_target(){
    pros::Mutex mut;
    bool wait = true;
    while (wait){
        mut.take();
        wait = std::fabs(error) > (ARM_PID_ERROR_DEADZONE);
        mut.give();
    }
}

pros::Task arm::arm_pid_task {[]{
    pros::Mutex mut;
    while (true){
        mut.take();
        error = target - (ARM_PID_GET_DEGREES);
        arm_motor.move(arm::arm_pid.update(error));
        mut.give();
        pros::delay(10);
    }
}};