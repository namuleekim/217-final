#include <iostream> 
#include "weightedGraph.hpp"
#include "priorityQueue.hpp"
using namespace std;

int main (void) {
    WeightedGraph<long> g = WeightedGraph<long>::readFromSTDIN();
    g.printAdjacencyList();

    auto coords = g.getCoords()[3531016709];
    

    return 0;
}