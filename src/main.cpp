#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <random>
#include <map>


std::random_device rd{};
std::mt19937 engine{rd()};
std::uniform_int_distribution<int> dist{0, 10000};

std::vector<std::string> split(std::string s) {
    std::vector<std::string> vec;
    std::string buffer;
    std::stringstream ss(s);
    while (ss >> buffer) {
        vec.push_back(buffer);
    }
    return vec;
}

class Node
{
  public:
    unsigned size() {
        unsigned result{};
        for (auto &item : map) {
            result += item.second;
        }
        return result;
    }
    void add(std::string s) {
        map[s]++;
    }
    std::string getRandom() {
        const unsigned size = this->size();
        const unsigned randomIndex = dist(engine) % size;
        std::string result;

        unsigned i{};
        for (auto &item : map) {
            i += item.second;
            if (randomIndex < i) {
                result = item.first;
                break;
            }
        }
        return result;
    }
    std::string word;
    std::map<std::string, unsigned> map;
};


std::vector<Node> show_nodes(std::string s) {
    std::vector<std::string> vec = split(s);
    std::vector<Node> nodes;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        // check if we already have such a word in nodes
        //
        auto jt = std::find_if(
            nodes.begin(), nodes.end(),
            [&it](const Node &node) -> bool { return node.word == *it; });

        if (jt != nodes.end()) {
            if (it + 1 != vec.end()) {
                jt->add(*(it + 1));
            }
        } else {

            Node tmp;
            tmp.word = *it;
            if (it + 1 != vec.end()) {
                tmp.add(*(it + 1));
            }
            nodes.push_back(tmp);
        }
    }


    return nodes;
}

void generate(std::string s) {
    auto nodes = show_nodes(s);

    auto word = nodes.at(0).word;

    for (int i{}; i < 100; ++i) {
        std::cout << word << " ";

        auto jt = std::find_if(
            nodes.begin(), nodes.end(),
            [&word](const Node &node) -> bool { return node.word == word; });

        word = jt->getRandom();
    }
    std::cout << std::endl;
}



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

    for (unsigned i{}; i < 3; ++i) {
        std::cout << "Chain No. " << i+1 << std::endl;
        generate(test);
        std::cout << std::endl;
    }

    return 0;
}
