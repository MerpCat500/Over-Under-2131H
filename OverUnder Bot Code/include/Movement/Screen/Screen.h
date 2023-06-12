#pragma once
#include "vex.h"

class File {
  
  void (* Auton) (void);
  File();

  File(void (* auton) (void));
  
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