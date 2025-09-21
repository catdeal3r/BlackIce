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

std::string CompileHandler::get_stdout_cmd(std::string cmd)
{
  std::string data;
  FILE *stream;

  const int max_buffer = 256;
  char buffer[max_buffer];

  stream = popen(cmd.c_str(), "r");

  if (stream)
  {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
  }

  int return_status = pclose(stream);

  return data;
}

std::vector<std::string> CompileHandler::split_str(std::string str, std::string spliter)
{
		std::vector<std::string> parts;
		size_t pos = 0;
		std::string part;
		
		while ((pos = str.find(spliter)) != std::string::npos)
		{
			part = str.substr(0, pos);
			parts.push_back(part);
			str.erase(0, pos + spliter.length());
		}

		parts.push_back(str);
	
		return parts;
}

int CompileHandler::create_mapped_time_file()
{
  std::ifstream file(".scrcache");

  if (file.good())
    return 0;

  file.close();
  std::ofstream file_touch(".scrcache");
  file_touch.close();

  return 0;
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

  std::fstream file(".scrcache", std::ios::in);
  
  if (file.fail() || !file.is_open())
  {
    file.close();
    throw std::invalid_argument("CompileHandler: 'load_mapped_time_file()' failed because .scrcache file is unreadable");
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
  std::fstream file(".scrcache", std::ios::out);

  if (file.fail() || !file.is_open())
  {
    file.close();
    throw std::invalid_argument("CompileHandler: 'update_mapped_time_file()' failed because .scrcache file is unwrittable");
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

  // Debug
  /*for (const std::string& s : files_recompile_needed)
    std::cout << s << "\n";*/

  return 0;
}

int CompileHandler::compile(ConfigHandler& h)
{
  std::string cmd = h.get_compiler();
  cmd += " -c ";

  for (const std::string& s : files_recompile_needed)
    cmd += s + " ";

  cmd += h.get_compiler_options();
  
  std::string cmd_two = h.get_compiler();
  cmd_two += " ";
  cmd_two += h.get_compiler_options();
  cmd_two += " -o ";
  cmd_two += h.get_output_file();
  cmd_two += " ";

  for (const std::string& s : h.get_files())
  {
    std::string file = s;

    // Cause g++ puts object files in the current directory
    std::vector<std::string> parts = split_str(file, "/");
    file = parts.back();

    if (file.back() == 'c')
    {
      file[file.length() - 1] = 'o';
    }
    else if (file.back() == 'p' && file[file.length() - 2] == 'p' && file[file.length() - 3] == 'c')
    {
      file.erase(file.length() - 2);
      file[file.length() - 1] = 'o';
    }

    // TODO: clean up compile checking to be more changeable
    if
    (
      file[file.length() - 1] != 'p' && 
      file[file.length() - 2] != 'p' && 
      file[file.length() - 3] != 'h' &&
      file[file.length() - 1] != 'h'
    )
    {
      cmd_two += file + " ";
    }
  }

  // Debug
  /*std::cout << cmd << "\n";
  std::cout << cmd_two << "\n";*/

  std::string compile = "";

  if (!files_recompile_needed.empty())
    compile = get_stdout_cmd(cmd);

  std::string link = get_stdout_cmd(cmd_two);

  if (!compile.empty())
    std::cout << compile;

  if (!link.empty())
    std::cout << link;

  return 0;
}
