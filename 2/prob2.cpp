#include <iostream>
#include "RBTree.hpp"
#define ll long long
using namespace std;

RBTree <ll, int> a;

int processfnc(ll& x)
{
	BinaryNode<ll,int> *p = a.getRoot();
	int res=0;
	while (p!=NULL)
	{
		if (x<p->key)
			p=p->left;
		else if (x>p->key)
		{
			res += (1+size(p->left));
			p=p->right;
		}
		else if (x==p->key)
		{
			p=p->left;
		}
	}
	a.insert(x,1);
	return res;
}

int main()
{
    int n,i;
    cin>>n;
	ll arr[n];
    for (i=0;i<n;i++)
		cin>>arr[i];
	string res="";
	for (i=n-1;i>=0;i--)
		res=to_string(processfnc(arr[i]))+" "+res;
	cout<<res<<"\n";
	return 0;
}
