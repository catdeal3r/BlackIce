#include <iostream>
//#include "parser.hpp"
#include "classes/config.hpp"
#include <vector>

int main()
{
  ConfigHandler ch;

  ch.write_file("Johnny");
  ch.write_files({ "James", "Bob", "Barry", "Luke" });
  std::vector<std::string> files = ch.get_files();

  for (int i = 0; i < files.size(); i++)
    std::cout << files[i] << ", ";

  std::cout << "\b\b.\n";

  ch.remove_files({ 0, 2, 3 });
  files = ch.get_files();

  for (int i = 0; i < files.size(); i++)
    std::cout << files[i] << ", ";

  std::cout << "\b\b.\n";

  ch.write_cpp_mode(false);
  int cpp_mode = ch.get_cpp_mode();
  
  if (cpp_mode == 0)
    std::cout << "CPP mode is disabled.\n";
  else
    std::cout << "CPP mode is enabled.\n";
}
