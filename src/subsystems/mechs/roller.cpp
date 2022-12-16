#include "main.h"


void rollerControl() {

    static bool XPressed;


    while(true) {   

        
        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
            
            XPressed = !XPressed;
        }


        if(XPressed) {

            roller.move(-117);
            
        } else if(!XPressed){

            roller.brake();
        } 
    
        pros::delay(10);
    }
}