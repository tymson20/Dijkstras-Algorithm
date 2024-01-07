#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include "node.h"

using Edge = int;


class Graph {
public:
    Graph(const std::vector<Node*>& nodes);

    virtual void addNode(Node* node);
    bool isNodeBelong(Node* node) const;

    virtual void addEdge(Node* startNode, Node* endNode, Edge edge) = 0;
    virtual Edge getEdge(Node* startNode, Node* endNode) const = 0;

    std::vector<Node*> getNodes() const { return m_Nodes; }
    virtual std::vector<Node*> getNeighbours(Node* node) const = 0;

    std::size_t size() const { return m_NumberOfNodes; }

    virtual void print() const;

protected:
    std::size_t m_NumberOfNodes;
    std::vector<Node*> m_Nodes;
    std::map<Node*, std::size_t> m_Map;
};

#endif // GRAPH_H