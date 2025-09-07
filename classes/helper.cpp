#include "helper.hpp"
#include <iostream>

int Helper::remove_double_quotes(std::string s)
{
  if (s.front() == '"')
    s.erase(0, 1);
    
  if (s.back() == '"')
    s.erase(s.size() - 1);

  return 0;
}
