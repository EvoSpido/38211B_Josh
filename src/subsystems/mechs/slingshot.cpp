#include "main.h"
#include "pros/motors.h"

bool rejectDisks = false;

void slingshotControl() {


    while (true) {

        //toggle functions
        if(controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
            
            rejectDisks = true;
            intake.move(127);
            slingshot1.move(127);
            slingshot2.move(127);
            pros::delay(300); //delay time between firing and priming
            slingshot1.move(-127);
            slingshot2.move(-127);
            pros::delay(2500); //delay time for how long it should prime
            slingshot1.brake();
            slingshot2.brake();
            rejectDisks = false;
        }
        
        pros::delay(10);
    }

}