#include "priorityQueue.hpp"

//==============================================================
// Default Constructor
//==============================================================
PriorityQueue::PriorityQueue() {}

//==============================================================
// Copy Constructor
//==============================================================
PriorityQueue::PriorityQueue(const PriorityQueue& other) {
    minHeap = other.minHeap;
    position = other.position;
}

//==============================================================
// Destructor
//==============================================================
PriorityQueue::~PriorityQueue() {
    minHeap.clear();
    position.clear();
}

//==============================================================
// Assignment Operator
//==============================================================
PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this != &other) {
        minHeap = other.minHeap;
        position = other.position;
    }
    return *this;
}

//==============================================================
// Insert
//==============================================================
void PriorityQueue::insert(long nodeId, double priority) {
    if (position.count(nodeId) > 0) {
        throw runtime_error("Node already exists in priority queue");
    }

    minHeap.push_back({nodeId, priority});
    position[nodeId] = minHeap.size() - 1;
    
    heapifyUp(minHeap.size() - 1);
}

//==============================================================
// Extract Min
//==============================================================
pair<long, double> PriorityQueue::extractMin() {
    if (isEmpty()) {
        throw runtime_error("Priority queue is empty");
    }

    pair<long, double> minElement = minHeap[0];

    long lastNodeId = minHeap.back().first;
    minHeap[0] = minHeap.back();
    
    minHeap.pop_back();
    
    position.erase(minElement.first);
    
    if (!isEmpty()) {
        position[minHeap[0].first] = 0;
        heapifyDown(0);
    }

    return minElement;
}

//==============================================================
// Decrease Key 
//==============================================================
void PriorityQueue::decreaseKey(long nodeId, double newPriority) {
    if (position.count(nodeId) == 0) {
        throw runtime_error("Node not found in priority queue");
    }

    int index = position[nodeId];

    if (newPriority >= minHeap[index].second) {
        return;
    }

    minHeap[index].second = newPriority;
    
    heapifyUp(index);
}


void PriorityQueue::printMinHeap() {
    cout << "Priority Queue (Min-Heap):" << endl;
    cout << left << setw(10) << "Index" << setw(10) << "Node ID" << "Priority" << endl;
    cout << "-----------------------------------" << endl;

    for (size_t i = 0; i < minHeap.size(); ++i) {
        cout << left << setw(10) << i 
             << setw(10) << minHeap[i].first 
             << minHeap[i].second << endl;
    }

    cout << "\nNode positions in the heap:" << endl;
    for (const auto& entry : position) {
        cout << "Node " << entry.first << " is at index " << entry.second << endl;
    }
}

