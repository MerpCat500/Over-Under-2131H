#pragma once
#include "vex.h"

class Motion {

  int wheelSize;
  Motion(int WheelSize): 
    wheelSize{WheelSize}
    {

    };

  void linearRamp(double Distance, double speed, bool right = false) {

    AllDriveMotors.setStopping(coast);
    AllDriveMotors.resetRotation();
    AllDriveMotors.resetPosition();

    AllDriveMotors.spin(fwd, 0, pct);

    Distance = (Distance/(wheelSize*2*M_PI))*360;
    if (right) {
      for (int i = 0; i < speed; i++) {
        RightDrive.setVelocity(i, percent);
        LeftDrive.setVelocity(i*-1, percent);

        wait(3, msec);
      }
      while (fabs(AllDriveMotors.position(degrees)) < Distance) {
        wait(1, msec);
      }
      for (int i = speed; i > 0; i--) {
        RightDrive.setVelocity(i, percent);
        LeftDrive.setVelocity(i*-1, percent);
        wait(7, msec);
      }
    } else {
      for (int i = 0; i < speed; i++) {
        RightDrive.setVelocity(i*-1, percent);
        LeftDrive.setVelocity(i, percent);

        wait(3, msec);
      }
      while (fabs(AllDriveMotors.position(degrees)) < Distance) {
        wait(1, msec);
      }
      for (int i = speed; i > 0; i--) {
        RightDrive.setVelocity(i*-1, percent);
        LeftDrive.setVelocity(i, percent);
        wait(7, msec);
      }
    }

    AllDriveMotors.stop();
  }

  void linearRampTurn(double Distance, double speed, int reverse = 1){

    AllDriveMotors.setStopping(coast);
    AllDriveMotors.resetRotation();
    AllDriveMotors.resetPosition();

    AllDriveMotors.spin(fwd, 0, pct);

    Distance = (Distance/(wheelSize*2*M_PI))*360;

    for (int i = 0; i < speed; i++) {
      AllDriveMotors.setVelocity(i*reverse, percent);
      wait(3, msec);
    }
    while (fabs(AllDriveMotors.position(degrees)) < Distance) {
      wait(1, msec);
    }
    for (int i = speed; i > 0; i--) {
      AllDriveMotors.setVelocity(i*reverse, percent);
      wait(7, msec);
    }

    AllDriveMotors.stop();
  
  }

  void turn(double Distance, double speed, bool right = false, bool blocking = true) {
    if (right) {
      LeftDrive.spinFor(Distance, deg, speed*-1, velocityUnits::pct, false); 
      RightDrive.spinFor(Distance, deg, speed, velocityUnits::pct, blocking); 
    } else {
      LeftDrive.spinFor(Distance, deg, speed, velocityUnits::pct, false); 
      RightDrive.spinFor(Distance, deg, speed*-1, velocityUnits::pct, blocking); 
    } 
  }

  void drive(double Distance, double speed, bool reverse = false, bool blocking = true) {
    if (reverse) {
      AllDriveMotors.spinFor(Distance, deg, speed*-1, velocityUnits::pct, blocking); 
    } else {
      AllDriveMotors.spinFor(Distance, deg, speed, velocityUnits::pct, blocking); 
    }
  }

};