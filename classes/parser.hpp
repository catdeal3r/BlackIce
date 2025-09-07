#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class ParsingHandler
{
  private:
    std::string scfile_loc = "./scfile";
    std::fstream open_scfile_loc();

  public:
    int write_scfile_loc(std::string);
    int clear_scfile_loc();

    int parse_scfile();

    static int remove_double_quotes(std::string);
    static std::vector<std::string> parse_array(std::string);
};
