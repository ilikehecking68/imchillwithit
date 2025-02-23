#pragma once

#include "lemlib/api.hpp"
#include "settings.hpp"

namespace arm {
    extern float target;
    extern float error;
    extern lemlib::PID arm_pid;
    extern pros::Task arm_pid_task;
    extern void arm_pid_set_target(float new_target);
    extern float arm_pid_get_target();
    extern void wait_until_reached_target();
    extern bool reached_target();
}