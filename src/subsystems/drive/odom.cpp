#include "main.h"
#include "pros/rtos.hpp"
#include <cmath>
#include <string>

// Define distance between left, right, and back tracking wheels to the tracking center with the respective direction.
double dL = 3.125; 
double dR = 3.125; 
double dB = 5.625; 


// Variables decalared outside of function so they can be displayed to the screen
double currentOrientation = 0;
double currentX = 0;
double currentY = 0;
// Main function calculating orientation and position.

void algorithmMain() {
    
    double previousLeftTick = 0;
    double previousRightTick = 0;
    double previousBackTick = 0;
    double previousOrientation = 0;
    double previousX = 0;
    double previousY = 0;

    // While loop to continuously update position and orientation
    while(true) {
       
        // Get current number of ticks. 
        double currentLeftTick = leftEncoder.get_value();
        double currentRightTick = rightEncoder.get_value();
        double currentBackTick = backEncoder.get_value();
        // double currentIMUTick = inertial.get_rotation() * (M_PI / 180);
    

        // Calculate change in distance (in inches) from left, right, and back tracking wheel.
        double deltaL = ((currentLeftTick - previousLeftTick) / 360.0) * 8.64;
        double deltaR = ((currentRightTick - previousRightTick) / 360.0)  * 8.64;
        double deltaB = ((currentBackTick - previousBackTick) / 360.0) * 8.64;
       
   
        // Calculation of Orientation using an average of encoder math and IMU reading.    
        currentOrientation = (previousOrientation) + ((deltaL - deltaR) / (dL + dR));   
        // double currentOrientation = (  (previousOrientation) + ((deltaL - deltaR) / (dL + dR)) + (currentIMUTick)  ) / 2.00; 
        currentX = (previousX) + 2*((deltaB / currentOrientation) + dB) * sin((currentOrientation/2));
        currentY = (previousY) + 2*((deltaR / currentOrientation) + dR) * sin((currentOrientation/2));
   
    
        // Display values to debug.
        char orientationstr[32];
        snprintf(orientationstr, 32, "Current Orientation: %f", currentOrientation);
        setDiagText(0, orientationstr);
        
        char Xstr[32];
        snprintf(Xstr, 32, "X: %f", currentX);
        setDiagText(1, Xstr);

        char Ystr[32];
        snprintf(Ystr, 32, "Y: %f", currentY);
        setDiagText(2, Ystr);
        
        // Set previous tick # for next iteration.
        previousLeftTick = currentLeftTick;
        previousRightTick = currentRightTick;
        previousBackTick = currentBackTick;
        previousOrientation = currentOrientation;
        previousX = currentX;
        previousY = currentY;
        pros::delay(10);
        
    }
}

   
/* Notes

// https://okapilib.github.io/OkapiLib/md_docs_tutorials_walkthrough_odometry.html
To calculate change in orientation Δ θ
Use this formula
Δ θ = ΔL - ΔR  / sL + sR
Where delta L and R is the change in distance (in inches) from the respective direction.
To calculate change in position Δ d
Use this formula: 2sin(theta/2) (change in L/theta) + dL
Not sure how to input sin in the math.

Without IMU Test Trial: 
1.58
1.53
1.55

Pretty Damm Accurate

IMU Alone
1.54
1.61
1.60
IDK MAN trials seem sus.
*/




       
        
    



