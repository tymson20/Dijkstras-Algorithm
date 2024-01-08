#include <set>
#include <limits>
#include <algorithm>
#include <iostream>  // delete
#include "graphMatrix.h"

int dijkstraAlgorithm(const Graph& graph, Node* startNode, Node* destinationNode) {
    std::vector<Node*> nodes = graph.getNodes();
    std::map<Node*, int> distances;
    for (Node* node : nodes) {
        distances[node] = std::numeric_limits<int>::max();
    }
    distances[startNode] = 0;
    std::set<Node*> unvisitedSet(nodes.cbegin(), nodes.cend());
    Node* currentNode = startNode;

    while (true) {
        std::cout << currentNode->getId() << " ";
        std::vector<Node*> neighbours = graph.getNeighbours(currentNode);
        for (auto neighbour : neighbours) {
            if (unvisitedSet.find(neighbour) != unvisitedSet.cend()) {
                int distance = distances[currentNode] + graph.getEdge(currentNode, neighbour);
                if (distance < distances[neighbour]) distances[neighbour] = distance;
            }
        }
        unvisitedSet.erase(currentNode);
        auto compareDistance = [&distances](Node* const node1, Node* const node2) {
            return distances[node1] < distances[node2];
        };
        Node* nearestNode = nullptr;
        if (unvisitedSet.find(destinationNode) == unvisitedSet.cend()) {
            // Algorithm reached destination node.
            return distances[destinationNode];
        }
        else {
            nearestNode = *std::min_element(unvisitedSet.cbegin(), unvisitedSet.cend(), compareDistance);
            if (distances[nearestNode] == std::numeric_limits<int>::max()) {
                // There is no connection between nodes.
                return -1;
            }
            else currentNode = nearestNode;
        }
    }
    
}