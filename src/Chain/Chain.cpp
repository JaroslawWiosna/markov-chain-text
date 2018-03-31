#include "Chain.hpp"

Chain::Chain(std::string str) {
    // std::vector<std::string> vec = split(str);
    std::vector<std::string> vec;
    std::string buffer;
    std::stringstream ss(str);
    while (ss >> buffer) {
        vec.push_back(buffer);
    }

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
}

void Chain::generate() {
    auto word = nodes.at(0).word;

    for (int i{}; i < 100; ++i) {
        std::cout << word << " ";

        auto jt = std::find_if(
            nodes.begin(), nodes.end(),
            [&word](const Node &node) -> bool { return node.word == word; });
        if (jt == nodes.end()) {
            return;
        }
        word = jt->getRandom();
    }
    std::cout << std::endl;
}

void Chain::generateGraph() {
    std::string script = "digraph G {";
    script += "\n";

    for (auto &item : nodes) {
        const auto size = std::to_string(item.size());
        for (auto &next : item.map) {
            script += "\"";
            script += item.word;
            script += "\"";
            script += " -> ";
            script += "\"";
            script += next.first;
            script += "\"";
            script += " [label=\"";
            script += std::to_string(next.second);
            script += "/";
            script += size;
            script += "\"];";
            script += "\n";
        }
    }
    script += "}";
    script += "\n";

    std::ofstream out("graph.gv");
    out << script;
    out.close();

    system("dot -Tpng graph.gv -o graph.png");
}
