#pragma once
#include <iostream>
#include <vector>

class ConfigHandler
{
  private:
    std::vector<std::string> files;
    std::string compiler;
    std::string compiler_options;
    std::string output_file;

  public:
    int write_file(std::string);
    int write_files(std::vector<std::string>);
    int remove_file(int);
    int remove_files(std::vector<int>);
    std::vector<std::string> get_files();

    int write_compiler(std::string);
    std::string get_compiler();

    int write_compiler_options(std::string);
    std::string get_compiler_options();

    int write_output_file(std::string);
    std::string get_output_file();

    int write_generic_option(std::string, std::string);
};
