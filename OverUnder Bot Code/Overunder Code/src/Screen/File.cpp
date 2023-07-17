#include "Screen/File.h"

File::File() 
{
  Name = "Unknown";
  Desc = "N/A";
  Date = "N/A";
  Callback = NULL;
}

File::File(std::string name):
Name{name}
{
  
}

File::File(std::string name, std::string desc, std::string date, void(*callback)(void)):
  Name{name},
  Desc{desc},
  Date{date},
  Callback{callback}
{ 
  
}

File::File(std::string name, std::string desc, std::string date):
  Name{name},
  Desc{desc},
  Date{date}
{
  Callback = NULL;
}

