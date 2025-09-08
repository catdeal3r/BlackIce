#pragma once
#include <iostream>
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include <unordered_map>

class CompileHandler
{
  private:
    template <typename TP>
    std::time_t to_time_t(TP);

  public:
    std::unordered_map<std::string, std::string> load_mapped_time_file();
    int update_mapped_time_file();

    std::string get_time_metadata_file(std::string);
};
