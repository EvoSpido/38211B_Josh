#include "main.h"

void spinIntake() {
    static bool rightPressed;
    static bool downPressed;

    while(true) {   

        //bypasses controller buttons if controller is not connected to the brain
        if(!controller.is_connected()) {
            rightPressed = true;
        }  

        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
            
            rightPressed = !rightPressed;
            downPressed = false;
        }
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
            
            downPressed = !downPressed;
            rightPressed = false;
        }

        

        //moves intake in the direction that is toggled by the driver -- if no buttons are toggled intake is automatically stopped
        if(rightPressed) {

            intake.move(-117); // Changed to 100 from 85 - Kaun's request
            
            setDiagText(9, "fwd");
        } else if(downPressed){

            intake.move(117); // Changed to -100 from -85 - Kaun's request
            
            setDiagText(9, "rev");
        } else {

            intake.brake();
        
            setDiagText(9, "stop");
        }
        
        pros::delay(10);
    }

}