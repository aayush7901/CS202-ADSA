#include <iostream>
#include "AVL.hpp"
#define ll long long
using namespace std;

int processfnc(AVL<ll,int>& a, ll& x)
{
	BinaryNode<ll,int> *p = a.getRoot();
	int res=0;
	while (p!=NULL)
	{
		if (x<=p->key)
			p=p->left;
		else if (x>p->key)
		{
			res += (1+size(p->left));
			p=p->right;
		}
	}
	a.put(x,1);
	// a.print_pre_order();
	return res;
}

int main()
{
    int n,i;
	AVL <ll, int> tree;
    cin>>n;
	ll arr[n];
    for (i=0;i<n;i++)
		cin>>arr[i];
	string res="";
	for (i=n-1;i>=0;i--)
		res=to_string(processfnc(tree,arr[i]))+" "+res;
	cout<<res<<"\n";
	return 0;
}
