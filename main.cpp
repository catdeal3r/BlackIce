#include <iostream>
//#include "parser.hpp"
#include "config.hpp"
#include <vector>

int main()
{
  ConfigHandler ch;

  ch.write_file("Johnny");
  ch.write_files({ "James", "Bob" });
  std::vector<std::string> files = ch.get_files();

  for (int i = 0; i < files.size(); i++)
    std::cout << files[i] << ", ";

  std::cout << "\b\b.\n";
}
