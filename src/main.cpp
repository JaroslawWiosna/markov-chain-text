#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include "Node.hpp"
#include "Chain.hpp"

int main() {

    std::cout << "markov-chain-text" << std::endl;
    std::cout << std::endl;

    std::string test = "I am only human after all. I am so tired. I am so "
                       "happy. I am tired. I am so so so so so happy. I do "
                       "love and love and love you all. I love and hate. Apple "
                       "or banana. Apple and banana.";

    std::cout << "Test string is:" << std::endl;
    std::cout << test << std::endl;
    std::cout << std::endl;

    std::cout << "Let's generate something:" << std::endl;

    Chain chain(test);
    for (unsigned i{}; i < 3; ++i) {
        std::cout << "Chain No. " << i + 1 << std::endl;
        chain.generate();
        std::cout << std::endl;
    }

    std::cout << "Here is script for graph:" << std::endl;
    chain.generateGraph();
    std::cout << std::endl;

    return 0;
}
