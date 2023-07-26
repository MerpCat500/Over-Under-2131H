#include "Screen.h"

// An Auton (On the brain)
Auton::Auton(const char* name, const char* desc, const char* points, void(*callback)(void)):
  Name{name},
  Desc{desc},
  Points{points},
  Callback{callback}
{

}

// A tab
Tab::Tab(const char* name, std::vector<Auton> autonList):
  Name{name},
  AutonList{autonList}
{

}

Screen::Screen():
  TabIndex{0},
  AutonIndex{0},
  ScreenPressing{false}
{

}

void Screen::PrintAtCentered(int x, int y, int Width, const char* String) 
{
  Brain.Screen.printAt(x + Width/2 - Brain.Screen.getStringWidth(String)/2, y, String);
}

bool Screen::WithinRect(int x1, int y1, int x2, int y2, int Width, int Height)
{
  if ((x1 > x2 && x1 < x2+Width) && (y1 > y2 && y1 < y2 + Height)) return true; else return false;
}

void Screen::TablistPress(int x, int y, int Width, int Height)
{
  if (WithinRect(Brain.Screen.xPosition(), Brain.Screen.yPosition(), x, y, Width*Tabs, Height))
  {
    int xoff = Brain.Screen.xPosition() - x;

    TabIndex = int(xoff / Width);
    AutonIndex = 0;

  }
}

void Screen::AutonlitsPress(int x, int y, int Width, int Height)
{
  if (WithinRect(Brain.Screen.xPosition(), Brain.Screen.yPosition(), x, y, Width, Height))
  {
    int yoff = Brain.Screen.yPosition() - y;

    AutonIndex  = int(yoff / (Height / Tablist[TabIndex].AutonList.size()));

  }
}

void Screen::DrawBg()
{
  Brain.Screen.setPenColor(vex::color(0xff1414));
  Brain.Screen.setFillColor(vex::color(0x000000));
  Brain.Screen.drawRectangle(0, 0, 480, 240);
}

void Screen::DrawTablist(int x, int y, int Width, int Height)
{
  Brain.Screen.setFont(propM);  
  Brain.Screen.setPenColor(vex::color(0xff1414));
  for(int i = 0; i<Tabs;i++)
  {
    if (i == TabIndex) Brain.Screen.setFillColor(vex::color(0x000000)); else Brain.Screen.setFillColor(vex::color(0x181818));
    Brain.Screen.drawRectangle(x + Width*i, y, Width, Height + Pad1*2);
    PrintAtCentered(x + Width*i+1, y + Height - Pad1*2, Width, Tablist[i].Name);
  }
}

void Screen::DrawAutonlist(int x, int y, int Width, int Height)
{
  Brain.Screen.setFont(propM);  
  Brain.Screen.setPenColor(vex::color(0xff1414));
  if (Height < Brain.Screen.getStringHeight(Tablist[TabIndex].AutonList[0].Name))
  {
    Height = Brain.Screen.getStringHeight(Tablist[TabIndex].AutonList[0].Name);
  }

  for(int i = 0; i < Tablist[TabIndex].AutonList.size(); i++) 
  {
    if (i == AutonIndex) Brain.Screen.setFillColor(vex::color(0x000000)); else Brain.Screen.setFillColor(vex::color(0x181818));
    Brain.Screen.drawRectangle(x, y + Height*i, Width, Height);
    PrintAtCentered(x, y + Height*i + Height/2 + Pad1, Width, Tablist[TabIndex].AutonList[i].Name);
  }
}

void Screen::DrawInfo(int x, int y, int Width, int Height)
{
  Brain.Screen.setPenColor(vex::color(0xff1414));
  Brain.Screen.setFillColor(vex::color(0x181818));

  Brain.Screen.drawRectangle(x, y, Width, Height);
  Brain.Screen.setFont(propL);

  PrintAtCentered(x, y + Brain.Screen.getStringHeight(Tablist[TabIndex].AutonList[AutonIndex].Name) - Pad2, Width, Tablist[TabIndex].AutonList[AutonIndex].Name);
  
  Brain.Screen.setFont(propM);
  Brain.Screen.printAt(x + Pad2, y + 70 + Pad2, "Set-Up: ");
  
  Brain.Screen.setFont(mono20);  
  Brain.Screen.printAt(x + Pad2, y + 70 + Pad2*2 + Brain.Screen.getStringHeight("Set-Up: ") + 7, Tablist[TabIndex].AutonList[AutonIndex].Desc);

  Brain.Screen.setFont(propM);
  Brain.Screen.printAt(x + Pad2, y + 70 + Pad2*2 + Brain.Screen.getStringHeight("Set-Up: ")*2, "Points: ");

  Brain.Screen.printAt(x + Pad2 + Brain.Screen.getStringWidth("Points: "), y + 70 + Pad2*2 + Brain.Screen.getStringHeight("Set-Up: ")*2, Tablist[TabIndex].AutonList[AutonIndex].Points);

}

void Screen::Update()
{
  
  if (Brain.Screen.pressing() && !ScreenPressing) 
  {
    ScreenPressing = true;
    TablistPress(5, 5, 60, 30);
    AutonlitsPress(5, 45, 240, 190);

    Competition.autonomous(Tablist[TabIndex].AutonList[AutonIndex].Callback);

    Draw();
  } else if (!Brain.Screen.pressing() && ScreenPressing) 
  {
    ScreenPressing = false;
  }
}

void Screen::Draw() 
{
  DrawBg();
  DrawTablist(5, 5, 60, 30);
  DrawAutonlist(5, 45, 240, 190/Tablist[TabIndex].AutonList.size());
  DrawInfo(250, 5, 225, 230);
}

