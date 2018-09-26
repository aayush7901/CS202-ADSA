#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1

#include <limits.h>
#include "queue.hpp"
#include <iostream>

using namespace std;
using namespace cs202;

template <class Key, class Value>
class BinaryNode
{
public:
	Key key;
	Value val;
	BinaryNode<Key,Value> *left, *right, *parent;
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode();
	/*This contructor should assign the key and val from the passed parameters
     */
	BinaryNode(Key key, Value value);
};

template <class Key, class Value>
BinaryNode<Key,Value>::BinaryNode()
{
	this->key=(Key)0;
	this->val=(Value)0;
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

template <class Key, class Value>
BinaryNode<Key,Value>::BinaryNode(Key key, Value value)
{
	this->key=key;
	this->val=value;
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

template <class Key, class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */
protected:
	BinaryNode<Key,Value> *root;

public:
	BinaryTree()
	{
		this->root=NULL;
	}
	/* Implement get function to retrieve the value corresponding to given key in binary tree.
	*/
	virtual Value get(const Key& key);
	/* Implement remove function that can delete a node in binary tree with given key.
	*/
	virtual void remove(const Key& key) ;
	/* Implement has function which will return true if the given key is present in binary tree
	* otherwise return false.
	*/
	virtual bool has(const Key& key) ;
	/* Implement put function such that newly inserted node keep the tree balanced.
	*/
	virtual void put(const Key& key, const Value& value) ;
	/*
	*This method print all the key value pairs of the binary tree, as
	*observed in an in order traversal.
	*/
	virtual void print_in_order();
	/*
	*This method print all the key value pairs of the binary tree, as
	*observed in an pre order traversal.
	*/
	virtual void print_pre_order();
	/*
	*This method print all the key value pairs of the binary tree, as
	*observed in a post order traversal.
	*/

	void removeUtil(BinaryNode<Key,Value> *p, const Key& key);

	virtual void print_post_order();
	/*
	*This method returns the minimum element in the binary tree.
	*/
	virtual Key minimum();
	/*
	* This method returns the maximum element in the binary tree.
	*/
	virtual Key maximum();
	/*
	*This method returns the successor, i.e, the next larget element in the
	*binary tree, after Key.
	*/
	virtual Key successor(const Key& key);
	/*
	* This method returns the predessor, ie, the next smallest element in the
	* binary tree, after Key.
	*/
	virtual Key predecessor(const Key& key);
};

template <class Key, class Value>
void inorderUtil(BinaryNode<Key,Value> *root)
{
	if(root==NULL)
		return;
	inorderUtil(root->left);
	cout<<(root->key)<<" "<<(root->val)<<"\n";
	inorderUtil(root->right);
}

template <class Key, class Value>
void BinaryTree<Key,Value> :: print_in_order()
{
	inorderUtil(this->root);
}

template <class Key, class Value>
void postorderUtil(BinaryNode<Key,Value> *root)
{
	if(root==NULL)
		return;
	postorderUtil(root->left);
	postorderUtil(root->right);
	cout<<(root->key)<<" "<<(root->val)<<"\n";
}

template <class Key, class Value>
void BinaryTree<Key,Value> :: print_post_order()
{
	postorderUtil(this->root);
}

template <class Key, class Value>
void preorderUtil(BinaryNode<Key,Value> *root)
{
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->val)<<"\n";
	preorderUtil(root->left);
	preorderUtil(root->right);
}

template <class Key, class Value>
void BinaryTree<Key,Value> :: print_pre_order()
{
	preorderUtil(this->root);
}

template <class Key, class Value>
void getUtil(BinaryNode<Key, Value> *p, const Key& key, Value& retValue)
{
	if (p==NULL)
		return;
	if (key==p->key)
	{
		retValue=p->val;
		return;
	}
	getUtil(p->left, key, retValue);
	getUtil(p->right, key, retValue);
}

template <class Key, class Value>
Value BinaryTree<Key,Value>::get(const Key& key)
{
	Value value=(Value)0;
	getUtil(this->root, key, value);
	return value;
}

