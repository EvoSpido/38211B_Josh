#include "main.h"
#include "pros/rtos.hpp"

bool timerUpdating = false;

void matchTimer(int numOfSec) {
    /* CANNOT USE A FOR LOOP, STARVES RESOURCES
    for (int time = numOfSec; time >= 0; time--) {

        int minutes = time / 60;
        int seconds = time % 60;

        if (seconds == 9) {

            timerUpdating = true;
            controller.clear_line(1);
            pros::delay(50);
            controller.print(1, 0, "0%i:0%i", minutes, seconds);
            timerUpdating = false;
        } else if (seconds < 9) {

            timerUpdating = true;
            controller.print(1, 0, "0%i:0%i", minutes, seconds);
            timerUpdating = false;
        } else {
            
            timerUpdating = true;
            controller.print(1, 0, "0%i:%i", minutes, seconds);
            timerUpdating = false;
        }
        pros::delay(10);
    }
    */
}