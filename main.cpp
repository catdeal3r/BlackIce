#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include <vector>
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <sstream>

template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
              + system_clock::now());
    return system_clock::to_time_t(sctp);
}

int main(int argc, char* argv[])
{
  std::vector<std::string> command_input;
  
  for (int i = 0; i < argc; i++)
    command_input.push_back(argv[i]);
  
  ParsingHandler ph;

  if (command_input[1] == "--test-parse")
  {
    std::cout << "Testing parser .....\n";
    ph._test_parse_scfile();
    return 0;  
  }

  if (command_input[1] == "--test-metadata")
  {
    std::string file = command_input[2];
    std::cout << "Testing metadata for " << file << " .....\n";

    std::filesystem::file_time_type ftime = std::filesystem::last_write_time(file);
    
    std::time_t tt = to_time_t(ftime);
    std::tm *gmt = std::gmtime(&tt);
    
    std::stringstream buffer;
    buffer << std::put_time(gmt, "%A, %d %B %Y %H:%M");
    std::string formattedFileTime = buffer.str();
    
    std::cout << "File write time is " << formattedFileTime << "\n";    

    return 0;
  }
  
  ph.parse_scfile();
}
