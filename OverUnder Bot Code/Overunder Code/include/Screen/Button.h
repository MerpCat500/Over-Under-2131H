#include <iostream>
#include "Screen/File.h"

#pragma once

class Button 
{
public:
  int x, y;
  int width, height;
  int pad;

  File TiedFile;

  Button();
  Button(int X, int Y, int Width, int Height);
  Button(int X, int Y, int Width, File tiedFile, int Pad = 5);

  void DrawFile();

};