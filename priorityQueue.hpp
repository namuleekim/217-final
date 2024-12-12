#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <iomanip>
using namespace std;

class PriorityQueue {
    private:
        vector<pair<long, double> > minHeap;
        unordered_map<long, int> position;

        // helpers for maintaining heap property when adding or deleting
        void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            
            if (minHeap[parentIndex].second > minHeap[index].second) {
                swap(minHeap[parentIndex], minHeap[index]);
                
                position[minHeap[parentIndex].first] = parentIndex;
                position[minHeap[index].first] = index;
                
                index = parentIndex;
            } 
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = minHeap.size();
        while (true) {
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && 
                minHeap[leftChild].second < minHeap[smallest].second) {
                smallest = leftChild;
            }

            if (rightChild < size && 
                minHeap[rightChild].second < minHeap[smallest].second) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(minHeap[index], minHeap[smallest]);
                
                position[minHeap[index].first] = index;
                position[minHeap[smallest].first] = smallest;
                
                index = smallest;
            } 
            else {
                break;
            }
        }
    }

    public:
                            PriorityQueue();
                            PriorityQueue(const PriorityQueue& other);
                            ~PriorityQueue();
        PriorityQueue&      operator=(const PriorityQueue &other);
        void                insert(long nodeId, double priority);
        pair<long, double>  extractMin();
        void                decreaseKey(long nodeId, double newPriority);
        void                printMinHeap();
        
        bool                isEmpty() const { return minHeap.empty(); }
        int                 size() const { return minHeap.size(); }
};

#endif