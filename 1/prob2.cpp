#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

using namespace std;

int performop(LinearList <int> v,  LinearList <int> fin, string prefix, int n, int head)
{
	int i;
	for (i=0;i<prefix.length();i++)
	{
		if (head>=n)
			head=n-1;
		if (prefix[i]=='1')
		{
			int cho=0,min1,min2,min3;
			int min=v[head];
			for (i=1;i<head-1;i++)
			{
				if (v[i-1]<min && v[i+1]>min)
				{
					cho=1,min1=i;
					break;
				}
			}
			if (cho==0)
			{
				for (i=0;i<head-1;i++)
				{
					if (v[i+1]>min)
					{
						cho=2,min2=i;
						break;
					}
				}
				for (i=1;i<head;i++)
				{
					if (v[i-1]<min)
					{
						cho=2,min3=i;
						break;
					}
				}
			}
			if (cho==1)
				swap(v[head],v[min1]);
			else
			{
				if (min2<min3)
					swap(v[head],v[min2]);
				else
					swap(v[head],v[min3]);
			}
			head++;
		}
		else if (prefix[i]=='2')
		{
			int min=v[head];
			for (i=head+1;i<n;i++)
			{
				if (v[i]<min)
					min=i;
			} 
			swap(v[min],v[head]);
			head++;
		}
		else
		{
			for (i=head;i<n;i++)
			{
				if (v[i]>v[i+1])
					swap(v[i],v[i+1]);
			}
		}
	}
	for (i=0;i<n;i++)
	{
		if (v[i]!=fin[i])
			return 0;
	}
	return 1;
}

void printAllKLengthRec(string set, string prefix, int n, int k, LinearList <int> v,  LinearList <int> fin, int head) 
{
    if (k == 0)  
    { 
        cout<<prefix<<"\n"; 
        int t = performop(v,fin,prefix,n,head);
        if (t)
        	cout<<"Yes\n";
        else
        	cout<<"No\n";
        return; 
    } 
    for (int i = 0; i < n; ++i) 
    { 
        string newPrefix = prefix + set[i];  
        printAllKLengthRec(set, newPrefix, n, k - 1, v, fin, head);  
    } 
} 

void printsets(string set, int k, LinearList <int> v,  LinearList <int> fin, int head) 
{ 
    int n = set.length();  
    printAllKLengthRec(set, "", n, k, v, fin, head); 
}
   
int main()
{
	int head,n,i,j,k,tmp;
	cin>>n;
	LinearList <int> v(n);
	for (i=0;i<n;i++)
	{
		cin>>tmp;
		v.insert(i,tmp);
	}
	cin>>head;
	cin>>k;
	LinearList <int> fin(n);
	for (i=0;i<n;i++)
	{
		cin>>tmp;
		fin.insert(i,tmp);
	}
	LinearList <int> op(4);
	string str="123";
	printsets(str,k,v,fin,head);
	return 0;
}