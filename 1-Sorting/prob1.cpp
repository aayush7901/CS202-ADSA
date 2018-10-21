#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

#define MOD 1000000007
#define ll long long int

int main()
{
	int n,i;
	ll tmp,maxi,mini;
	cin>>n;
	LinearList <ll> v(n);
	Sort <ll> sortObject;
	for (i=0;i<n;i++)
	{
   		cin>>tmp;
   		v.insert(i,tmp);
	}
	sortObject.mergeSort(v,0,n-1);
	if (n%2)
		cout<<v[n/2]%MOD<<"\n";
	else
	{
		maxi=v[n/2];
		mini=v[n/2-1]-1;
		cout<<((((maxi*(maxi+1)))/2)%MOD-(((mini*(mini+1)))/2)%MOD)%MOD<<endl;
	}
	return 0;
}