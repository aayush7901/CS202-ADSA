#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"
template <class Key, class Value>
class AVL : public BSTree<Key, Value> {
  /*
   * Inherit as much functionality as possible from the BSTree class.
   * Then provide custom AVL Tree functionality on top of that.
   * The AVL Tree should make use of as many BST functions as possible.
   * Override only those methods which are extremely necessary.
   */
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   *
   * The signature of these functions are not provided in order to provide you
   * some flexibility in how you implement the internals of your AVL Tree. But
   * make sure these functions are there.
   */
public:
	int getBalance(BinaryNode<Key,Value>* p);
	BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value>* p);
	BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value>* p);
	BinaryNode<Key,Value>* insertUtil(BinaryNode<Key,Value>* p, const Key& key, const Value& value);
	BinaryNode<Key,Value>* deleteUtil(BinaryNode<Key,Value>* p, const Key& key);
	AVL()
	{
		this->root=NULL;
	}
	void put(const Key& key, const Value& value);
	void remove(const Key& key);
};

template <class Key, class Value>
int AVL<Key, Value>::getBalance(BinaryNode<Key,Value> *p)
{
	if (p==NULL)
		return 0;
	return ghUtil(p->left)-ghUtil(p->right);
}

template <class Key, class Value>
BinaryNode<Key,Value>* AVL<Key,Value>::rightRotate(BinaryNode<Key,Value>* p)
{
	BinaryNode<Key,Value> *x=p->left;
	x->parent=p->parent;
	if (p->parent==NULL) // p root
		this->root=x;
	else if (p->parent->left==p) //p left child
		p->parent->left=x;
	else if (p->parent->right==p) //p right child
		p->parent->right=x;
	BinaryNode<Key,Value> *y=x->right;
	if (y)
		y->parent=p;
	p->parent=x;
	p->left=y;
	x->right=p;
	return x;
}

template <class Key, class Value>
BinaryNode<Key,Value>* AVL<Key,Value>::leftRotate(BinaryNode<Key,Value>* p)
{
	BinaryNode<Key,Value> *x=p->right;
	x->parent=p->parent;
	if (p->parent==NULL) // p root
		this->root=x;
	else if (p->parent->left==p) //p left child
		p->parent->left=x;
	else if (p->parent->right==p) //p right child
		p->parent->right=x;
	BinaryNode<Key,Value> *y=x->left;
	if (y)
		y->parent=p;
	p->parent=x;
	p->right=y;
	x->left=p;
	return x;
}

template <class Key, class Value>
BinaryNode<Key,Value>* AVL<Key,Value>::insertUtil(BinaryNode<Key,Value>* p, const Key& key, const Value& value)
{
	BinaryNode<Key,Value> *x;
	if (p==NULL)
	{
		x = new BinaryNode<Key,Value>(key,value);
		return x;
	}
	if (key<p->key)
	{
		x=insertUtil(p->left,key,value);
		x->parent=p;
		p->left=x;
	}
	else if (p->key<key)
	{
		x=insertUtil(p->right,key,value);
		x->parent=p;
		p->right=x;
	}
	int bal=getBalance(p);
	if (bal>1) //L
	{
		if (key<p->left->key) //LL case
			return rightRotate(p);
		else if (key>p->left->key) //LR case
		{
			p->left=leftRotate(p->left);
			return rightRotate(p);
		}
	}
	else if (bal<-1) //R
	{
		if (key>p->right->key) //RR case
			return leftRotate(p);
		else if (key<p->right->key) //RL case
		{
			p->right=rightRotate(p->right);
			return leftRotate(p);
		}
	}
	return p;
}

template <class Key, class Value>
void AVL<Key,Value>::put(const Key& key, const Value& value)
{
	this->root=insertUtil(this->root,key,value);
}

template <class Key, class Value>
BinaryNode<Key,Value>* AVL<Key,Value>::deleteUtil(BinaryNode<Key,Value>*p, const Key& key)
{
	if (p==NULL)
		return p;
	if (key<p->key)
		p->left=deleteUtil(p->left,key);
	else if (key>p->key)
		p->right=deleteUtil(p->right,key);
	else
	{
		if (p->left==NULL || p->right==NULL) // only one child or no child
		{
			BinaryNode<Key,Value>*tmp=(p->left==NULL)?p->right:p->left;
			if (p!=this->root)
			{
				if (p->parent->left==p) // L child
					p->parent->left=tmp;
				else if (p->parent->right==p) // R child
					p->parent->right=tmp;
				if (tmp)
					tmp->parent=p->parent;
			}
			delete p;
			return tmp;
		}
		else  // 2 childs
		{
			BinaryNode<Key,Value>*tmp=p->right;
			while (tmp->left!=NULL)
				tmp=tmp->left;
			p->key=tmp->key;
			p->val=tmp->val;
			p->right=deleteUtil(p->right,tmp->key);
		}
	}
	int bal=getBalance(p);
	if (bal>1) //L
	{
		if (getBalance(p->left)>=0) //LL
			return rightRotate(p);
		else if (getBalance(p->left)<0) //LR
		{
			p->left=leftRotate(p->left);
			return rightRotate(p);
		}
	}
	else if (bal<-1) //R
	{
		if (getBalance(p->right)<=0) //RR
			return leftRotate(p);
		else if (getBalance(p->right)>0)//RL
		{
			p->right=rightRotate(p->right);
			return leftRotate(p);
		}
	}
	return p;
}

template <class Key, class Value>
void AVL<Key,Value>::remove(const Key& key)
{
	this->root=deleteUtil(this->root,key);
}

#endif /* ifndef AVL_HPP */