template <class Key, class Value>
void BinaryTree<Key, Value>::removeUtil(BinaryNode<Key, Value> *p, const Key& key)
{
	if (p==NULL)
		return;
	if (key==p->key)
	{
		if (p->left && p->right)
		{
			BinaryNode <Key, Value> *tmp=p;
			while (tmp->left!=NULL)
				tmp=tmp->left;
			Value tmpvalue=(Value)0;
			Key tmpkey=(Key)0;
			tmpvalue=tmp->val;
			tmpkey=tmp->key;
			tmp->val=p->val;
			tmp->key=p->key;
			p->val=tmpvalue;
			p->key=tmpkey;
			removeUtil(p, tmp->key);
			return;
		}
		else if (p->left)
		{
			if (p==this->root)
			{
				delete this->root;
				this->root=p->left;
				return;
			}
			else if (p->parent->left==p)
			{
				p->parent->left=p->left;
				p->left->parent=p->parent;
				delete p;
				return;
			}
			else
			{
				p->parent->right=p->left;
				p->left->parent=p->parent;
				delete p;
				return;
			}
		}
		else if (p->right)
		{
			if (p==this->root)
			{
				delete this->root;
				this->root=p->right;
				return;
			}
			else if (p->parent->left==p)
			{
				p->parent->left=p->right;
				p->right->parent=p->parent;
				delete p;
				return;
			}
			else
			{
				p->parent->right=p->right;
				p->right->parent=p->parent;
				delete p;
				return;
			}
		}
		else
		{
			if (p==this->root)
			{
				delete this->root;
				this->root=NULL;
				return;
			}
			else if (p->parent->left==p)
			{
				p->parent->left=NULL;
				delete p;
				return;
			}
			else
			{
				p->parent->right=NULL;
				delete p;
				return;
			}
		}
	}
	removeUtil(p->left,key);
	removeUtil(p->right,key);
}

template <class Key, class Value>
void BinaryTree<Key, Value>::remove(const Key& key)
{
	removeUtil(this->root, key);
}

template <class Key, class Value>
bool BinaryTree<Key, Value>::has(const Key& key)
{
	Value value=(Value)0;
	getUtil(this->root,key,value);
	if (value==(Value)0)
		return false;
	return true;
}

template <class Key, class Value>
void BinaryTree<Key,Value>::put(const Key& key, const Value& value)
{
	if (this->root==NULL)
	{
		this->root = new BinaryNode<Key,Value>(key,value);
		return;
	}
	BinaryNode<Key,Value> *p;
	p = new BinaryNode<Key,Value>(key,value);
	queue < BinaryNode<Key,Value> *> q;
	q.push(this->root);
	while (1)
	{
		BinaryNode<Key,Value> *cur = q.pop();
		if (cur->left==NULL)
		{
			p->parent=cur;
			cur->left=p;
			break;
		}
		else
			q.push(cur->left);
		if (cur->right==NULL)
		{
			p->parent=cur;
			cur->right=p;
			break;
		}
		else
			q.push(cur->right);
	}
}


template<class Key, class Value>
void minUtil(BinaryNode<Key,Value> *p, Key &tmp)
{
	if (p==NULL)
		return;
	if (p->key<tmp)
		tmp=p->key;
	minUtil(p->left,tmp);
	minUtil(p->right,tmp);
}

template <class Key, class Value>
Key BinaryTree<Key,Value> :: minimum()
{
	Key tmp;
	tmp=this->root->key;
	minUtil(this->root,tmp);
	return tmp;
}

template<class Key, class Value>
void maxUtil(BinaryNode<Key,Value> *p, Key &tmp)
{
	if (p==NULL)
		return;
	if (p->key>tmp)
		tmp=p->key;
	maxUtil(p->left,tmp);
	maxUtil(p->right,tmp);
}

template <class Key, class Value>
Key BinaryTree<Key,Value> :: maximum()
{
	Key tmp;
	tmp=this->root->key;
	maxUtil(this->root,tmp);
	return tmp;
}

template<class Key, class Value>
void succUtil(BinaryNode<Key,Value> *p, BinaryNode<Key,Key> &tmp, Key tkey)
{
	if (p==NULL)
		return;
	if (((p->key -tkey)>0) && ((p->key -tkey)<tmp.val))
	{
		tmp.val = p->key -tkey;
		tmp.key = p->key;
	}
	succUtil(p->left,tmp,tkey);
	succUtil(p->right,tmp,tkey);
}

template <class Key, class Value>
Key BinaryTree<Key,Value>::successor(const Key& key)
{
	BinaryNode<Key,Value> tmp;
	tmp.val=maximum();
	succUtil(this->root,tmp,key);
	return tmp.key;
}

template<class Key, class Value>
void predUtil(BinaryNode<Key,Value> *p, BinaryNode<Key,Key> &tmp, Key tkey)
{
	if (p==NULL)
		return;
	if (((tkey- p->key)>0) && ((tkey- p->key)<tmp.val))
	{
		tmp.val = tkey - p->key;
		tmp.key = p->key;
	}
	predUtil(p->left,tmp,tkey);
	predUtil(p->right,tmp,tkey);
}

template <class Key, class Value>
Key BinaryTree<Key,Value>::predecessor(const Key& key)
{
	BinaryNode<Key,Value> tmp;
	tmp.val=maximum();
	predUtil(this->root,tmp,key);
	return tmp.key;
}

#endif /* ifndef BINARYTREE_HPP */
