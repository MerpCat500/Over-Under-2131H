#include "vex.h"

void DriverControl() 
{
  
  // ==== Buttons ==== //
    bool ButtonR1pressing = false;
  // ================= //

  // ==== Toggles ==== //
    bool Punching = false;
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
      
      if (Punching) 
      {
        Punching = false;
        Puncher.stop();
      } else
      {
        Punching = true;
        Puncher.spin(fwd, 100, pct);
      }

    } else if (!Controller1.ButtonR1.pressing() && ButtonR1pressing) 
    {
      ButtonR1pressing = false;
    }

    wait(20, msec);

  }
}