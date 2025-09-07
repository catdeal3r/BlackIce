#include "parser.hpp"
#include "compiler.hpp"
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <filesystem>

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
  std::tm *gmt = std::gmtime(&tt);
    
  std::stringstream buf;
  buf << tt;
  std::string formatted_file_time = buf.str();

  return formatted_file_time;
}
