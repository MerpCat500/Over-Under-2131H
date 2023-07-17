#include "vex.h"
#include "Screen/Button.h"

Button::Button()
{
  
}

Button::Button(int X, int Y, int Width, int Height):
  x{X},
  y{Y - Height},
  width{Width},
  height{Height}
{
  
}

Button::Button(int X, int Y, int Width, File tiedFile, int Pad):
  x{X},
  y{Y},
  width{Width},
  height{Brain.Screen.getStringHeight(tiedFile.Name.c_str())},
  pad{Pad},
  TiedFile{tiedFile}
{
  
}

void Button::DrawFile()
{
  // std::cout << "Drawing" << std::endl;
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(x - pad, y - height, width + pad*2, height + pad*2, black);
 	Brain.Screen.printAt(x, y, TiedFile.Name.c_str());
}