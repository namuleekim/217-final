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
}


//==============================================================
// Assignment operator
//==============================================================
template <class T>
WeightedGraph<T>& WeightedGraph<T>::operator=(const WeightedGraph &other) {
    listSize = other.listSize;
    return *this;
}

//==============================================================  dijkstras
// addEdge
//==============================================================
template <class T>
void WeightedGraph<T>::addEdge(const T& u, const T& v, double weight) {
    // u and v are IDs of nodes, so coords[u] = {x, y} and coords[v] = {x, y}
    // adjList[u][v] = pair ( weight , location name if one provided )
    adjacencyList[u][v] = weight;
}

//==============================================================
// readFromSTDIN
//==============================================================
template <class T>
WeightedGraph<T>& WeightedGraph<T>::readFromSTDIN() {
    int n, m;
    cin >> n >> m;

    WeightedGraph<long> g;
    g.listSize = n;

    for (int i = 0; i < n; i++) {
        long long id;
        double x, y;
        cin >> id >> x >> y;
        g.coords[id] = make_pair(x, y);
    }

    for (int i = 0; i < m; i++) {
        long long u, v;
        double weight;

        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }
    return g;
}

//==============================================================
// printAdjacencyList
//==============================================================
template <class T>
void WeightedGraph<T>::printAdjacencyList() const {
    for (const auto& node : adjacencyList) {
        long u = node.first;
        cout << "Vertex " << u << ": ";

        bool first = true; 
        for (const auto& neighbor : node.second) {
            long v = neighbor.first;
            double weight = neighbor.second.first;
            const string& roadName = neighbor.second.second;

            if (!first)
                cout << ", ";
            first = false;

            cout << "("<< v << ", " << weight;
            if (!roadName.empty())
                cout << ", " << roadName;
            cout << ")";
        }

        cout << endl;
    }
}   
