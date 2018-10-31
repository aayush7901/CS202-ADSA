#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {
	
	int size;

	public:
		AdjacencyMatrix(int vertices);
		~AdjacencyMatrix();
};

#endif /* ifndef ADJACENCY_MATRIX */
