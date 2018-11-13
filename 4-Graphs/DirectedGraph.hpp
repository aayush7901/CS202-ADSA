#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"

/*
* A class to represent a directed graph.
*/
class DirectedGraph : public AbstractGraph {
	private:
		char mode;
		AdjacencyList *list;
		AdjacencyMatrix *matrix;
	public:
		/*
		 * Constructor: DirectedGraph
		 *
		 * Parameters: mode
		 * Used to decide which representation to use
		 * 'm' for AdjacencyMatrix
		 * 'l' for AdjacencyList
		 */
		DirectedGraph(int vertices, char rep);
		/*
		 * Destructor
		 */
		~DirectedGraph();
		bool edgeExists(int i, int j);
		int edges();
		int vertices();
		void add(int i, int j);
		void remove(int i, int j);
		void dfs(void(*work)(int&));
		void bfs(void(*work)(int&));
		void display();
};

DirectedGraph :: DirectedGraph(int vertices, char rep)
{
	this->mode=rep;
	if (rep=='l')
		list= new AdjacencyList(vertices);
	else if (rep=='m')
		matrix= new AdjacencyMatrix(vertices);
	else
		cout<<"Please enter paramters l or m only\n";
}

bool DirectedGraph :: edgeExists(int i, int j)
{
	if (mode=='l')
		return list->edgeExists();
	else
		return matrix->edgeExists();
}

int DirectedGraph :: edges()
{
	if (mode=='l')
		return list->edges();
	else
		return matrix->edges();
}

int DirectedGraph :: vertices()
{
	if (mode=='l')
		return list->vertices();
	else
		return matrix->vertices();
}

void DirectedGraph :: add(int i, int j)
{
	if (mode=='l')
		list->add(i,j);
	else
		matrix->add(i,j);
}

void DirectedGraph :: remove(int i, int j)
{
	if (mode=='l')
		list->remove(i,j);
	else
		matrix->remove(i,j);
}

void dfsHelp(int state[], int n, int v)
{
	int i;
	cout<<v<<" ";
	state[v]=1;
	for (i=0;i<n;i++)
	{
		if (edgeExists(v,i) && state[i]==0)
			dfsHelp(i);
	}
	state[v]=2;
}

void DirectedGraph :: dfs(void(*work)(int&))
{
	int i, state[this->vertices()];
	for (i=0;i<(this->vertices());i++)
		state[i]=0;
	for (i=0;i<(this->vertices());i++)
	{
		if (state[i]==0)
			dfsHelp(state,this->vertices(),i);
	}
	cout<<"\n";
}

void DirectedGraph :: bfs(void(*work)(int&))
{
	int i, state[this->vertices()];
	for (i=0;i<(this->vertices());i++)
		state[i]=0;
	queue <int> q;
	q.push_back(0);
	state[0]=1;
	while (!q.isEmpty())
	{
		int t= q.pop();
		cout<<t<<" ";
		state[t]=2;
		for (i=0;i<(this->size);i++)
		{
			if (edgeExists(t,i) && state[i]==0)
			{
				q.push_back(i);
				state[i]=1;
			}
		}
	}
	cout<<"\n";
}

void DirectedGraph :: display()
{
	if (mode=='l')
		list->display();
	else
		matrix->display();
}

#endif /* ifndef DIRECTED_GRAPH */
