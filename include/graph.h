#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include "node.h"

class Graph {
public:
    Graph(const std::vector<Node*>& nodes);
    virtual void addNode(Node* node) = 0;
    virtual void addEdge(Node* startNode, Node* endNode, int egde) = 0;
    virtual void print() const;
    std::size_t size() const { return m_NumberOfNodes; }

protected:
    std::size_t m_NumberOfNodes;
    std::vector<Node*> m_Nodes;
    std::map<Node*, std::size_t> m_Map;
};

#endif // GRAPH_H