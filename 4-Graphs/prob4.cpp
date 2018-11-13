#include <iostream>
#include "UndirectedGraph.hpp"
using namespace std;

#define MAX 1000
#define NIL -1
#define INF 1000000000
int v;
int adj[MAX][MAX];
int pre[MAX];
int pathlength[MAX];
int status[MAX];

void findPath(int s, int v)
{
	int i,u;
	int path[MAX];
	int shortdist=0;
	int count=0;
	while (v!=s)
	{
		count++;
		path[count]=v;
		u=pre[v];
		shortdist+=adj[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	cout<<"The path is: ";
	for (i=count;i>1;i--)
		cout<<path[i]+1<<"− > ";		// 1 added to change to 1 index from 0 index
	cout<<path[1]+1<<"\n";
	cout<<"Total Time is: "<<shortdist<<"\n";
}

int min_temp()
{
	int i;
	int min=INF;
	int k=NIL;
	for (i=0;i<v;i++)
	{
		if (status[i]==0 && pathlength[i]<min)
		{
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}

void dijkstra(int s)
{
	int i,current;
	for (i=0;i<v;i++)
	{
		pre[i]=NIL;
		pathlength[i]=INF;
		status[i]=0;
	}
	pathlength[s]=0;
	while (1)
	{
		current=min_temp();
		if (current==NIL)
			return;
		status[current]=1;
		for (i=0;i<v;i++)
		{
			if (adj[current][i]!=0 && status[i]==0)
			{
				if (pathlength[current]+adj[current][i] < pathlength[i])
				{
					pre[i]=current;
					pathlength[i]=pathlength[current]+adj[current][i];
				}
			}
		}
	}
}

int main()
{
	int e,i,s,d,wt;
	cin>>v>>e;
	for (i=0;i<e;i++)
	{
		cin>>s>>d>>wt;
		s--;d--;		// change to 0 index
		adj[s][d]=wt;
	}
	dijkstra(0);
	if (pathlength[v-1]==INF)
		cout<<"No way to go to "<<v<<"th class\n";
	else
		findPath(0,v-1);
	return 0;
}
