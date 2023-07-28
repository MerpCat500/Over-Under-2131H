#include "driverCon.h"

void DriverControl() 
{
  
  // ==== Buttons ==== //
    bool ButtonR1pressing = false;
  // ================= //

  while(true) 
  {
    int Laxis = Controller1.Axis3.position();
    int Raxis = Controller1.Axis2.position();

    LeftDrive.spin(fwd, Laxis, pct);
    RightDrive.spin(fwd, Raxis, pct);

    if (Controller1.ButtonR1.pressing() && !ButtonR1pressing) 
    {
      ButtonR1pressing = true;

    } else if (!Controller1.ButtonR1.pressing() && ButtonR1pressing) 
    {
      ButtonR1pressing = false;
    }

    wait(20, msec);

  }
}