//=========================================================
// Graph.hpp
// Andrew McCutchan
// 12/18/2024
//=========================================================

#ifndef WEIGHTED_GRAPH_HPP
#define WEIGHTED_GRAPH_HPP


#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include "customexceptions.hpp"
#include "priorityQueue.hpp"
using namespace std;

class WeightedGraph {
    private:
        unordered_map<long, pair<double, double> > coords;
        unordered_map<long, unordered_map<long, pair<double, string> > > adjacencyList;
		int listSize;
    public:
                                WeightedGraph();
                                WeightedGraph(const WeightedGraph &other);
                                ~WeightedGraph();
                WeightedGraph   operator=(const WeightedGraph &other);
                void            addEdge(long u, long v, double weight, const string& location);
		        void            printAdjacencyList() const;
        static  WeightedGraph   readFromSTDIN();

        // get functions
        unordered_map<long, pair<double, double> > getCoords() { return coords; };
                int             getSize() { return listSize; }
};

#endif