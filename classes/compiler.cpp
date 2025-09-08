#include "parser.hpp"
#include "compiler.hpp"
#include "config.hpp"
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <vector>

template <typename TP>
std::time_t CompileHandler::to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}


std::string CompileHandler::get_time_metadata_file(std::string file)
{
  std::filesystem::file_time_type ftime = std::filesystem::last_write_time(file);
    
  std::time_t tt = to_time_t(ftime);
    
  std::stringstream buf;
  buf << tt;
  std::string formatted_file_time = buf.str();

  return formatted_file_time;
}

std::unordered_map<std::string, std::string> CompileHandler::load_mapped_time_file()
{
  std::unordered_map<std::string, std::string> mapped_times = {};

  std::fstream file(".sccache", std::ios::in);
  
  if (file.fail() || !file.is_open())
  {
    file.close();
    throw std::invalid_argument("CompileHandler: 'write_mapped_time_file()' failed because .sccache file is unreadable");
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

    key = ParsingHandler::remove_spaces_from_str(key);
    value = ParsingHandler::remove_spaces_from_str(value);

    key = ParsingHandler::parse_str(key);
    value = ParsingHandler::parse_str(value);

    mapped_times.insert({key, value});
  }
  
  return mapped_times;
}

int CompileHandler::update_mapped_time_file(ConfigHandler& h)
{
  std::fstream file(".sccache", std::ios::out);

  if (file.fail() || !file.is_open())
  {
    file.close();
    throw std::invalid_argument("CompileHandler: 'write_mapped_time_file()' failed because .sccache file is unwrittable");
    exit(1);
  }

  std::vector<std::string> files = h.get_files();
 
  std::string formatted_output;

  for (std::string s : files)
  {
    formatted_output += "\""; formatted_output += s; formatted_output += "\"=\"";
    std::string time_metadata = get_time_metadata_file(s);
    formatted_output += time_metadata; formatted_output += "\"\n";
  }

  file << formatted_output;
  
  return 0;
}


int CompileHandler::write_files_recompile_needed(std::vector<std::string> names)
{
  if (names.empty())
  {
    throw std::invalid_argument("CompileHandler: 'write_files_recompile_needed()' requires valid strings.");
  }
  
  for (const std::string& s : names)
    files_recompile_needed.push_back(s);

  return 0;
}