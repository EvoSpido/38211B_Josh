#include "main.h"
#include "okapi/api/chassis/controller/chassisScales.hpp"
#include "okapi/api/units/QForce.hpp"
#include "okapi/api/units/QLength.hpp"
#include "okapi/api/units/RQuantity.hpp"

//makes 360deg of rotation = 1 revolution 
double revolutions(double numOfRev) { 
    double answer = numOfRev * 360;

    return answer;
}

//converts inches to motor revolutioins
double inches(double numOfInches) { 
    double answer = numOfInches / 8.6393797974; //12.9590696961" is the circumfrence of the 4" omnis
    
    return revolutions(answer);
}


bool enablePID;
bool resetMotors;



///////////////////////////
//PID
///////////////////////////
double kP = 0.0; //0.285
double kI = 0.0; //0.0
double kD = 0.0; //0.0
double turnkP = 0.4; //0.7
double turnkI = 0.0; //0.0001
double turnkD = 0.0; //0.07



int desiredValue = inches(12);
int desiredTurnValue = 350; //counts | testing 1105 = 90 deg

int error; //Sensor Value - Desired Value || Positional Value
int prevError; //Pos 10ms ago
int derivative; //error - prevError || Speed
int totalError; //totalError + error

int turnError; //Sensor Value - Desired Value || Positional Value
int turnPrevError; //Pos 10ms ago
int turnDerivative; //turnError - turnPrevError || Speed
int turnTotalError; //turnTotalError + turnError


void PID() {
    
    resetMotors = true;

    while(enablePID) {
        while(resetMotors) {
            leftChassis.set_zero_position(0);
            rightChassis.set_zero_position(0);

            leftChassis.tare_position();
            rightChassis.tare_position();

            resetMotors = false;
        }

        int leftSidePosition = leftEncoder.get_value();
        int rightSidePosition = rightEncoder.get_value();
        int headingPosition = inertial.get_heading();


        int averagePosition = (leftSidePosition + rightSidePosition)/2;

        //Potential
        error = desiredValue - averagePosition;
        //Integral
        totalError = totalError + error;
        //Derivative
        derivative = error - prevError;
        


        int turnDiff = (leftSidePosition - rightSidePosition);

        //Potential
        turnError = desiredTurnValue - turnDiff; 
        //Integral
        turnTotalError += turnError;
        //Derivative
        turnDerivative = turnError - turnPrevError;



        prevError = error;
        turnPrevError = turnError;

        int lateralMotorPower =  error * kP + totalError * kI + derivative * kD;
        int turnMotorPower =  turnError * turnkP + turnTotalError * turnkI + turnDerivative * turnkD;

        setDrive(lateralMotorPower + turnMotorPower, lateralMotorPower - turnMotorPower);
        

        std::string str = std::to_string(headingPosition);
        pros::lcd::set_text(0, "headingPos");
        pros::lcd::set_text(1, str);

        std::string str1 = std::to_string(turnError);
        pros::lcd::set_text(2, "error");
        pros::lcd::set_text(3, str1);
        
        std::string str2 = std::to_string(turnTotalError);
        pros::lcd::set_text(4, "turnTotalError");
        pros::lcd::set_text(5, str2);

        std::string str3 = std::to_string(turnMotorPower);
        pros::lcd::set_text(6, "turnMotorPower");
        pros::lcd::set_text(7, str3);

        pros::delay(10);
        
    }
    
}
