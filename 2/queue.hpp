#ifndef QUEUE_HPP_
#define QUEUE_HPP_ 1
#include <iostream>
using namespace std;

namespace queuehelp
{
    template<class T> class queue;
	template<class T> class listnode
	{
    	friend class queue<T>;
    	private:
            T data;
            listnode *link;
	};
	template <class T> class queue
    {
		private:
			listnode<T> *fron;
            listnode<T> *last;
            int len;
		public:
        	queue();
        	void print();
        	void push(T& t);
        	T pop();
        	T front();
        	inline int size();
        	inline bool empty();
        	~queue();
    };
    template<class T>
    void queue<T>::print()
    {
		listnode<T> *tmp=fron;
        while ( tmp!= NULL )
        {
			cout<<tmp->data<<"\n";
            tmp = tmp->link;
        }
    }

	template<class T>
    queue<T>::queue()
    {
        fron=NULL;
        last=NULL;
        len=0;
    }

    template<class T>
    void queue<T>::push(T& t)
	{
		listnode<T>* newnode=new listnode<T>();
        newnode->data=t;
        newnode->link=NULL;
		listnode<T> *tmp = fron;
		if (tmp!=NULL )
		{
        	last->link=newnode;
        	last=newnode;
    		len++;
    	}
    	else
		{
    		fron = last = newnode;
    		len++;
    	}
	}
	template<class T>
	T queue<T>::pop()
	{
		listnode<T> *tmp;
        T a= fron->data;
        tmp = fron->link;
        delete fron;
        fron=tmp;
        len--;
        return a;
    }

	template<class T>
    T queue<T>::front()
    {
		return fron->data;
	}

	template<class T>
    inline int queue<T>::size()
    {
		return len;
	}

    template<class T>
    inline bool queue<T>::empty()
    {
		if (len>0)
			return false;
        return true;
    }

    template<class T>
    queue<T>::~queue()
    {
        listnode<T> *tmp;
        while (fron)
        {   tmp = fron->link;
            delete fron;
            fron=tmp;
        }
    }
}
#endif
