#include "main.h"
#include "pros/misc.h"

void endgameControl() {

    while (true) {

        bool endgameTriggered = false;

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {

            endgameTriggered = true;
        }

        if (endgameTriggered) {

            endgame.set_value('4095');
        }

        pros::delay(10);
    }
}