#include "main.h"

void spinIntake() {
    static bool L2Pressed;
    static bool L1Pressed;

    while(true) {   

        
        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
            
            L2Pressed = !L2Pressed;
            L1Pressed = false;
        }
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
            
            L1Pressed = !L1Pressed;
            L2Pressed = false;
        }

        

        //moves intake in the direction that is toggled by the driver -- if no buttons are toggled intake is automatically stopped
        if(L2Pressed) {

            intake.move(-117); // Changed to 100 from 85 - Kaun's request
            
            setDiagText(9, "fwd");
        } else if(L1Pressed){

            intake.move(117); // Changed to -100 from -85 - Kaun's request
            
            setDiagText(9, "rev");
        } else {

            intake.brake();
            setDiagText(9, "stop");
        }
        
        pros::delay(10);
    }

}