//========================================================
// customexceptions.hpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides names and definitions for the
// exceptions in the customexceptions class.
//========================================================


#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <exception>
using namespace std;

class edge_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Edge/Vertex does not exist in the graph.";
    }
};


#endif 
