#pragma once
#include <iostream>
#include <vector>

class ConfigHandler
{
  private:
    std::vector<std::string> files;
    int cpp_mode = -1;
    std::string compiler_options;

  public:
    int write_file(std::string);
    int write_files(std::vector<std::string>);
    int remove_file(int);
    int remove_files(std::vector<int>);
    std::vector<std::string> get_files();

    int write_cpp_mode(int);
    int get_cpp_mode();

    int write_compiler_options(std::string);
    int clear_compiler_options();
    std::string get_compiler_options();

    int write_generic_option(std::string, std::string);
};
