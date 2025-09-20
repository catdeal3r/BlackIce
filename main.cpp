#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include "classes/compiler.hpp"
#include <vector>
#include <unordered_map>

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
      ph._test_parse_scrfile();
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

  ph.parse_scrfile(h);
  std::vector<std::string> files = h.get_files();

  // create file if not already existing
  ch.create_mapped_time_file();
  std::unordered_map<std::string, std::string> times_and_files = ch.load_mapped_time_file();

  bool is_new_files;
  for (const std::string& s : files)
  {
    bool is_new = true;
    for (auto& x : times_and_files)
    {
      if (x.first == s)
        is_new = false;
    }

    if (is_new == true)
      is_new_files = true;
  }


  if (times_and_files.empty() || is_new_files == true)
  {
    ch.write_files_recompile_needed(h.get_files());
  }
  else 
  {
    for (auto& x : times_and_files)
    {
      std::string file = x.first;
      std::string time = x.second;

      std::string current_time = ch.get_time_metadata_file(file);

      if (time != current_time)
      {
        ch.write_files_recompile_needed({file});
      }
    }
  }

  ch.compile(h);

  ch.update_mapped_time_file(h);
}
