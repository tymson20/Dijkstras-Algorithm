#include <iostream>
#include "graph.h"

Graph::Graph(const std::vector<Node*>& nodes) {
    m_NumberOfNodes = nodes.size();
    m_Nodes = nodes;
    for (std::size_t i = 0; i < size(); i++) {
        m_Map[m_Nodes[i]] = i;
    }
}

void Graph::print() const {
    for (std::size_t i = 0; i < m_NumberOfNodes; i++) {
        std::cout << "Node: (Id: " << m_Nodes[i]->getId() << "), Node address: " << m_Nodes[i] << ", Map index: " << m_Map.at(m_Nodes[i]) << std::endl;
    }
}