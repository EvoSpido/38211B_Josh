#include "main.h"
#include "pros/misc.h"

void endgameControl() {

    while (true) {

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {

            endgame1.set_value('4095');
            endgame2.set_value('4095');
        }

        pros::delay(10);
    }
}