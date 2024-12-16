mytests: weightedGraph.o priorityQueue.o mytests.o
	g++ -o mytests weightedGraph.o priorityQueue.o mytests.o

weightedGraph.o: weightedGraph.cpp weightedGraph.hpp
	g++ -c weightedGraph.cpp

priorityQueue.o: priorityQueue.cpp priorityQueue.hpp
	g++ -c priorityQueue.cpp

mytests.o: mytests.cpp weightedGraph.hpp
	g++ -c mytests.cpp

clean:
	rm -f *.o mytests