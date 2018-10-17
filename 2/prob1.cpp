#include <iostream>
#include "RBTree.hpp"
#define ll long long
using namespace std;

class kvpair
{
public:
	ll val;
	ll index;
};

kvpair temp[100005];

void merge(kvpair arr[], ll l, ll mid, ll r)
{
    ll i,j,k;
    i=l;j=mid;k=l;
    while (i<mid && j<=r)
    {
        if (arr[i].val<=arr[j].val)
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while (i<mid)
        temp[k++]=arr[i++];
    while (j<=r)
        temp[k++]=arr[j++];
    for (i=l;i<=r;i++)
    	arr[i]=temp[i];
}

void mergesort(kvpair arr[], ll l, ll r)
{
    ll mid;
    if (r>l)
    {
        mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid+1,r);
    }
}

int main()
{
	int n,i;
	cin>>n;
	kvpair arr[n];
	for (i=0;i<n;i++)
	{
		cin>>arr[i].val;
		arr[i].index=i+1;
	}
	mergesort(arr,0,n-1);
	RBTree<ll,ll> a;
	ll pred[n],succ[n],res[n];
	for (i=n-1;i>=0;i--)
	{
		a.put(arr[i].index, arr[i].val);
		succ[i]=a.successor(arr[i].index);
		pred[i]=a.predecessor(arr[i].index);
		if (succ[i]==arr[i].index)
			succ[i]=-1;
		else
			succ[i]=abs(arr[i].index-succ[i]);
		if (pred[i]==arr[i].index)
			pred[i]=-1;
		else
			pred[i]=abs(arr[i].index-pred[i]);
		if (pred[i]==-1 && succ[i]==-1)
			res[arr[i].index-1]=-1;
		else if (pred[i]==-1)
			res[arr[i].index-1]=succ[i];
		else if (succ[i]==-1)
			res[arr[i].index-1]=pred[i];
		else
			res[arr[i].index-1]=min(succ[i],pred[i]);
	}
	for (i=0;i<n;i++)
		cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
