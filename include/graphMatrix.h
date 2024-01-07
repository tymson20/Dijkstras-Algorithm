#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "graph.h"

using Matrix = std::vector<std::vector<Edge>>;

class GraphMatrix : public Graph {
public:
    GraphMatrix(const std::vector<Node*>& nodes, const Matrix& adjacencyMatrix) : 
        Graph(nodes), m_AdjacencyMatrix(adjacencyMatrix) {}

    void addNode(Node* node);

    void addEdge(Node* startNode, Node* endNode, int edge) override;
    Edge getEdge(Node* startNode, Node* endNode) const override;

    Matrix getMatrix() const { return m_AdjacencyMatrix; }

    std::vector<Node*> getNeighbours(Node* node) const override;

    void print() const override;

private:
    Matrix m_AdjacencyMatrix;
};

#endif // GRAPH_MATRIX_H