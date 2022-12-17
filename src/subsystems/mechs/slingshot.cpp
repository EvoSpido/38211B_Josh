#include "main.h"
#include "pros/motors.h"


void slingshotControl() {


    while (true) {

        //toggle functions
        if(controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            
            slingshot1.move(127);
            slingshot2.move(127);
            pros::delay(500); //delay time between firing and priming
            slingshot1.move(-127);
            slingshot2.move(-127);
            pros::delay(3500); //delay time for how long it should prime
            slingshot1.brake();
            slingshot2.brake();
        }
        
        pros::delay(10);
    }

}