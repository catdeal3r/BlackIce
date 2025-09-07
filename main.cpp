#include <iostream>
#include "classes/parser.hpp"
#include "classes/config.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  ParsingHandler ph;

  if (argv[1] == "--test-parse")
  {
    ph._test_parse_scfile();
    return 0;  
  }
  
  ph.parse_scfile();
}
