#include "vex.h"
#include "Screen/Screen.h"

ScreenBuilder::ScreenBuilder() 
{
  FileTree = 
    {
      {Button(File("FAWPS")), 
        {
          Button(5 + 10, 0+30, 200, File("Right FAWP", "NA", "NA")), 
          Button(5 + 10, 30+30, 200, File("Left FAWP", "NA", "NA"))
          }
        },

      {Button(File("HAWPS")), 
        {
          Button(5 + 10, 60+30, 200, File("Right HAWP", "NA", "NA")), 
          Button(5 + 10, 90+30, 200, File("Left HAWP", "NA", "NA"))
        }
      },

      {Button(File("OTHER")), 
        {
          Button(5 + 10, 120+30, 200, File("Skills", "NA", "NA"))
        }
      }

    };
}

void ScreenBuilder::Draw()
{
  Brain.Screen.clearScreen();
  
  for(auto i : FileTree) 
  {
    for(int j = 0; j < i.second.size(); j++) 
    {
      i.second[j].DrawFile();
      // std::cout << i.second[j].TiedFile.Name << std::endl;
    }
  }
}