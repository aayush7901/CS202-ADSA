#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"


/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph {

	GraphAdjacencyBase *base;
		
 	public:

  	/*
   	* Constructor: UndirectedGraph
   	*
   	* Parameters: mode
   	* Used to decide which representation to use
   	* 'm' for AdjacencyMatrix
   	* 'l' for AdjacencyList
   	*/
  	UndirectedGraph(int vertices, char mode);
  	/*
  	* Destructor
  	*/
  	~UndirectedGraph(); 
  	
	};
	
#endif /* ifndef UNDIRECTED_GRAPH */
