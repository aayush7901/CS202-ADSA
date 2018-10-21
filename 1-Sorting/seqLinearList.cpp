#include <iostream>
#include "seqLinearList.hpp"

template <class Item>
LinearList <Item>:: LinearList(void) : element(NULL), MaxSize(20){
} 

template <class Item>
LinearList <Item>:: LinearList(const int& MaxListSize){
	element = new Item[MaxListSize];
	MaxSize = MaxListSize;
	len = 0;
	int i;
	for (i=0;i<MaxSize;i++)
		element[i]=0;
}

template <class Item>
LinearList <Item>:: ~LinearList(void){
	delete [] element;
}

template <class Item>
Item& LinearList <Item>:: operator[](const int& i){
	return element[i];
}

template <class Item>
bool LinearList <Item>:: isEmpty(){
	return (len==0);
}

template <class Item>
int LinearList <Item>:: length(){
	return len;
}

template <class Item>
int LinearList <Item>:: maxSize(){
	return MaxSize;
}

template <class Item>
Item LinearList <Item>:: returnListElement(const int k){
	return element[k];
}

template <class Item>
bool LinearList <Item>:: find(const int k, Item& x){
	x=element[k];
	return (k>=0 && k<len);
}

template <class Item>
int LinearList <Item>:: search(Item& x){
	for (int i=0;i<len;i++)
	{
		if (element[i]==x)
			return i;
	}
	return 0; // can return -1 if not be confused if first element is found
}

template <class Item>
void LinearList <Item>:: deleteElement(const int k, Item& x){
	x=element[k];
	for (int i=k;i<len;i++)
		element[i]=element[i+1];
	len--;
}

template <class Item>
void LinearList <Item>:: insert(const int k, Item& x){
	for (int i=len-1;i>=k;i--)
		element[i+1]=element[i];
	element[k]=x;
	len++;
} 