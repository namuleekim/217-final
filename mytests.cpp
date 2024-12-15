#include <iostream> 
#include "weightedGraph.hpp"
#include "priorityQueue.hpp"
using namespace std;

int main (void) {
    WeightedGraph<long> graph;
    
    while (true) {
        string filename;
        cout << "Enter a file or 'q' to quit: ";
        cin >> filename;

        if (filename == "q") {
            cout << "Exiting program." << endl;
            break;
        }

        
        try {
            graph = WeightedGraph<long>::readFromFile(filename);
            cout << "Graph loaded successfully from " << filename << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << ". Try running again with correct graph." << endl;
            break; 
        }

        while (true) {
            double x_1, y_1, x_2, y_2;
            cout << "Enter a start coordinate (formatted as 'x y') or 'q' to quit: ";
            cin >> x_1 >> y_1;
            cout << "Enter an end coordinate (formatted as 'x y') or 'q' to quit: ";
            cin >> x_2 >> y_2;

            pair<double, double> start = make_pair(x_1, y_1);
            pair<double, double> end = make_pair(x_2, y_2);
        

            
            
        }
    }

    
    // cout << "Thank you for using our program! Exiting..." << endl;
    return 0;
}