#pragma once
#include <iostream>
#include "config.hpp"
#include <fstream>
#include <vector>

class ParsingHandler
{
  private:
    std::string scrfile_loc = "./scrfile";
    std::fstream open_scrfile_loc();

  public:
    int write_scrfile_loc(std::string);
    int clear_scrfile_loc();

    int parse_scrfile(ConfigHandler&);
    
    int _test_parse_scrfile();
    int _test_parse_option(std::string, std::string);

    static std::string parse_str(std::string);
    static std::vector<std::string> parse_array(std::string);
    static std::string remove_spaces_from_str(std::string);
};
