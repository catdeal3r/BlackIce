#include "config.hpp"
#include <iostream>
#include <vector>

int ConfigHandler::write_file(std::string name)
{
  (void)files.push_back(name);
  return 0;
}

int ConfigHandler::write_files(std::vector<std::string> names)
{
  for (int i = 0; i < names.size(); i++)
    (void)files.push_back(names[i])

  return 0;
}

std::vector<std::string> ConfigHandler::get_files()
{
  return files;
}

