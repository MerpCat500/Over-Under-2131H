#include "Movement/DriverControl.h"

void DriverControl() {
  Terminal.Log("Start", "Driver Control Started");
  bool buttonR1pressing = false;
  double FLlast = 0;
  double FRlast = 0;

  while (true) {
    int FLAxis = Controller.Axis3.position();
    int FRAxis = Controller.Axis2.position();
    
    double FLsmooth = 0.97*FLlast + 0.3*FLAxis;
    double FRsmooth = 0.97*FRlast + 0.3*FRAxis;

    LeftDrive.spin(fwd, FLsmooth, pct);
    RightDrive.spin(fwd, FRsmooth, pct);

    if(Controller.ButtonR1.pressing() && !buttonR1pressing){ 
      buttonR1pressing = true;   
      Puncher.spinFor(fwd, 360, deg, 100, velocityUnits::pct, false);
      
    } else if (!Controller.ButtonR1.pressing() && buttonR1pressing) {
      buttonR1pressing = false;
    }

    FLlast = FLsmooth;
    FRlast = FRsmooth;
    wait(20, msec);
  }
}

