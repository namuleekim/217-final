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
        // cout << "Adjacency List: " << endl;
        // graph.printAdjacencyList();
        cout << "Press any key to enter a new file" << endl;
        while (true) {
            double x_1, y_1, x_2, y_2;
            cout << "Enter a start coordinate (formatted as 'x y'): ";
            cin >> x_1 >> y_1;
            cout << "Enter an end coordinate (formatted as 'x y'): ";
            cin >> x_2 >> y_2;

            // double shortest = graph.dijkstras();
            cout << "The shortest distance is: " << "shortest" << endl;
        }
    }

    cout << "Thank you for using our program! Exiting..." << endl;

    
    return 0;
}