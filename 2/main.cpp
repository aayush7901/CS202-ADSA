#include "BinaryTree.hpp"
#include <iostream>

template <class Key, class Value>
void btinp(BinaryTree<Key,Value> a)
{
	int q,x;
	Key y;
	cin>>q;
	while (q--)
	{
		cin>>x;
		if (x==1) //insert
		{
			cin>>y;
			if (a.get(y)!=Value())
				cout<<"Key Already Exists\n";
			else
				a.put(y,y);
		}
		else if (x==2) //delete
		{
			cin>>y;
			if (a.get(y)!=Value())
				a.remove(y);
			else
				cout<<"Key Not Found\n";
		}
		else if (x==3) //find
		{
			cin>>y;
			if (a.get(y)!=Value())
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else if (x==4) //max
			cout<<a.maximum()<<"\n";
		else if (x==5) //min
			cout<<a.minimum()<<"\n";
		else
			cout<<"Enter choices from 1 to 5 only\n";
	}
}

int main(int argc, char *argv[])
{
	string ttype=argv[1],dtype=argv[2];
	if (ttype=="bt")
	{
		if (dtype=="int")
		{
			BinaryTree<int,int> a;
			btinp(a);
		}
		else if (dtype=="string")
		{
			BinaryTree<string,string> a;
			btinp(a);
		}
		else if (dtype=="double")
		{
			BinaryTree<double,double> a;
			btinp(a);
		}
		else if (dtype=="char")
		{
			BinaryTree<char,char> a;
			btinp(a);
		}
		else if (dtype=="long")
		{
			BinaryTree<long long,long long> a;
			btinp(a);
		}
	}
	// else if (ttype=="bst")
	// {
	// 	switch (dtype)
	// 	{
	// 		case "int":
	// 		case "string":
	// 		case "double":
	// 	}
	// }
	// else if (ttype=="avl")
	// {
	// 	switch (dtype)
	// 	{
	// 		case "int":
	// 		case "string":
	// 		case "double":
	// 	}
	// }
	// else if (ttype=="rbt")
	// {
	// 	switch (dtype)
	// 	{
	// 		case "int":
	// 		case "string":
	// 		case "double":
	// 	}
	// }
    return 0;
}
