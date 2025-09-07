#include "helper.hpp"
#include <iostream>
#include <vector>

int Helper::remove_double_quotes(std::string s)
{
  if (s.front() == '"')
    s.erase(0, 1);
    
  if (s.back() == '"')
    s.erase(s.size() - 1);

  return 0;
}

std::vector<std::string> process_array(std::string s)
{
  std::vector<std::string> array;
  std::string current_str = "";
  bool processing = false;

  for (char c : s)
  {
    if (processing == true)
    {
      if (c == '"')
      {
        processing = false;
        array.push_back(current_str);
        current_str = "";
        continue;
      }

      current_str += c;
    }
      
    if (c == '"')
      processing = true;
  }

  return array;
}
