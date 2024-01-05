#include <iostream>
#include <algorithm>

#include "..\include\graphMatrix.h"

void GraphMatrix::addNode(Node* node) {
    m_Nodes.push_back(node);
    m_Map[node] = size();
    m_NumberOfNodes++;

    for (auto& row : m_AdjacencyMatrix) {
        row.push_back(0);
    }
    m_AdjacencyMatrix.emplace_back(std::move(std::vector<int>(size())));
}

void GraphMatrix::addEdge(Node* startNode, Node* endNode, int edge) {
    if (std::find(m_Nodes.cbegin(), m_Nodes.cend(), startNode) == m_Nodes.cend() || 
    std::find(m_Nodes.cbegin(), m_Nodes.cend(), endNode) == m_Nodes.cend()) {
        std::cout << "Invalid Node pointer!" << std::endl;
        return;
    }
    std::size_t startIdx = m_Map[startNode], endIdx = m_Map[endNode];
    m_AdjacencyMatrix[startIdx][endIdx] = edge;
    m_AdjacencyMatrix[endIdx][startIdx] = edge;
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