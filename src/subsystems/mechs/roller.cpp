#include "main.h"


void rollerControl() {

    static bool R1Pressed;


    while(true) {   

        
        //toggle functions
        if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
            
            R1Pressed = !R1Pressed;
        }

        if(R1Pressed) {

            roller.move(70);
            
        } else if(!R1Pressed){

            roller.brake();
        } 
    
        pros::delay(10);
    }
}