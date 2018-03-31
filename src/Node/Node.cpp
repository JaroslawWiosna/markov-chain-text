#include "Node.hpp"
unsigned Node::size() {
    unsigned result{};
    for (auto &item : map) {
        result += item.second;
    }
    return result;
}
void Node::add(std::string s) {
    map[s]++;
}
std::string Node::getRandom() {
    const unsigned size = this->size();
    const unsigned randomIndex = Random::randomNumber() % size;
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
