#include <iostream>
#include <fstream>
#include "UndirectedGraph.hpp"
using namespace std;

void printConnected(UndirectedGraph& g)
{
	int i, v=g.vertices();
	int visited[v];
	for (i=0;i<v;i++)
		visited[i]=0;
	int compnum=1;
	freopen("output2.out","w",stdout);
	for (i=0;i<v;i++)
	{
		if (visited[i]==0)
		{
			cout<<"Connected Component "<<compnum<<": ";
			g.dfsHelp(visited,v,i);
			cout<<"\n";
			compnum++;
		}
	}
}

int main()
{
	int i,v,e,s,d;
	ifstream f("input2.in");
	f>>v>>e;
	UndirectedGraph g(v,'l');
	for (i=0;i<e;i++)
	{
		f>>s>>d;
		g.add(s,d);
	}
	printConnected(g);
	return 0;
}
