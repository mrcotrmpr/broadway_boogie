#ifndef NODETYPE_HPP
#define NODETYPE_HPP

class NodeType {
public:
    NodeType() = default;
    NodeType(char tag, int red, int green, int blue, int weight);
    char tag;
    int red;
    int green;
    int blue;
    int weight;
};

#endif // NODETYPE_HPP
