#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"

/*
* A class to represent a directed graph.
*/
class DirectedGraph : AbstractGraph {
	
	GraphAdjacencyBase *base;
	
	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep);
	/*
	 * Destructor
	 */
	~DirectedGraph();
		
};

#endif /* ifndef DIRECTED_GRAPH */
