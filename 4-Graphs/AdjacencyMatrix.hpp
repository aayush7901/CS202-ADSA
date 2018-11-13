#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {

	int size;
	int **arr;
	public:
		AdjacencyMatrix(int vertices);
		~AdjacencyMatrix();
		bool edgeExists(int i, int j);
		int vertices();
		int edges();
		void add(int i, int j);
		void remove(int i, int j);
		int degree(int i);
		void display();
};

AdjacencyMatrix :: AdjacencyMatrix(int vertices)
{
	int i,j;
	size = vertices;
	arr = new int*[vertices];
	for (i=0;i<vertices;i++)
		arr[i] = new int[vertices];
	for (i=0;i<vertices;i++)
	{
		for (j=0;j<vertices;j++)
			arr[i][j]=0;
	}
}

AdjacencyMatrix :: ~AdjacencyMatrix()
{
	int i;
	for (i=0;i<(this->size);i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

bool AdjacencyMatrix :: edgeExists(int i, int j)
{
	return (arr[i][j]==1);
}

int AdjacencyMatrix :: vertices()
{
	return this->size;
}

int AdjacencyMatrix :: edges()
{
	int i,j,res=0;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			if (arr[i][j]==1)
				res++;
		}
	}
	return res;
}

void AdjacencyMatrix :: add(int i, int j)
{
	arr[i][j]=1;
}

void AdjacencyMatrix :: remove(int i, int j)
{
	arr[i][j]=0;
}

int AdjacencyMatrix :: degree(int i)
{
	int j,res=0;
	for (j=0;j<size;j++)
	{
		if (arr[i][j]==1)
			res++;
		if (arr[j][i]==1)
			res++;
	}
	return res;
}

void AdjacencyMatrix :: display()
{
	int i,j;
	std::cout<<"\n";
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}

#endif /* ifndef ADJACENCY_MATRIX */
