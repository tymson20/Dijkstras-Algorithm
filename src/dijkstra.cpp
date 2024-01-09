#include <set>
#include <limits>
#include <algorithm>
#include "graphMatrix.h"

std::vector<Node*> dijkstraAlgorithm(const Graph& graph, Node* startNode, Node* destinationNode, int* cost) {
    std::vector<Node*> nodes = graph.getNodes();
    std::map<Node*, int> distances;
    std::map<Node*, Node*> previous;
    for (Node* node : nodes) {
        distances[node] = std::numeric_limits<int>::max();
        previous[node] = NULL;
    }
    distances[startNode] = 0;
    std::set<Node*> unvisitedSet(nodes.cbegin(), nodes.cend());
    Node* currentNode = startNode;

    while (true) {
        std::vector<Node*> neighbours = graph.getNeighbours(currentNode);
        for (auto neighbour : neighbours) {
            if (unvisitedSet.find(neighbour) != unvisitedSet.cend()) {
                int distance = distances[currentNode] + graph.getEdge(currentNode, neighbour);
                if (distance < distances[neighbour]) {
                    distances[neighbour] = distance;
                    previous[neighbour] = currentNode;
                }
            }
        }
        unvisitedSet.erase(currentNode);
        auto compareDistance = [&distances](Node* const node1, Node* const node2) {
            return distances[node1] < distances[node2];
        };
        Node* nearestNode = nullptr;
        if (currentNode == destinationNode) {
            // Algorithm reached destination node.
            std::vector<Node*> shortestPathReversed = {currentNode};
            while (currentNode != startNode) {
                Node* previousNode = previous[currentNode];
                shortestPathReversed.push_back(previousNode);
                currentNode = previousNode;
            }
            *cost = distances[destinationNode];
            std::vector<Node*> shortestPath(shortestPathReversed.rbegin(), shortestPathReversed.rend());
            return shortestPath;
        }
        else {
            nearestNode = *std::min_element(unvisitedSet.cbegin(), unvisitedSet.cend(), compareDistance);
            if (distances[nearestNode] == std::numeric_limits<int>::max()) {
                // There is no connection between nodes.
                *cost = -1;
                return {};
            }
            else currentNode = nearestNode;
        }
    }
    
}