#include "main.h"

void slingshotControl() {

    static bool Xpressed = false;
    
    while (true) {

        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
            
            Xpressed = !Xpressed;
            
        }

        if(controller.get_digital(E_CONTROLLER_DIGITAL_B)) {
            
            Xpressed = false;
            slingshot1.move(127);
            slingshot2.move(127);
            pros::delay(10);
            slingshot1.brake();
            slingshot2.brake();
        }

        if(Xpressed) {

            slingshot1.move(-127);
            slingshot2.move(-127);
        } else {

            slingshot1.brake();
            slingshot2.brake();

        }
        pros::delay(10);
    }



}