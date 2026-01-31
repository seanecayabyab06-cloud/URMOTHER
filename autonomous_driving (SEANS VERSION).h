#include "vex.h"
#include "odometry.h"
using namespace vex; 

// motors
motor LeftMotor1 = motor(PORT1, ratio36_1, false);
motor LeftMotor2 = motor(PORT2, ratio36_1, true);

motor RightMotor1 = motor(PORT3, ratio36_1, true);
motor RightMotor2 = motor(PORT4, ratio36_1, false);

// inertial sensor
inertial Inertial = inertial (PORT5);

//robot constants
const double wheelDiameter = 50.0; // in millimeters
const double wheelCircumference = M_PI * wheelDiameter;

void totalDistance (double mm){
double rotations = mm / wheelCircumference;

LeftMotor1.setVelocity(30, percent);
LeftMotor2.setVelocity(30, percent);
RightMotor1.setVelocity(30, percent);
RightMotor2.setVelocity(30, percent);

LeftMotor1.spinFor(forward, rotations, turns, false);
LeftMotor2.spinFor(forward, rotations, turns, false);
RightMotor1.spinFor(forward, rotations, turns, false);
RightMotor2.spinFor(forward, rotations, turns, true);

LeftMotor1.stop(hold);
LeftMotor2.stop(hold);
RightMotor1.stop(hold);
RightMotor2.stop(hold);
}

void turnLeft(double degrees){
  Inertial.resetRotation();

  while (Inertial.rotation() >-degrees){
    LeftMotor1.spin(reverse, 15, percent);
    LeftMotor2.spin(reverse, 15, percent);
    RightMotor1.spin(forward, 15, percent);
    RightMotor2.spin(forward, 15, percent);
    wait(10, msec);
  }
    LeftMotor1.stop(hold);
    LeftMotor2.stop(hold);
    RightMotor1.stop(hold);
    RightMotor2.stop(hold);
  
}

void REVERSAL1 (double mm){

double rotations1 = mm / wheelCircumference;

LeftMotor1.setVelocity(30, percent);
LeftMotor2.setVelocity(30, percent);
RightMotor1.setVelocity(30, percent);
RightMotor2.setVelocity(30, percent);

LeftMotor1.spinFor(reverse, rotations1, turns, false);
LeftMotor2.spinFor(reverse, rotations1, turns, false);
RightMotor1.spinFor(reverse, rotations1, turns, false);
RightMotor2.spinFor(reverse, rotations1, turns, true);

LeftMotor1.stop(hold);
LeftMotor2.stop(hold);
RightMotor1.stop(hold);
RightMotor2.stop(hold);
}

void PATH2 (double mm){

  LeftMotor1.set



  +





  
}

int main ()
{

  Inertial.calibrate();
  while (Inertial.isCalibrating()){
    wait(20, msec);

  }
  Inertial.setRotation(0, degrees);
 totalDistance(94.0); // MAKES THE ROBOT GOES FORWARD 1.23m
 turnLeft(90);
 totalDistance(32.0);
 REVERSAL1(64.0);


    }