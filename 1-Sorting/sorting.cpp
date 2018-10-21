#include <iostream>
#include "sorting.hpp"

template <class Item>
void Sort <Item>:: insertionSort(LinearList<Item>& A, int low, int high){
	int i,j;
	Item key;
    for (i=low+1;i<=high;i++) 
    {
        key=A[i];
        j=i-1;
        while (j>=0 && A[j]>key) 
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

template <class Item>
void Sort <Item>:: bubbleSort(LinearList<Item>& A, int low, int high){
	int swapped,i;
	Item temp;
    do 
    {
        swapped=0;
        for (i=low;i<high;i++) 
        {
            if (A[i]>A[i+1]) 
            {
                swapped=1;
                temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
            }
        }
        high--;
    } while (swapped);
}

template <class Item>
void Sort <Item>:: rankSort(LinearList<Item>& A, int low, int high){
	Item rank[high-low+1];
	Item tmp[high-low+1];
	int i,j;
	for (i=low;i<=high;i++)
		rank[i]=0;
	for (i=low+1;i<=high;i++)
	{
		for (j=low;j<i;j++)
		{
			if (A[j]>A[i])
				rank[j]++;
			else
				rank[i]++;
		}
	}
	for (i=low;i<=high;i++)
		tmp[rank[i]]=A[i];	
	for (i=low;i<=high;i++)
		A[i]=tmp[i];
}

template <class Item>
void Sort <Item>:: selectionSort(LinearList<Item>& A, int low, int high){
	int i,j,minElementIndex;
	Item temp;
    for (i=low;i<high;i++) 
    {
        minElementIndex=i;
        for (j=i+1;j<=high;j++) 
        {
            if (A[j]<A[minElementIndex])
                minElementIndex = j;
        }
        if (i!=minElementIndex) 
        {
            temp=A[i];
            A[i]=A[minElementIndex];
            A[minElementIndex]=temp;
        }
    }
}

template <class Item>
void merge(LinearList<Item>& A, int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	Item left[n1],right[n2];
	for (i=0;i<n1;i++)
		left[i]=A[l+i];
	for (j=0;j<n2;j++)
		right[j]=A[m+1+j];
	i=0;j=0;k=l;
	while (i<n1 && j<n2)
	{
		if (left[i]<=right[j])
			A[k]=left[i++];
		else
			A[k]=right[j++];
		k++;
	}
	while (i<n1)
	{
		A[k]=left[i++];
		k++;
	}		
	while (j<n2)
	{
		A[k]=right[j++];
		k++;
	}	
}

template <class Item>
void Sort <Item>:: mergeSort(LinearList<Item>& A, int low, int high){
	if (low<high)
	{
		int m=low+(high-low)/2;
		mergeSort(A,low,m);
		mergeSort(A,m+1,high);
		merge(A,low,m,high);		
	}
}

template <class Item>
int partition(LinearList<Item>& A, int l, int r)
{
	Item pivot=A[r],tmp;
	int j,i=l-1;
	for (j=l; j<=r; j++)
	{
		if (A[j]<=pivot)
		{
			i++;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
	return i;
}

template <class Item>
void Sort <Item>:: quickSort(LinearList<Item>& A, int low, int high){
	if (low<high)
    {
        int pi=partition(A, low, high);
		quickSort(A, low, pi-1);
		quickSort(A, pi+1, high);
    }
}

template <class Item>
void heapify(LinearList<Item> &A, int i, int n)
{
	int l=2*i+1,r=2*i+2,large=i;
	if (l<n && A[l]>A[large])
		large=l;
	if (r<n && A[r]>A[large])
		large=r;
	if (large!=i)
	{
		swap(A[i],A[large]);
		heapify(A,large,n);
	}
}

// low should be 0 always in this heap sort
template <class Item>
void Sort <Item>:: heapSort(LinearList<Item>& A, int low, int high)
{
	Item max;
	int i;
	for (i=((high+1)/2)-1;i>=low;i--)
		heapify(A,i,high+1);
	while (high>=low)
	{
		swap(A[low],A[high]);
		heapify(A,low,high);
		high--;
	}
}