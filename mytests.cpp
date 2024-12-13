#include <iostream> 
#include "weightedGraph.hpp"
#include "priorityQueue.hpp"
using namespace std;

int main (void) {
    

    while (true) {
        string filename;
        cout << "Enter file: ";
        cin >> filename;
        if (filename == "q") {
            break;
        }
        WeightedGraph<long> graph = WeightedGraph<long>::readFromFile(filename);
        cout << "Adjacency List: " << endl;
        graph.printAdjacencyList();

        cout << "Press any key to enter a new file" << endl;
        while (true) {
            

            double x, y;
            cout << "enter coords: ";
            cin >> x >> y;
            make_pair(x, y);
        }
    }

    
    return 0;
}