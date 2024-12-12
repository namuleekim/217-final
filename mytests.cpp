#include <iostream> 
#include "weightedGraph.hpp"
#include "priorityQueue.hpp"
using namespace std;

int main (void) {
    // WeightedGraph g = WeightedGraph::readFromSTDIN();
    // g.printAdjacencyList();

    PriorityQueue queue;
    queue.insert(4256589581, 38.1956);
    queue.print();
    return 0;
}