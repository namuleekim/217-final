#include "weightedGraph.hpp"


//==============================================================
// Default Constructor
//==============================================================
WeightedGraph::WeightedGraph() {
    listSize = 0;
}

//==============================================================
// Copy Constructor
//==============================================================
WeightedGraph::WeightedGraph(const WeightedGraph &other) {
    listSize = other.listSize;
}

//==============================================================
// Destructor
//==============================================================
WeightedGraph::~WeightedGraph() {
}


//==============================================================
// Assignment operator
//==============================================================
WeightedGraph WeightedGraph::operator=(const WeightedGraph &other) {
    listSize = other.listSize;
    return *this;
}

//==============================================================  dijkstras
// addEdge
//==============================================================
void WeightedGraph::addEdge(long u, long v, double weight, const string& location) {
    // u and v are IDs of nodes, so coords[u] = {x, y} and coords[v] = {x, y}
    // adjList[u][v] = pair ( weight , location name if one provided )
    adjacencyList[u][v] = make_pair(weight, location);
}

//==============================================================
// readFromSTDIN
//==============================================================
WeightedGraph WeightedGraph::readFromSTDIN() {
    int n, m;
    cin >> n >> m;

    WeightedGraph g;
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
        string location;

        cin >> u >> v >> weight;

        if (cin.peek() == '\n') {
        location = "";  
        } else {
            cin.ignore();  
            getline(cin, location);
        }
            g.addEdge(u, v, weight, location);
        }

    return g;
}

//==============================================================
// printAdjacencyList
//==============================================================
void WeightedGraph::printAdjacencyList() const {
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
