#include "weightedGraph.hpp"


//==============================================================
// Default Constructor
//==============================================================
template <class T>
WeightedGraph<T>::WeightedGraph() {
    listSize = 0;
}

//==============================================================
// Copy Constructor
//==============================================================
template <class T>
WeightedGraph<T>::WeightedGraph(const WeightedGraph &other) {
    listSize = other.listSize;
}

//==============================================================
// Destructor
//==============================================================
template <class T>
WeightedGraph<T>::~WeightedGraph() {
    coords.clear();
    adjacencyList.clear();
}


//==============================================================
// Assignment operator
//==============================================================
template <class T>
WeightedGraph<T>& WeightedGraph<T>::operator=(const WeightedGraph &other) {
    coords.clear();
    adjacencyList.clear();

    listSize = other.listSize;
    return *this;
}

//==============================================================  dijkstras
// addEdge
//==============================================================
template <class T>
void WeightedGraph<T>::addEdge(const T& u, const T& v, double weight) {
    // u and v are IDs of nodes, so coords[u] = {x, y} and coords[v] = {x, y}
    // adjList[u][v] = weight
    adjacencyList[u][v] = weight;
    
}

//==============================================================
// readFromSTDIN
//==============================================================
template <class T>
WeightedGraph<T> WeightedGraph<T>::readFromSTDIN() {
    int n, m;
    cin >> n >> m;

    WeightedGraph<long> g;
    g.listSize = n;

    for (int i = 0; i < n; i++) {
        T id;
        double x, y;
        cin >> id >> x >> y;
        g.coords[id] = make_pair(x, y);
    }

    for (int i = 0; i < m + 1; i++) {
        string line;
        getline(cin, line); 
        istringstream iss(line);

        T u, v;
        double weight;
        if (iss >> u >> v >> weight) {
            g.addEdge(u, v, weight);
        }
    }
    return g;
}

//==============================================================
// printAdjacencyList
//==============================================================
template <class T>
void WeightedGraph<T>::printAdjacencyList() const {
    for (const auto& [node, neighbors] : adjacencyList) {
        cout << node << ": ";
        for (const auto& [neighbor, weight] : neighbors) {
            cout << " -> (" << neighbor << ", " << weight << ") ";
        }
        cout << std::endl;
    }
}   

template class WeightedGraph<long>;
