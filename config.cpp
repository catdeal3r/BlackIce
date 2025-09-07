#include "config.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int ConfigHandler::write_file(std::string name)
{
  (void)files.push_back(name);
  return 0;
}

int ConfigHandler::write_files(std::vector<std::string> names)
{
  for (int i = 0; i < names.size(); i++)
    (void)files.push_back(names[i]);

  return 0;
}

int ConfigHandler::remove_file(int loc)
{
  (void)files.erase(files.begin() + loc);
  return 0;
}

int ConfigHandler::remove_files(std::vector<int> locs)
{
  for (int i = 0; i < locs.size(); i++)
  {
    if (i == 0)
      (void)files.erase(files.begin() + locs[i]);
    else
      (void)files.erase(files.begin() + locs[i] - i);
  }

  return 0;
}

std::vector<std::string> ConfigHandler::get_files()
{
  return files;
}

int ConfigHandler::write_cpp_mode(int state)
{
  cpp_mode = state;
  return 0;
}

int ConfigHandler::get_cpp_mode()
{
  if (cpp_mode == -1)
  {
    throw std::invalid_argument("ConfigHandler: cpp_mode is not set");
    exit(1);
  }

  return cpp_mode;
}
