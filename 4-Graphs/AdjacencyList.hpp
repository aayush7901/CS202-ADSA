#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"

class AdjListNode
{
	public:
		int val;
		AdjListNode();
		AdjListNode(int value);
		AdjListNode* next;
};

/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
class AdjacencyList : public GraphAdjacencyBase {
	private:
		AdjListNode **arr;
		int size;
	public:
		AdjacencyList(int vertices);
		~AdjacencyList();
		bool edgeExists(int i, int j);
		int vertices();
		int edges();
		void add(int i, int j);
		void remove(int i, int j);
		int degree(int i);
		void display();
};

AdjListNode :: AdjListNode()
{
	this->val=0;
}

AdjListNode :: AdjListNode(int val)
{
	this->val=val;
}

AdjacencyList :: AdjacencyList(int vertices)
{
	int i,j;
	this->size=vertices;
	arr= new AdjListNode*[vertices];
	for (i=0;i<vertices;i++)
		arr[i]= NULL;
}

AdjacencyList :: ~AdjacencyList()
{
	int i, vertices = this->size;
	AdjListNode *tmp,*nxt;
	for (i=0;i<vertices;i++)
	{
		tmp=arr[i];
		arr[i]=NULL;
		while (tmp!=NULL)
		{
			nxt=tmp->next;
			delete tmp;
			tmp=nxt;
		}
		delete[] arr;
	}
}

bool AdjacencyList :: edgeExists(int i, int j)
{
	AdjListNode *tmp = arr[i];
	while (tmp!=NULL)
	{
		if (tmp->val == j)
			return true;
		tmp=tmp->next;
	}
	return false;
}

int AdjacencyList :: vertices()
{
	return this->size;
}

int AdjacencyList :: edges()
{
	int i, res=0;
	AdjListNode *tmp;
	for (i=0;i<(this->size);i++)
	{
		tmp=arr[i];
		while (tmp!=NULL)
		{
			res++;
			tmp=tmp->next;
		}
	}
	return res;
}

void AdjacencyList :: add(int i, int j)
{
	AdjListNode *tmp=arr[i];
	arr[i]= new AdjListNode(j);
	(arr[i])->next=tmp;
}

void AdjacencyList :: remove(int i, int j)
{
	AdjListNode *t,*tmp;
	tmp=arr[i];
	while (tmp!=NULL)
	{
		if ((arr[i])->val==j)
		{
			tmp=arr[i];
			arr[i]=(arr[i])->next;
			delete tmp;
			return;
		}
		if (tmp->next==NULL)
			return;
		if (tmp->next->val==j)
		{
			t=tmp->next;
			tmp->next=t->next;
			delete t;
			return;
		}
	}
}

int AdjacencyList :: degree(int i)
{
	int j,res=0;
	AdjListNode *tmp=arr[i];
	while (tmp!=NULL)
	{
		res++;
		tmp=tmp->next;
	}
	for (j=0;j<(this->size);j++)
	{
		if (i!=j)
		{
			tmp=arr[j];
			while (tmp!=NULL)
			{
				if (tmp->val==i)
					res++;
				tmp=tmp->next;
			}
		}
	}
	return res;
}

void AdjacencyList :: display()
{
	int i;
	AdjListNode *tmp;
	std::cout<<"\n";
	for (i=0;i<(this->size);i++)
	{
		tmp=arr[i];
		std::cout<<i<<" : ";
		while (tmp!=NULL)
		{
			std::cout<<tmp->val<<" ";
			tmp=tmp->next;
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}

#endif /* ifndef ADJACENCY_LIST */
