#ifndef CHAIN_HPP
#define CHAIN_HPP
#include "Node.hpp"
#include <string>
#include <iostream>
#include <string>
#include <fstream>
class Chain
{
  public:
    explicit Chain(std::string str);
    void generate();
    void generateGraph();

  private:
    std::vector<Node> nodes;
};

#endif
