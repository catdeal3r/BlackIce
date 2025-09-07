#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>

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
    struct stat result;
    
    if (stat(file.c_str(), &result))
    {
      auto time = result.st_mtime;
      std::cout << "Time last modified was: " << time << "\n";  
    }
    
    return 0;
  }
  
  ph.parse_scfile();
}
