#include "parser.hpp"
#include <fstream>
#include <iostream>
#include "config.hpp"
#include <sstream>

std::fstream ParsingHandler::open_scfile_loc()
{
  std::fstream file(scfile_loc, std::ios::in);
  
  if (file.fail())
  {
    file.close();
    throw std::invalid_argument("ParsingHandler: 'open_scfile_loc()' failed as scfile is unreadable.");
    exit(1);
  }
  
  return file;
}

int ParsingHandler::write_scfile_loc(std::string loc)
{
  scfile_loc = loc;
  return 0;
}

int ParsingHandler::clear_scfile_loc()
{
  scfile_loc = "";
  return 0;
}

int ParsingHandler::parse_scfile()
{
  ConfigHandler ch;
  std::fstream file = open_scfile_loc();

  if (!file.is_open())
  {
    (void)file.close();
    throw std::invalid_argument("ParsingHandler: 'parse_scfile()' failed as scfile is unreadable.");
    exit(1);
  }

  // nestingg ahhhhh
  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream is_line(line);
    std::string key;
    
    if (!std::getline(is_line, key, '='))
      continue;
    
    std::string value;
    if (std::getline(is_line, value))
      ch.write_generic_option(key, value);
  }
  
  file.close();
  return 0;
}
