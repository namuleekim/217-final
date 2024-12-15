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
WeightedGraph<T>::WeightedGraph(const WeightedGraph<T> &other) {
    listSize = other.listSize;
    coords = other.coords;
    adjacencyList = other.adjacencyList;
}

//==============================================================
// Destructor
//==============================================================
template <class T>
WeightedGraph<T>::~WeightedGraph() {}

//==============================================================
// Assignment operator
//==============================================================
template <class T>
WeightedGraph<T>& WeightedGraph<T>::operator=(const WeightedGraph<T> &other) {
    coords = other.coords;
    adjacencyList = other.adjacencyList;
    listSize = other.listSize;
    return *this;
}

//============================================================== 
// addEdge
//==============================================================
template <class T>
void WeightedGraph<T>::addEdge(const T& u, const T& v, double weight) {
    adjacencyList[u][v] = weight;
    
}

//============================================================== 
// edgeIn
//==============================================================
template <class T>
bool WeightedGraph<T>::edgeIn(const T& u, const T& v) {
    return adjacencyList[u].find(v) != adjacencyList[u].end();
}

//==============================================================  
// addVertex
//==============================================================
template <class T>
void WeightedGraph<T>::addVertex(const T& id, double x, double y) {
    coords[id] = make_pair(x, y);
}

//==============================================================
// readFromSTDIN
//==============================================================
template <class T>
WeightedGraph<T> WeightedGraph<T>::readFromSTDIN() {
    int n, m;
    cin >> n >> m;

    WeightedGraph<T> g;
    g.listSize = n;

    for (int i = 0; i < n; i++) {
        T id;
        double x, y;
        cin >> id >> x >> y;
        g.addVertex(id, x, y);
    }

    for (int i = 0; i < m + 1; i++) {
        string line;
        getline(cin, line);
        istringstream street(line);

        T u, v;
        double weight;
        if (street >> u >> v >> weight) {
            g.addEdge(u, v, weight);
        }  
    }
    return g;
}

//==============================================================
// readFromFile
//==============================================================
template <class T>
WeightedGraph<T> WeightedGraph<T>::readFromFile(const string& filename) {
    int n, m;
    ifstream file(filename);

    if (!file) {
        throw runtime_error("file not found");
    }

    file >> n >> m;
    WeightedGraph<T> g;
    g.listSize = n;

    for (int i = 0; i < n; i++) {
        T id;
        double x, y;
        file >> id >> x >> y;
        g.coords[id] = make_pair(x, y);
    }

    for (int i = 0; i < m + 1; i++) {
        string line;
        getline(file, line);
        istringstream street(line);

        T u, v;
        double weight;
        if (street >> u >> v >> weight) {
            g.addEdge(u, v, weight);
        }  
    }
    file.close();
    return g;
}

//==============================================================
// Dijkstra's
//==============================================================
// template <class T>
// vector<pair<double, double> > WeightedGraph<T>::dijkstras(pair<double, double> start, pair<double, double> end) {
   
// }

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
        cout << endl;
    }
}   

//==============================================================
// findClosestNode
//==============================================================


template class WeightedGraph<long>;
template class WeightedGraph<int>;