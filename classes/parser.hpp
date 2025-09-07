#pragma once
#include <iostream>
#include <fstream>

class ParsingHandler
{
  private:
    std::string scfile_loc = "./scfile";
    std::fstream open_scfile_loc();

  public:
    int write_scfile_loc(std::string);
    int clear_scfile_loc();

    int parse_scfile();
};
