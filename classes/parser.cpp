#include "parser.hpp"
#include <fstream>
#include <iostream>
#include "config.hpp"
#include <sstream>
#include <vector>

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

  std::cout << "Opened file\n";

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream is_line(line);
    std::string key;
    
    if (!std::getline(is_line, key, '='))
      continue;
    
    std::string value;
    if (!std::getline(is_line, value))
      continue;

    key = remove_spaces_from_str(key);
    value = remove_spaces_from_str(value);

    ch.write_generic_option(key, value);
  }
  
  file.close();
  return 0;
}

std::string ParsingHandler::parse_str(std::string s)
{
  std::string str = "";
  bool processing = false;

  for (char c : s)
  {
    if (processing == true)
    {
      if (c == '"')
      {
        processing = false;
        break;
      }

      str += c;
    }
      
    if (c == '"')
      processing = true;
  }

  return str;
}

std::vector<std::string> ParsingHandler::parse_array(std::string s)
{
  std::vector<std::string> array;
  std::string current_str = "";
  bool processing = false;

  for (char c : s)
  {
    if (processing == true)
    {
      if (c == '"')
      {
        processing = false;
        array.push_back(current_str);
        current_str = "";
        continue;
      }

      current_str += c;
    }
      
    if (c == '"')
      processing = true;
  }

  return array;
}


int ParsingHandler::_test_parse_scfile()
{
  std::fstream file = open_scfile_loc();

  if (!file.is_open())
  {
    (void)file.close();
    throw std::invalid_argument("ParsingHandler: 'parse_scfile()' failed as scfile is unreadable.");
    exit(1);
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream is_line(line);
    std::string key;
    
    if (!std::getline(is_line, key, '='))
      continue;
    
    std::string value;
    if (!std::getline(is_line, value))
      continue;

    key = remove_spaces_from_str(key);
    value = remove_spaces_from_str(value);
    
    _test_parse_option(key, value);
  }
  
  file.close();
  return 0;
}

int ParsingHandler::_test_parse_option(std::string key, std::string value)
{
  if (key == "compiler")
  {
    value = ParsingHandler::parse_str(value); 
    std::cout << "Value for key '" << key << "' is: '" << value << "'\n";
  }
  else if (key == "compiler_options")
  {
    value = ParsingHandler::parse_str(value); 
    std::cout << "Value for key '" << key << "' is: '" << value << "'\n";
  }
  else if (key == "files")
  {
    std::vector<std::string> files = ParsingHandler::parse_array(value);

    std::cout << "Values for key '" << key << "' is: '";
    for (std::string s : files)
      std::cout << "\"" << s << "\", ";

    std::cout << "\b\b'\n";
  }
  else
  {
    std::cout << "Unrecognized config key: '" << key << "'\n";
    exit(1);
  }
  
  return 0;
}

std::string ParsingHandler::remove_spaces_from_str(std::string s)
{
  if (s.front() == ' ')
    s.erase(0, 1);

  if (s.back() == ' ')
    s.erase(s.size() - 1);
  
  return s;
}
