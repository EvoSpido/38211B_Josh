#include "main.h"

void slingshotControl() {

    static bool Xpressed = false;
    // one spin one way one spin other way idk what kauns talking about
    // X is supposed to spin the shaft infinitely until pressed again, and then B is supposed to spin the shaft the other way for a moment 
    
    while (true) {

        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
            
            Xpressed = !Xpressed;
            
        }

        if(controller.get_digital(E_CONTROLLER_DIGITAL_B)) {
            
            Xpressed = false;
            slingshot1.move(127);
            slingshot2.move(127);
            pros::delay(50);
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