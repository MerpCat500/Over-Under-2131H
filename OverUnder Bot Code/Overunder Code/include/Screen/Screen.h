#include <iostream>
#include <map>
#include <vector>
#include "Screen/Button.h"

#pragma once

class ScreenBuilder 
{
public:

  ScreenBuilder();

  std::map<Button, std::vector<Button>> FileTree;

  void Draw();
};