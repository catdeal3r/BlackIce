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

int ConfigHandler::write_compiler(std::string c)
{
  if (c == "")
  {
      throw std::invalid_argument("ConfigHandler: 'write_compiler()' requires a valid string.");
      exit(1);
  }

  if (c != "g++" && c != "gcc")
  {
    std::cout << "Config error: unsupported compiler: '" << c << "'.\n";
    exit(1);
  }
  
  compiler = c;
  return 0;
}

std::string ConfigHandler::get_compiler()
{
  if (compiler.length() == 0)
  {
    throw std::invalid_argument("ConfigHandler: compiler is not set.");
    exit(1);
  }

  return compiler;
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

  if (key == "compiler")
  {
    write_compiler(value);
  }
  else if (key == "compiler_options")
  {
    write_compiler_options(value);
  }
  else
  {
    std::cout << "Unrecognized config key: '" << key << "'\n";
    exit(1);
  }
  
  return 0;
}
