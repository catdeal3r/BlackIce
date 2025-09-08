#pragma once
#include <iostream>
#include "config.hpp"
#include <fstream>
#include <vector>

class ParsingHandler
{
  private:
    std::string scfile_loc = "./scfile";
    std::fstream open_scfile_loc();
    std::string remove_spaces_from_str(std::string);

  public:
    int write_scfile_loc(std::string);
    int clear_scfile_loc();

    int parse_scfile(ConfigHandler&);
    
    int _test_parse_scfile();
    int _test_parse_option(std::string, std::string);

    static std::string parse_str(std::string);
    static std::vector<std::string> parse_array(std::string);
};
