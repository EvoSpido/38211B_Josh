#include "main.h"
#include "pros/motors.h"

using namespace pros;

/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
Controller controller(pros::E_CONTROLLER_MASTER);

//drivetrain motors
Motor leftFront(1, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); //1
Motor leftBack(2, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); //2
Motor_Group leftChassis({leftFront, leftBack});
Motor rightFront(3, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); //3
Motor rightBack(4, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); //4
Motor_Group rightChassis({rightFront, rightBack});

Imu inertial (5);

Motor slingshot1(6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS); //6
Motor slingshot2(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS); //7
Motor roller(9, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); //8
Motor intake(10, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); //5

ADIEncoder leftEncoder(1, 2, false); //:A+B 
ADIEncoder rightEncoder(3, 4, true); //:C+D 
ADIEncoder backEncoder(5, 6, false);  //:E+F 
