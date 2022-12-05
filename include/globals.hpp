#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "okapi/impl/device/rotarysensor/adiEncoder.hpp"

using namespace pros;

/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
extern Controller controller;

//drivetrain motors
extern Motor leftFront; //1 :1
extern Motor rightFront; //2 :2
extern Motor_Group leftChassis;
extern Motor leftBack; //3 :3
extern Motor rightBack; //4 :4
extern Motor_Group rightChassis;

extern Motor intake; //5 :10
extern Motor slingshot1; //6 :6
extern Motor slingshot2; //7 :7

extern ADIEncoder leftEncoder; //:A+B 
extern ADIEncoder rightEncoder; //:C+D 
extern ADIEncoder backEncoder; //:E+F 

extern Imu inertial; //:5

/////////////////////////////////
//GLOBAL VARIABLES
/////////////////////////////////

extern bool enablePID; //drive.cpp
extern bool resetMotors; //drive.cpp

extern int autoSelected; //gui.cpp