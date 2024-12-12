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

template <typename T>
class WeightedGraph {
    private:
        unordered_map<T, pair<double, double> > coords;
        unordered_map<T, unordered_map<T, double > > adjacencyList;
		int listSize;
    public:
                                    WeightedGraph();
                                    WeightedGraph(const WeightedGraph &other);
                                    ~WeightedGraph();
                WeightedGraph<T>&   operator=(const WeightedGraph &other);
                void                addEdge(const T& u, const T& v, double weight);
		        void                printAdjacencyList() const;
        static  WeightedGraph<T>&   readFromSTDIN();

        // getter functions
        unordered_map<long, pair<double, double> > getCoords() { return coords; };
                int             getSize() { return listSize; }
};

#endif