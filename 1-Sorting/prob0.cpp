#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"

int main(){
   
   //variables
   int inputSize,temp,option,i;

   //input
   cout<<"Enter the input size of our LinearList"<<"\n";
   cin>>inputSize;

   //objects
   LinearList <int> sampleObject =  LinearList <int>(inputSize);
   Sort <int> sortObject;

   //input
   cout<<"Please enter elements of LinearList"<<"\n";
   for (i=0;i<inputSize;i++){
   	cin>>temp;
   	sampleObject.insert(i,temp);
   }
   cout<<"\n";
   cout<<"Entered array is:\n";
	for (i=0;i<inputSize;i++){
	 cout<<sampleObject[i]<<" ";
	}
	cout<<"\n";
   //options
		
   	cout<<" Please select a method for Sorting of these Numbers";
   	cout<<"\n1. InsertionSort\n";
	cout<<"2. BubbleSort\n";
	cout<<"3. RankSort\n";
	cout<<"4. SelectionSort\n";
	cout<<"5. MergeSort\n";
	cout<<"6. QuickSort\n";
	cout<<"7. HeapSort\n";
	cout<<"8. Exit\n";
   	cin>>option;
	cout<<"\n";
	switch(option)
		{
	     case 1  :
	        sortObject.insertionSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by InsertionSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break; 
	     case 2  :
	        sortObject.bubbleSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by BubbleSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break; 
	     case 3 :
	        sortObject.rankSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by RankSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break;
	     case 4 :
	        sortObject.selectionSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by SelectionSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break; 
	     case 5 :
	        sortObject.mergeSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by MergeSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break;
	     case 6 :
	        sortObject.quickSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by QuickSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";
	        break; 
	     case 7 :
	        sortObject.heapSort(sampleObject,0,inputSize-1);
	        cout<<"Array sorted by HeapSort\n";
	        for (i=0;i<inputSize;i++){
	           cout<<sampleObject[i]<<" ";
	        }
	        cout<<"\n\n";  
	     case 8 :
	        exit(1); 
	     default : 
	        cout<<"Select an option from 1 to 7\n";
		}
   return 0;
}