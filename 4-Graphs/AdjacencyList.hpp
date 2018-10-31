#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"

/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
class AdjacencyList : public GraphAdjacencyBase {

	int size;

	public:
	AdjacencyList(int vertices);
	~AdjacencyList();
		  	
};  	
#endif /* ifndef ADJACENCY_LIST */
