#pragma once
#include <iostream>
#include "config.hpp"
#include <fstream>
#include <vector>

class ParsingHandler
{
  private:
    std::string bifile_loc = "./bifile";
    std::fstream open_bifile_loc();

  public:
    int write_bifile_loc(std::string);
    int clear_bifile_loc();

    int parse_bifile(ConfigHandler&);
    
    int _test_parse_bifile();
    int _test_parse_option(std::string, std::string);

    static std::string parse_str(std::string);
    static std::vector<std::string> parse_array(std::string);
    static std::string remove_spaces_from_str(std::string);
};
