#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

#define ll long long int

int main()
{
	int n,k,i,tmp,j,p;
	cin>>n>>k;
	LinearList <int> v(n);
	Sort <int> s;
	for (i=0;i<n;i++)
	{
		cin>>tmp;
		v.insert(i,tmp);
	}
	if (n%2)
	{
		LinearList <int> a(n/2+1);
		LinearList <int> b(n/2);
		LinearList <int> ac(n/2);
		LinearList <int> bc(n/2+1);
		for (i=0;i<n;i++)
		{
			if (i<n/2)
			{
				a.insert(i,v[i]);
				ac.insert(i,v[i]);
			}
			else if (i>n/2)
			{
				b.insert(i-(n/2)-1,v[i]);
				bc.insert(i-(n/2),v[i]);
			}
			else
			{
				a.insert(i,v[i]);
				bc.insert(0,v[i]);
			}
		}
		s.mergeSort(a,0,n/2);
		s.mergeSort(b,0,n/2-1);
		s.mergeSort(ac,0,n/2-1);
		s.mergeSort(bc,0,n/2);
		j=0;i=n/2-1;
		for (p=0;p<k;p++)
		{
			if (b[i]>a[j] && j<=n/2 && i>=0)
				swap(a[j],b[i]);
			else
				break;
			j++;i--;
		}
		j=0;i=n/2-1;
		for (p=0;p<k;p++)
		{
			if (bc[j]<ac[i] && j<=n/2 && i>=0)
				swap(bc[j],ac[i]);
			else
				break;
			j++;i--;
		}
		ll asum=0,bsum=0,acsum=0,bcsum=0;
		for (i=0;i<n/2;i++)
		{
			asum+=a[i];
			bsum+=b[i];
			acsum+=ac[i];
			bcsum+=bc[i];
		}
		asum+=a[n/2];
		bcsum+=bc[n/2];
		if (max(asum,max(bsum,max(acsum,bcsum)))==asum)
		{
			for (i=0;i<=n/2;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
			for (i=0;i<n/2;i++)
				cout<<b[i]<<" ";
		}
		else if (max(asum,max(bsum,max(acsum,bcsum)))==bsum)
		{
			for (i=0;i<n/2;i++)
				cout<<b[i]<<" ";
			cout<<"\n";	
			for (i=0;i<=n/2;i++)
				cout<<a[i]<<" ";
		}
		else if (max(asum,max(bsum,max(acsum,bcsum)))==acsum)
		{
			for (i=0;i<n/2;i++)
				cout<<ac[i]<<" ";
			cout<<"\n";
			for (i=0;i<=n/2;i++)
				cout<<bc[i]<<" ";
		}
		else
		{
			for (i=0;i<=n/2;i++)
				cout<<bc[i]<<" ";
			cout<<"\n";
			for (i=0;i<n/2;i++)
				cout<<ac[i]<<" ";
		}
	}
	else
	{
		LinearList <int> a(n/2);
		LinearList <int> b(n/2);
		LinearList <int> ac(n/2);
		LinearList <int> bc(n/2);
		for (i=0;i<n;i++)
		{
			if (i<n/2)
			{
				a.insert(i,v[i]);
				ac.insert(i,v[i]);
			}
			else
			{
				b.insert(i-(n/2),v[i]);
				bc.insert(i-(n/2),v[i]);
			}
		}
		s.mergeSort(a,0,n/2-1);
		s.mergeSort(b,0,n/2-1);
		s.mergeSort(ac,0,n/2-1);
		s.mergeSort(bc,0,n/2-1);
		j=0;i=n/2-1;
		for (p=0;p<k;p++)
		{
			if (b[i]>a[j] && j<n/2 && i>=0)
				swap(a[j],b[i]);
			else
				break;
			j++;i--;
		}
		j=0;i=n/2-1;
		for (p=0;p<k;p++)
		{
			if (bc[j]<ac[i] && j<n/2 && i>=0)
				swap(bc[j],ac[i]);
			else
				break;
			j++;i--;
		}
		ll asum=0,bsum=0,acsum=0,bcsum=0;
		for (i=0;i<n/2;i++)
		{
			asum+=a[i];
			bsum+=b[i];
			acsum+=ac[i];
			bcsum+=bc[i];
		}
		if (max(asum,max(bsum,max(acsum,bcsum)))==asum)
		{
			for (i=0;i<n/2;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
			for (i=0;i<n/2;i++)
				cout<<b[i]<<" ";
		}
		else if (max(asum,max(bsum,max(acsum,bcsum)))==bsum)
		{
			for (i=0;i<n/2;i++)
				cout<<b[i]<<" ";
			cout<<"\n";	
			for (i=0;i<n/2;i++)
				cout<<a[i]<<" ";
		}
		else if (max(asum,max(bsum,max(acsum,bcsum)))==acsum)
		{
			for (i=0;i<n/2;i++)
				cout<<ac[i]<<" ";
			cout<<"\n";
			for (i=0;i<n/2;i++)
				cout<<bc[i]<<" ";
		}
		else
		{
			for (i=0;i<n/2;i++)
				cout<<bc[i]<<" ";
			cout<<"\n";
			for (i=0;i<n/2;i++)
				cout<<ac[i]<<" ";
		}
	}
	return 0;
}