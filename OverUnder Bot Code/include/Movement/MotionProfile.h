#pragma once
#include "vex.h"

class Motion {

  int wheelSize;
  Motion(int WheelSize): 
    wheelSize{WheelSize}
  {

  };

  void linearRamp(double Distance, double speed, bool right = false);
  void linearRampTurn(double Distance, double speed, int reverse = 1);
  void turn(double Distance, double speed, bool right = false, bool blocking = true);
  void drive(double Distance, double speed, bool reverse = false, bool blocking = true);

};

