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
// idFromCoords
// finds and returns id of node by searching coodrs for coordinate pair
//==============================================================
template <class T>
T WeightedGraph<T>::idFromCoords(pair<double, double> node) {
    T nodeId = -1; // -1 does not exist as id in coords
    for (const auto& [id, coord] : coords) {                          
        if (node.first == coord.first && node.second == coord.second) {
            nodeId = id;
        }
    }
    return nodeId;
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
        // cout << id << ", " << x << ", " << y << endl; //for debugging
        g.coords[id] = make_pair(x, y);
    }

    for (int i = 0; i < m + 1; i++) {
        string line;
        getline(file, line);
        istringstream street(line);

        T u, v;
        double weight;
        if (street >> u >> v >> weight) {
            // cout << u << ", " << v << ", " << weight << endl; //for debugging
            g.addEdge(u, v, weight);
        }  
    }
    file.close();
    return g;
}

// //==============================================================
// // Dijkstra's (coord)
// //==============================================================
// template <class T>
// vector<pair<double, double> > WeightedGraph<T>::dijkstras(pair<double, double> start, pair<double, double> end) {
//     pair<double, double> seNodes = findNode(start, end);

//     PriorityQueue<T> pq;
//     unordered_map<T, T> parent;
//     unordered_map<T, double> distance;

//     for (const auto& [node, _] : adjacencyList) {
//         distance[node] = numeric_limits<double>::infinity();
//         parent[node] = -1;
//         pq.insert(node, distance[node]);
//     }

//     pq.decreaseKey(seNodes.first, 0);
//     distance[seNodes.first] = 0;
//     while (!pq.isEmpty()) {
//         auto [current, currentDist] = pq.extractMin();
        
//     }    
// }

//==============================================================
// Dijkstra's (id)
//==============================================================
template <class T>
vector<pair<double, double> > WeightedGraph<T>::dijkstras(const T& sourceNode, const T& endNode) {
    vector<pair<double, double> > spath; // vector that will store shortest path

    PriorityQueue<T> pq; // Min-priority que
    //unordered_map<T, T> parent; // Holds parent value of node
    //unordered_map<T, double> distance; // Holds distance from source

    // Hold parents and distance from source.
    unordered_map<T, pair<T, double> > S;

    // Initialization
    for (const auto& [node, _] : adjacencyList) {
        // S[node].first = parent
        // S[node].second = shortest path estimate from source (node.d)
        S[node].first = -1;
        S[node].second = numeric_limits<double>::infinity();
        pq.insert(node, S[node].second); // Fill pq
    }

    
    S[sourceNode].second = 0;// s.d = 0
    pq.decreaseKey(sourceNode, S[sourceNode].second);

    //Loop for shortest path
    while (!pq.isEmpty()) {
        auto [u, u_d] = pq.extractMin(); // u = current node
        double v_d; // Holds v.d
        // S U {u}
        for (const auto& [v, _] : adjacencyList[u]) {
            double w_uv = adjacencyList[u][v]; // weight of edge u->v
            v_d = S[v].second;
            // If v.d > u.d + w(u,v), "RELAX"
            if (v_d > S[u].second + w_uv) {
                S[v].second = S[u].second + w_uv; // v.d = u.d + w(u,v)
                S[v].first = u; // v.p = u
            }
            // If RELAX decreased v.d
            if (S[v].second < v_d) {
                pq.decreaseKey(v, S[v].second);
            }
        }
    }

    //Test output
    cout << "\n>> Output S for source " << sourceNode << ": " << endl;
    for (const auto& [id, pd] : S) {
        cout << "-node: "  << id;
        cout << "\n parent: " << pd.first << 
        "\n node.d: " << pd.second << endl;
        cout << "------------------------------" << endl;
    }
    

    return spath;
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
        cout << endl;
    }
}   

//==============================================================
// findNode
//==============================================================
template <class T>
pair<double, double> WeightedGraph<T>::findNode(pair<double, double> start, pair<double, double> end) {
    T startNode = -1, endNode = - 1;
    for (const auto& [id, coord] : coords) {                          
        if (start.first == coord.first && start.second == coord.second) {
            startNode = id;
        }

        if (end.first == coord.first && end.second == coord.second) {
            endNode = id;
        }
    }

    if (startNode == -1 || endNode == -1) {
        throw invalid_argument("Start or end coord not found");
    }

    return make_pair(startNode, endNode);
}


template class WeightedGraph<long>;
template class WeightedGraph<long long>; // for windows
template class WeightedGraph<int>;