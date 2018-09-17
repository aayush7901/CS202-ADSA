#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

#define ll long long int
#define INF 1e7

using namespace std;

struct node
{
	int info;
	struct node *link;
};
typedef struct node NODE;

bool havecommon(int a, int b)
{
	int x=min(a,b),res=0;
	for (int i=2;i<=x;i++)
	{
		if (a%i==0 && b%i==0)
			res++;
	}
	return (res>=2);
}

NODE *addatbeg(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

NODE *addatend(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	NODE *p;
	p=start;
	while (p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

NODE *addatpos(NODE *start, int data, int pos)
{
	NODE *tmp,*p;
	int i;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	if (pos==1)
	{
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	for (i=1;i<pos-1 && p!=NULL;i++)
		p=p->link;
	if (p==NULL)
		printf("There are less than %d elements in the list!\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}

int checkpos(NODE* start, int data)
{
	NODE *p=start;
	int i=1;
	while (p!=NULL)
	{
		if (havecommon(data,p->info))
			return i;
		i++;
		p=p->link;
	}
	return INF;
}

void display(NODE *start)
{
	while (start != NULL)
  	{
		printf(" %d ", start->info);
		start = start->link;
  	}
}

double minswaps(NODE *start, LinearList<int> &roll, LinearList<double> &height)
{
	NODE *p=start;
	int count=0;
	while (p!=NULL)
	{
		count++;
		p=p->link;
	}
	LinearList <double> cur(count);
	int i=0;
	NODE *pi=start;
	while (pi!=NULL)
	{
		int pos=roll.search(pi->info);
		cur.insert(i,height[pos]);
		i++;
		pi=pi->link;
	}
	// Now we find minimum swaps in cur list (height list in one row)
	int j,minElementIndex,res=0;
	double temp;
    for (i=0;i<count;i++) 
    {
        minElementIndex=i;
        for (j=i+1;j<count;j++) 
        {
            if (cur[j]<cur[minElementIndex])
                minElementIndex = j;
        }
        if (i!=minElementIndex) 
        {
            swap(cur[i],cur[minElementIndex]);
            res++;
        }
    }
    return (0.5*res);
}

int main()
{
	int n,m,i,k,tmp;
	double h;
	cin>>n>>m>>k;
	LinearList <int> roll(k);
	LinearList <double> height(k);
	for (i=0;i<k;i++)
	{
		cin>>tmp>>h;
		roll.insert(i,tmp);
		height.insert(i,h);
	}
	LinearList <int> flag(26);
	LinearList <NODE*> hea(26);
	for (i=0;i<26;i++)
	{
		flag[i]=0;
		hea[i]=NULL;
	}
	char a;int b;
	for (i=0;i<k;i++)
	{
		cin>>a>>b;
		tmp=flag[a-'A'];
		if (tmp==0)
		{
			flag[a-'A']=1;
			hea[a-'A']=addatbeg(hea[a-'A'],b);
		}
		else
		{
			int pos=checkpos(hea[a-'A'],b);
			if (pos==INF)
				hea[a-'A']=addatend(hea[a-'A'],b);
			else
				hea[a-'A']=addatpos(hea[a-'A'],b,pos+1);
		}
	}
	for (i=0;i<26;i++)
	{
		if (hea[i]!=NULL)
			cout<<minswaps(hea[i],roll,height)<<" ";
	}
	return 0;
}