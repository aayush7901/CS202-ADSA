#include "BinaryTree.hpp"
#include "BSTree.hpp"
#include "AVL.hpp"
#include "RBTree.hpp"
#include <iostream>

template <class Key, class Value>
void btinp(BinaryTree<Key,Value>& a)
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
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				a.put(y,gv+1); //increases frequency by 1
			}
			else
				a.put(y,1);  // insert and set value to 1 .. here value is frequency
		}
		else if (x==2) //delete
		{
			cin>>y;
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				if (gv!=1)
					a.put(y,gv-1);
			}
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
void bstinp(BSTree<Key,Value>& a)
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
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				a.put(y,gv+1);
			}
			else
				a.put(y,1);
		}
		else if (x==2) //delete
		{
			cin>>y;
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				if (gv!=1)
					a.put(y,gv-1);
			}
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
void avlinp(AVL<Key,Value>& a)
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
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				a.put(y,gv+1);
			}
			else
				a.put(y,1);
		}
		else if (x==2) //delete
		{
			cin>>y;
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				a.remove(y);
				if (gv!=1)
					a.put(y,gv-1);
			}
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
void rbtinp(RBTree<Key,Value>& a)
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
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				// a.printrbtree();
				// cout<<"a\n";
				a.deleteKey(y);
				// cout<<"b\n";
				// a.printrbtree();
				a.insert(y,gv+1);
				// cout<<"c\n";
			}
			else
				a.insert(y,1);
			// a.printrbtree();
		}
		else if (x==2) //delete
		{
			cin>>y;
			Value gv=a.get(y);
			if (a.get(y)!=Value())
			{
				// cout<<"a\n";
				// a.printrbtree();
				a.deleteKey(y);
				// cout<<"b\n";
				// a.printrbtree();
				if (gv!=1)
					a.insert(y,gv-1);
			}
			else
				cout<<"Key Not Found\n";
			// a.printrbtree();
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
			BinaryTree<string,int> a;
			btinp(a);
		}
		else if (dtype=="double")
		{
			BinaryTree<double,int> a;
			btinp(a);
		}
		else if (dtype=="char")
		{
			BinaryTree<char,int> a;
			btinp(a);
		}
		else if (dtype=="long")
		{
			BinaryTree<long long,int> a;
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
			BSTree<string,int> a;
			bstinp(a);
		}
		else if (dtype=="double")
		{
			BSTree<double,int> a;
			bstinp(a);
		}
		else if (dtype=="char")
		{
			BSTree<char,int> a;
			bstinp(a);
		}
		else if (dtype=="long")
		{
			BSTree<long long,int> a;
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
			AVL<string,int> a;
			avlinp(a);
		}
		else if (dtype=="double")
		{
			AVL<double,int> a;
			avlinp(a);
		}
		else if (dtype=="char")
		{
			AVL<char,int> a;
			avlinp(a);
		}
		else if (dtype=="long")
		{
			AVL<long long,int> a;
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
			RBTree<string,int> a;
			rbtinp(a);
		}
		else if (dtype=="double")
		{
			RBTree<double,int> a;
			rbtinp(a);
		}
		else if (dtype=="char")
		{
			RBTree<char,int> a;
			rbtinp(a);
		}
		else if (dtype=="long")
		{
			RBTree<long long,int> a;
			rbtinp(a);
		}
	}
    return 0;
}
