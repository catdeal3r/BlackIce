#include "config.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int ConfigHandler::write_file(std::string name)
{
  if (name == "")
  {
    throw std::invalid_argument("ConfigHandler: 'write_file()' requires a valid string.");
    exit(1);
  }

  (void)files.push_back(name);
  return 0;
}

int ConfigHandler::write_files(std::vector<std::string> names)
{
  if (names.size() == 0)
  {
    throw std::invalid_argument("ConfigHandler: 'write_files()' requires valid strings.");
    exit(1);
  }
  
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
  if (locs.size() == 0)
  {
    throw std::invalid_argument("ConfigHandler: 'remove_files()' requires valid integers.");
    exit(1);
  }

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
  if (files.size() == 0){
    throw std::invalid_argument("ConfigHandler: files are not set.");
    exit(1);
  }
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
    throw std::invalid_argument("ConfigHandler: cpp_mode is not set.");
    exit(1);
  }

  return cpp_mode;
}

int ConfigHandler::write_compiler_options(std::string options)
{
  if (options == "")
  {
    throw std::invalid_argument("ConfigHandler: 'write_compiler_options()' requires a valid string.");
    exit(1);
  }
    
  compiler_options = options;
  return 0;
}

int ConfigHandler::clear_compiler_options()
{
  compiler_options = "";
  return 0;
}

std::string ConfigHandler::get_compiler_options()
{
  if (compiler_options.length() == 0)
  {
    throw std::invalid_argument("ConfigHandler: compiler_options is not set.");
    exit(1);
  }

  return compiler_options;
}

int ConfigHandler::write_generic_option(std::string key, std::string value)
{
  std::cout << "Option received: '" << key << "=" << value << "'\n";
  return 0;
}
