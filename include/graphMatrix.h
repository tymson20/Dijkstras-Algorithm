#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "graph.h"

class GraphMatrix : public Graph {
public:
    GraphMatrix(const std::vector<Node*>& nodes, const std::vector<std::vector<int>>& adjacencyMatrix) : 
        Graph(nodes), m_AdjacencyMatrix(adjacencyMatrix) {}
    void addNode(Node* node) override;
    void addEdge(Node* startNode, Node* endNode, int edge) override;
    void print() const override;

private:
    std::vector<std::vector<int>> m_AdjacencyMatrix;
};

#endif // GRAPH_MATRIX_H