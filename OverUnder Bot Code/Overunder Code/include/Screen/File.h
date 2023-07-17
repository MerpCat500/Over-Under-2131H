#include <iostream>

#pragma once

class File 
{
public:
  std::string Name;
  std::string Desc;
  std::string Date;

  void(*Callback)(void);

  File();
  File(std::string name);
  File(std::string name, std::string desc, std::string date, void(*callback)(void));
  File(std::string name, std::string desc, std::string date);
};