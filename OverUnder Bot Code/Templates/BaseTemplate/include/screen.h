#include "vex.h"
#include <iostream>
#include <vector>

#pragma once

struct Auton
{
public:
  const char* Name;
  const char* Desc;
  const char* Points;

  void(*Callback)(void);

  Auton(const char* name, const char* desc, const char* points, void(*callback)(void));
};

struct Tab 
{
public:
  const char* Name;
  std::vector<Auton> AutonList;

  Tab(const char* Name, std::vector<Auton> AutonList);

};

namespace Screen 
{
  void NONE() {}

  static const int Tabs = 4;
  const int ListSize = 5;
  const int Pad1 = 3;
  const int Pad2 = 5;

  extern int TabIndex(0);
  extern int AutonIndex(0);
  extern bool ScreenPressing(false);

  Tab Tablist[Tabs] = 
  {
    Tab(
      "Match", 
      {
        Auton("Left HAWP", "NONE", "0", NONE), 
        Auton("Left Alt HAWP", "NONE", "0", NONE),
        Auton("Right HAWP", "NONE", "0", NONE),
        Auton("Right Alt HAWP", "NONE", "0", NONE), 
        Auton("Full Win Point", "NONE", "0", NONE),
      }
    ), 
    Tab(
      "Skills",
      {
        Auton("Skills 1", "NONE", "0", NONE),
      }
    ), 
    Tab(
      "Other",
      {
        Auton("Troll", "TROLL", "T-T", NONE), 
      }
    ), 
    Tab(
      "Debug", 
      {
        Auton("Drive Forward", "NONE", "0", NONE), 
        Auton("Turn", "NONE", "0", NONE),
        Auton("Fire", "NONE", "0", NONE)
      }
    )
  };

  void PrintAtCentered(int x, int y, int Width, const char* String);
  bool WithinRect(int x1, int y1, int x2, int y2, int Width, int Height);

  void TablistPress(int x, int y, int Width, int Height);
  void AutonlitsPress(int x, int y, int Width, int Height);

  void DrawBg();
  void DrawTablist(int x, int y, int Width, int Height);
  void DrawAutonlist(int x, int y, int Width, int Height);
  void DrawInfo(int x, int y, int Width, int Height);

  void Update();
  void Draw();

};