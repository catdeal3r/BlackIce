#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include <vector>

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
  
  ph.parse_scfile();
}
