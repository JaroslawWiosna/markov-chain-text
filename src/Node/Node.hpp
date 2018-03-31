#ifndef NODE_HPP
#define NODE_HPP

#include "Random.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

class Node
{
  public:
    unsigned size();
    void add(std::string s);
    std::string getRandom();
    std::string word;
    std::map<std::string, unsigned> map;
};

#endif
