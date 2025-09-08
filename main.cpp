#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include "classes/compiler.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<std::string> command_input;
  
  ParsingHandler ph;
  CompileHandler ch;
  ConfigHandler h;
  
  if (argc > 1)
  {
    for (int i = 0; i < argc; i++)
      command_input.push_back(argv[i]);
  

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
    
      std::string time = ch.get_time_metadata_file(file); 
      std::cout << "File write time is " << time << "\n";    

      return 0;
    }
  }

  ph.parse_scfile(h);

  std::vector<std::string> list = h.get_files();

  for (const std::string& s : list)
    std::cout << s << "\n";

  ch.update_mapped_time_file(h);
}
