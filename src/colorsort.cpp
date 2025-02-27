#include "main.h"
#include "colorsort.hpp"
#include "settings.hpp"
bool intake_override = false;
#define racist_to_red (true)
#define racist_to_blue (false)
#define racism racist_to_red

constexpr float RED_HUE = 12;
constexpr float BLUE_HUE = 215;

constexpr float HUE_TOLERANCE = 15;

constexpr float DIST_TOLERANCE = 200;

pros::Task intake_helper_task([] {
    int cs_outtake_delay = 0;
    int cs_outtake_ticks = 0;
    bool prev_verdict = false;

    while (true) {
        pros::delay(20);


        float r_hue_min = std::fmod(RED_HUE - HUE_TOLERANCE + 360, 360.0f);
        float r_hue_max = std::fmod(RED_HUE + HUE_TOLERANCE, 360.0f);
        float b_hue_min = std::fmod(BLUE_HUE - HUE_TOLERANCE + 360, 360.0f);
        float b_hue_max = std::fmod(BLUE_HUE + HUE_TOLERANCE, 360.0f);

        bool b_ring = false;
        if (b_hue_min <= b_hue_max) {
            // if it's normal, just check the ranges
            b_ring = b_hue_min <= optical.get_hue() && optical.get_hue() <= b_hue_max;
        } else if (b_hue_min >= b_hue_max) {
            // if the range goes around 0, say hue min is 330 while hue_max is 30,
            // 0 and 360 are used as bounds.
            b_ring = optical.get_hue() <= b_hue_max || optical.get_hue() >= b_hue_min;
        }

        bool r_ring = false;
        if (r_hue_min <= r_hue_max) {
            // if it's normal, just check the ranges
            r_ring = r_hue_min <= optical.get_hue() && optical.get_hue() <= r_hue_max;
        } else if (r_hue_min >= r_hue_max) {
            // if the range goes around 0, say hue min is 330 while hue_max is 30,
            // 0 and 360 are used as bounds.
            r_ring = optical.get_hue() <= r_hue_max || optical.get_hue() >= r_hue_min;
        }


        bool outtake = racism && r_ring || !racism && b_ring;

        bool verdict = outtake && optical.get_proximity() >= DIST_TOLERANCE;
        if (verdict) {
            cs_outtake_ticks = 420 / 20;
            if (!prev_verdict) {
                cs_outtake_delay = 10 / 20;
            }
        }

        // expected that intake_override is followed appropriately
        if (cs_outtake_delay > 0) {
            --cs_outtake_delay;
        } else if (cs_outtake_ticks > 0) {
            intake_override = true;
            hooks.move(-127);
            --cs_outtake_ticks;
        } else {
            intake_override = false;
        }

        prev_verdict = verdict;
    }
});