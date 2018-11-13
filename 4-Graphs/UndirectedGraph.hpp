#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "queue.hpp"

using namespace queuehelp;

/*
* A class to represent an UndirectedGraph
* Subclasses AbstractGraph
*/
class UndirectedGraph : public AbstractGraph
{
	private:
		char mode;
		AdjacencyList *list;
		AdjacencyMatrix *matrix;
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
	  	int degree(int i);
		bool edgeExists(int i, int j);
		int edges();
		int vertices();
		void add(int i, int j);
		void remove(int i, int j);
		void dfsHelp(int state[], int n, int v);
		void dfs();
		void bfs();
		void display();
};

UndirectedGraph :: UndirectedGraph(int vertices, char mode)
{
	this->mode=mode;
	if (mode=='l')
		list= new AdjacencyList(vertices);
	else if (mode=='m')
		matrix= new AdjacencyMatrix(vertices);
	else
		std::cout<<"Please enter l or m as parameter\n";
}

int UndirectedGraph :: degree(int i)
{
	if (mode=='l')
		return list->degree(i);
	else if (mode=='m')
		return matrix->degree(i);
}

bool UndirectedGraph :: edgeExists(int i, int j)
{
	if (mode=='l')
		return list->edgeExists(i,j);
	else if (mode=='m')
		return matrix->edgeExists(i,j);
}

int UndirectedGraph :: edges()
{
	if (mode=='l')
		return (list->edges())/2;
	else if (mode=='m')
		return (matrix->edges())/2;
}

int UndirectedGraph :: vertices()
{
	if (mode=='l')
		return list->vertices();
	else if (mode=='m')
		return matrix->vertices();
}

void UndirectedGraph :: add(int i, int j)
{
	if (mode=='l')
	{
		list->add(i,j);
		list->add(j,i);
	}
	else if (mode=='m')
	{
		matrix->add(i,j);
		matrix->add(j,i);
	}
}

void UndirectedGraph :: remove(int i, int j)
{
	if (mode=='l')
	{
		list->remove(i,j);
		list->remove(j,i);
	}
	else if (mode=='m')
	{
		matrix->remove(i,j);
		matrix->remove(j,i);
	}
}

void UndirectedGraph :: dfsHelp(int state[], int n, int v)
{
	int i;
	std::cout<<v<<" ";
	state[v]=1;
	for (i=0;i<n;i++)
	{
		if (edgeExists(v,i) && state[i]==0)
			dfsHelp(state, n, i);
	}
	state[v]=2;
}


void UndirectedGraph :: dfs()
{
	int i, state[this->vertices()];
	for (i=0;i<(this->vertices());i++)
		state[i]=0;
	for (i=0;i<(this->vertices());i++)
	{
		if (state[i]==0)
			dfsHelp(state,this->vertices(),i);
	}
	std::cout<<"\n";
}

void UndirectedGraph :: bfs()
{
	int i, state[this->vertices()];
	for (i=0;i<(this->vertices());i++)
		state[i]=0;
	queue <int> q;
	q.push(0);
	state[0]=1;
	while (!q.empty())
	{
		int t= q.pop();
		std::cout<<t<<" ";
		state[t]=2;
		for (i=0;i<(this->vertices());i++)
		{
			if (edgeExists(t,i) && state[i]==0)
			{
				q.push(i);
				state[i]=1;
			}
		}
	}
	std::cout<<"\n";
}

void UndirectedGraph :: display()
{
	if (mode=='l')
		list->display();
	else if (mode=='m')
		matrix->display();
}

#endif /* ifndef UNDIRECTED_GRAPH */
