#pragma once
#include <iostream>
#include <vector>

class ConfigHandler
{
  private:
    std::vector<std::string> files;

  public:
    int write_file(std::string);
    int write_files(std::vector<std::string>);
    int remove_file(int);
    int remove_files(std::vector<int>);
    std::vector<std::string> get_files();
};
