#include <iostream>
//#include "parser.hpp"
#include "classes/config.hpp"
#include <vector>

int main()
{
  ConfigHandler ch;

  std::string compiler_options = ch.get_compiler_options();
  std::cout << "Compiler options are '" << compiler_options << "'\n";
}
