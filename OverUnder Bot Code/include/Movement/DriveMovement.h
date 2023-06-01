#pragma once
#include "vex.h"

class Drivebase {

  Drivebase();

  void ramp();
  void rampTurn();

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