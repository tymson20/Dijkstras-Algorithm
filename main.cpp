#include <iostream>
#include "graphMatrix.h"

int dijkstraAlgorithm(const Graph& graph, Node* startNode, Node* destinationNode);

int main(void) {
    std::vector<Node> nodes = {{}, {}, {}, {}, {}, {}, {}, {}, {}};
    std::vector<Node*> nodesPointers(nodes.size());
    for (std::size_t i = 0; i < nodes.size(); i++) {
        nodesPointers[i] = &nodes[i];
    }
    //                         1  2  3  4  5  6  7  8  9
    Matrix adjacencyMatrix = {{0, 4, 0, 0, 8, 0, 0, 0, 0}, // 1
                              {4, 0, 3, 0, 0, 0, 0, 0, 0}, // 2
                              {0, 3, 0, 0, 0, 9, 0, 0, 4}, // 3
                              {0, 0, 0, 0, 0, 0, 9, 0, 0}, // 4
                              {8, 0, 0, 0, 0, 0, 8, 9, 0}, // 5
                              {0, 0, 9, 0, 0, 0, 0, 7, 3}, // 6
                              {0, 0, 0, 9, 8, 0, 0, 5, 0}, // 7
                              {0, 0, 0, 0, 9, 7, 5, 0, 0}, // 8
                              {0, 0, 4, 0, 0, 3, 0, 0, 0}};// 9
    GraphMatrix graph1(nodesPointers, adjacencyMatrix);
    int distance = dijkstraAlgorithm(graph1, &nodes[2], &nodes[7]);
    std::cout << "Distance = " << distance << std::endl;
    
    return 0;
}