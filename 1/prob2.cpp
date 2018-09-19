#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

using namespace std;

int final=0;
int performop(LinearList <int> v,  LinearList <int>& fin, string prefix, int n, int head)
{
	int i;
	for (i=0;i<prefix.length();i++)
	{
		if (head>=n)
			head=n-1;
		if (prefix[i]=='1')
		{
			int cho=0,min1,min2,min3;
			int mini=v[head];
			for (i=1;i<head;i++)
			{
				if (v[i-1]<mini && v[i+1]>mini)
				{
					cho=1,min1=i;
					break;
				}
			}
			if (cho==0)
			{
				for (i=0;i<head;i++)
				{
					if (v[i+1]>mini)
					{
						cho=2,min2=i;
						break;
					}
				}
				for (i=1;i<=head;i++)
				{
					if (v[i-1]<mini)
					{
						cho=2,min3=i;
						break;
					}
				}
			}
			if (cho==1)
				swap(v[head],v[min1]);
			else if (cho==2)
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
			int mini=head;
			for (i=head;i<n;i++)
			{
				if (v[i]<v[mini])
					mini=i;
			}
			swap(v[mini],v[head]);
			head++;
		}
		else
		{
			for (i=head;i<n-1;i++)
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

void printAllKLengthRec(string set, string prefix, int ss, int k, LinearList <int>& v,  LinearList <int>& fin, int head, int n)
{
    if (k == 0)
    {
        cout<<prefix<<"\n";
        int t = performop(v,fin,prefix,n,head);
        if (t)
        	final=1;
        return;
    }
    for (int i = 0; i < ss; ++i)
    {
        string newPrefix = prefix + set[i];
        printAllKLengthRec(set, newPrefix, ss, k - 1, v, fin, head, n);
    }
}

void printsets(string set, int k, LinearList <int>& v,  LinearList <int>& fin, int head, int n)
{
    int ss = set.length();
    printAllKLengthRec(set, "", ss, k, v, fin, head, n);
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
	string str="23";
	printsets(str,k,v,fin,head,n);
	if (final)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	// string prefix="11111";
	// cout<<performop(v,fin,prefix,n,head);;
	return 0;
}
