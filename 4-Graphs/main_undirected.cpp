#include <iostream>
#include "UndirectedGraph.hpp"

using namespace std;

int main()
{
	char ch;
	int choice,v,i,j;
	cout<<"Enter l for list and m for matrix\n";
	cin>>ch;
	cout<<"Enter number of vertices\n";
	cin>>v;
	UndirectedGraph g(v,ch);
	while(1)
	{
		cout<<"\n1.Add Edge\n2.Remove Edge\n3.Display\n4.Edges\n5.DFS\n6.BFS\n7.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case(1):cout<<"\nEnter src and dest: ";
					cin>>i>>j;
					g.add(i,j);
					break;
			case(2):cout<<"\nEnter src and dest: ";
					cin>>i>>j;
					g.remove(i,j);
					break;
			case(3):g.display();
					break;
			case(4):cout<<"\nNumber of edges: "<<g.edges()<<"\n";
					break;
			case(5):g.dfs();
					break;
			case(6):g.bfs();
					break;
			case(7):exit(0);
			default: cout << "\nEnter correct option\n";
		}
	}
	cout<<"\n";
	return 0;
}
