#pragma once
#include "vex.h"
#include <vector>



class file {
public:
  void (* Auton) (void);
  const char* Name;
  const char* Desc;
  const char* Pnts;
  const char* Time;

  file();

  file(void (* auton) (void), const char* name = "", const char* desc = "", const char* pnts = "", const char* time = "") :
    Auton{auton},
    Name{name},
    Desc{desc},
    Pnts{pnts},
    Time{time}
  {

  }
  
  void terminalLog() {
    std::cout << "- " << Name << std::endl;
  }
};

class folder : public file {
public:
  std::vector<file> groupedFiles;

  template<typename ... Files>
  folder(const char* name, Files&... File):file()
  {
    
    Name = name;
    ((groupedFiles.push_back(File)), ...);
  }

  void terminalLog() {
    std::cout << "- " << Name << std::endl;
    for(int i = 0; i < groupedFiles.size(); i++) {
      std::cout << "  ";
      groupedFiles[i].terminalLog();
    }
  }
};

/*

Folder -
  -Folder
    -File
  -Folder
    -File
    -File
    -File

Main -
  -Skills
    -Skills Main
  -Left
    -Left HAWP
    -Left FAWP
    -Left Def

Main -
  -FAWP
    -Left FAWP
    -Right FAWP
  -HAWP
    -Left
    -Right
  -SKILLS
    -Skills Main
  -OTHER
    -Left Def
    

*/