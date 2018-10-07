#include "BinaryTree.hpp"
#include "BSTree.hpp"
#include "AVL.hpp"
#include "RBTree.hpp"
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

template <class Key, class Value>
void bstinp(BSTree<Key,Value> a)
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

template <class Key, class Value>
void avlinp(AVL<Key,Value> a)
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

template <class Key, class Value>
void rbtinp(RBTree<Key,Value> a)
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
				a.insert(y,y);
		}
		else if (x==2) //delete
		{
			cin>>y;
			if (a.get(y)!=Value())
				a.deleteKey(y);
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
	else if (ttype=="bst")
	{
		if (dtype=="int")
		{
			BSTree<int,int> a;
			bstinp(a);
		}
		else if (dtype=="string")
		{
			BSTree<string,string> a;
			bstinp(a);
		}
		else if (dtype=="double")
		{
			BSTree<double,double> a;
			bstinp(a);
		}
		else if (dtype=="char")
		{
			BSTree<char,char> a;
			bstinp(a);
		}
		else if (dtype=="long")
		{
			BSTree<long long,long long> a;
			bstinp(a);
		}
	}
	else if (ttype=="avl")
	{
		if (dtype=="int")
		{
			AVL<int,int> a;
			avlinp(a);
		}
		else if (dtype=="string")
		{
			AVL<string,string> a;
			avlinp(a);
		}
		else if (dtype=="double")
		{
			AVL<double,double> a;
			avlinp(a);
		}
		else if (dtype=="char")
		{
			AVL<char,char> a;
			avlinp(a);
		}
		else if (dtype=="long")
		{
			AVL<long long,long long> a;
			avlinp(a);
		}
	}
	else if (ttype=="rbt")
	{
		if (dtype=="int")
		{
			RBTree<int,int> a;
			rbtinp(a);
		}
		else if (dtype=="string")
		{
			RBTree<string,string> a;
			rbtinp(a);
		}
		else if (dtype=="double")
		{
			RBTree<double,double> a;
			rbtinp(a);
		}
		else if (dtype=="char")
		{
			RBTree<char,char> a;
			rbtinp(a);
		}
		else if (dtype=="long")
		{
			RBTree<long long,long long> a;
			rbtinp(a);
		}
	}
    return 0;
}
