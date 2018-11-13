#include <iostream>
#include <fstream>
#include "queue.hpp"
using namespace std;
using namespace queuehelp;

class qnode
{
	public:
		string str;
		int len;
		qnode()
		{
			str="";
			len=0;
		}
		qnode(string x, int y)
		{
			str=x;
			len=y;
		}
};

bool check(string a, string b)
{
	int i,res=0;
	int n=a.length();
	for (i=0;i<n;i++)
	{
		if (a[i]!=b[i])
			res++;
		if (res>1)
			return false;
	}
	return (res==1);
}

void printPath(int i, string prev[], string arr[], string start, string target, int len)
{
	cout<<"The path is:\n"<<start<<"\n";
	string path[10000];
	int count=0,ind;
	while (target!=start)
	{
		count++;
		path[count]=target;
		for (i=0;i<len;i++)
		{
			if (arr[i]==target)
			{
				ind=i;
				break;
			}
		}
		target=prev[ind];
	}
	for (i=count;i>=1;i--)
		cout<<path[i]<<"\n";
}

void findSoln(string arr[], string start, string target, int len, string prev[])
{
	queue <qnode> q;
	qnode x(start,1);
	q.push(x);
	bool visited[len];
	int i;
	for (i=0;i<len;i++)
		visited[i]=false;
	while (!q.empty())
	{
		qnode cur=q.pop();
		for (i=0;i<len;i++)
		{
			string tmp=arr[i];
			if (visited[i]==false && check(cur.str,arr[i]))
			{
				x.str=tmp;
				x.len=cur.len+1;
				prev[i]=cur.str;
				q.push(x);
				visited[i]=true;
				if (tmp==target)
				{
					printPath(i,prev,arr,start,target,len);
					cout<<"The Length is: "<<x.len<<"\n";
					return;
				}
			}
		}
	}
}

int main()
{
	int i;
	string start, target, arr[10000], prev[10000];
	ifstream f("dictionary.txt");
	while (getline(f,arr[i]))
		i++;
	cout<<"The start word is: ";
	cin>>start;
	cout<<"The target word is: ";
	cin>>target;
	int len=i;
	findSoln(arr,start,target,len,prev);
	return 0;
}
