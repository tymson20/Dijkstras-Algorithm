#include <iostream>
#include "graphMatrix.h"

void GraphMatrix::addNode(Node* node) {
    Graph::addNode(node);

    for (auto& row : m_AdjacencyMatrix) {
        row.push_back(0);
    }
    m_AdjacencyMatrix.emplace_back(std::move(std::vector<int>(size())));
}

void GraphMatrix::addEdge(Node* startNode, Node* endNode, int edge) {
    if (!isNodeBelong(startNode) || !isNodeBelong(endNode)) {
        std::cout << "Invalid Node pointer!" << std::endl;
        return;
    }
    std::size_t startIdx = m_Map[startNode], endIdx = m_Map[endNode];
    m_AdjacencyMatrix[startIdx][endIdx] = edge;
    m_AdjacencyMatrix[endIdx][startIdx] = edge;
}

Edge GraphMatrix::getEdge(Node* startNode, Node* endNode) const {
    if (!isNodeBelong(startNode) || !isNodeBelong(endNode)) {
        std::cout << "Invalid Node pointer!" << std::endl;
        return -1;
    }
    std::size_t startIdx = m_Map.at(startNode), endIdx = m_Map.at(endNode);
    return m_AdjacencyMatrix[startIdx][endIdx];
}

std::vector<Node*> GraphMatrix::getNeighbours(Node* node) const {
    if (!isNodeBelong(node)) {
        std::cout << "Invalid Node pointer!" << std::endl;
        return std::vector<Node*>(1, 0);
    }
    std::size_t nodeIdx = m_Map.at(node);
    std::vector<Node*> neighbours;
    const std::vector<Edge>& row = m_AdjacencyMatrix[nodeIdx];
    for (std::size_t i = 0; i < size(); i++) {
        if (row[i] > 0) neighbours.push_back(m_Nodes[i]);
    }
    return neighbours;
}

void GraphMatrix::print() const {
    Graph::print();
    for (auto row : m_AdjacencyMatrix) {
        for (std::size_t i = 0; i < size(); i++) {
            std::cout << row[i] << " ";
        }
        std::cout << std::endl;
    }
}