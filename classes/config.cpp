#include "config.hpp"
#include "parser.hpp"
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
  if (names.empty())
  {
    throw std::invalid_argument("ConfigHandler: 'write_files()' requires valid strings.");
  }
  
  for (const std::string& s : names)
    files.push_back(s);

  return 0;
}

int ConfigHandler::remove_file(int loc)
{
  (void)files.erase(files.begin() + loc);
  return 0;
}

int ConfigHandler::remove_files(std::vector<int> locs)
{
  if (locs.empty())
  {
    throw std::invalid_argument("ConfigHandler: 'remove_files()' requires valid integers.");
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
  if (files.empty()) {
    throw std::invalid_argument("ConfigHandler: files are not set.");
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
    std::cout << "[!] Unsupported compiler: '" << c << "'. You may experience issues while using it.\n";
  
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

std::string ConfigHandler::get_compiler_options()
{
  if (compiler_options.length() != 0)
    return compiler_options;

  return "";
}

int ConfigHandler::write_output_file(std::string name)
{
  if (name == "")
  {
    throw std::invalid_argument("ConfigHandler: 'write_output_file()' requires a valid string.");
    exit(1);
  }

  output_file = name;
  return 0;
}

std::string ConfigHandler::get_output_file()
{
  if (output_file.length() == 0)
  {
    throw std::invalid_argument("ConfigHandler: output_file is not set.");
    exit(1);
  }

  return output_file;
}

int ConfigHandler::write_generic_option(std::string key, std::string value)
{
  if (key == "compiler")
  {
    value = ParsingHandler::parse_str(value); 
    write_compiler(value);
  }
  else if (key == "compiler_options")
  {
    value = ParsingHandler::parse_str(value); 
    write_compiler_options(value);
  }
  else if (key == "files")
  {
    std::vector<std::string> files = ParsingHandler::parse_array(value);
    write_files(files);
  }
  else if (key == "output_file")
  {
    value = ParsingHandler::parse_str(value);
    write_output_file(value);
  }
  else
  {
    std::cout << "Unrecognized config key: '" << key << "'\n";
    exit(1);
  }
  
  return 0;
}
