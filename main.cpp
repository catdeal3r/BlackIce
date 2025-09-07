#include <iostream>
//#include "parser.hpp"
#include "classes/config.hpp"
#include <vector>

int main()
{
  ConfigHandler ch;

  ch.write_compiler_options("-L/etc/curlpp -lcurl -lcurlpp");
  std::string compiler_options = ch.get_compiler_options();
  std::cout << "Compiler options are '" << compiler_options << "'\n";

  ch.clear_compiler_options();
  compiler_options = ch.get_compiler_options();
  std::cout << "Compiler options are '" << compiler_options << "'\n";
}
