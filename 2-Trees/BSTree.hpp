#ifndef BSTREE_HPP
#define BSTREE_HPP 1

#include "BinaryTree.hpp"

template <class Key, class Value>
class BSTree : public BinaryTree<Key, Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
 public:
	 BSTree()
	 {
		 this->root=NULL;
	 }
  /*
   * This method returns the current height of the binary search tree.
   */
	virtual int getHeight();
  /*
   * This method returns the total number of elements in the binary search tree.
   */
	virtual int size();
  /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
	virtual void print();
	virtual void remove(const Key &key);
	virtual void put(const Key &key, const Value& value);
	virtual Value get(const Key &key);
	virtual Key minimum();
	virtual Key maximum();
	virtual Key successor(const Key& key);
	virtual Key predecessor(const Key& key);
};

template <class Key, class Value>
int ghUtil(BinaryNode<Key,Value> *p)
{
	if (p==NULL)
		return 0;
	int lh=ghUtil(p->left);
	int rh=ghUtil(p->right);
	if (lh>rh)
		return lh+1;
	else
		return rh+1;
}

template <class Key, class Value>
int BSTree<Key,Value>::getHeight()
{
	return ghUtil(this->root);
}

template <class Key, class Value>
int sizeUtil(BinaryNode<Key,Value> *p)
{
	if (p==NULL)
		return 0;
	return 1+sizeUtil(p->left)+sizeUtil(p->right);
}

template <class Key, class Value>
int BSTree<Key,Value>::size()
{
	return sizeUtil(this->root);
}

template <class Key, class Value>
void BSTree<Key,Value>::print()
{
	this->print_in_order();
}

template <class Key, class Value>
void removeUtil(BinaryNode<Key,Value> *p, const Key &key)
{
	BinaryNode<Key,Value> *succ;
	if (p==NULL)
		return;
	if (key<p->key)
		removeUtil(p->left,key);
	else if (key>p->key)
		removeUtil(p->right,key);
	else
	{
		if (p->left && p->right)
		{
			succ=p->right;
			while (succ->left)
				succ=succ->left;
			p->key=succ->key;
			p->val=succ->val;
			removeUtil(p->right,succ->key);
		}
		else
		{
			if (p->left)
			{
				if (p->parent)
				{
					if (p==p->parent->left)
						p->parent->left=p->left;
					else
						p->parent->right=p->left;
				}
				p->left->parent=p->parent;
			}
			else if (p->right)
			{
				if (p->parent)
				{
					if (p==p->parent->left)
						p->parent->left=p->right;
					else
						p->parent->right=p->right;
				}
				p->right->parent=p->parent;
			}
			else
			{
				if (p->parent)
				{
					if (p==p->parent->left)
						p->parent->left=NULL;
					else
						p->parent->right=NULL;
				}
			}
			delete p;
		}
	}
}

template <class Key, class Value>
void BSTree<Key,Value>::remove(const Key& key)
{
	removeUtil(this->root,key);
}

template <class Key, class Value>
BinaryNode<Key,Value>* putUtil(BinaryNode<Key,Value>* p, const Key& key, const Value& value)
{
	if (p==NULL)
		p = new BinaryNode<Key, Value>(key,value);
	else if (key<p->key)
	{
		p->left=putUtil(p->left,key,value);
		p->left->parent=p;
	}
	else if (key>=p->key)
	{
		p->right=putUtil(p->right,key,value);
		p->right->parent=p;
	}
	return p;
}

template <class Key, class Value>
void BSTree<Key,Value>::put(const Key& key, const Value& value)
{
	this->root=putUtil(this->root,key,value);
}

template <class Key, class Value>
Value getUtil(BinaryNode<Key,Value>* p, const Key& key)
{
	if (p==NULL)
		return Value();
	if (p->key==key)
		return p->val;
	else if (p->key<key)
		return getUtil(p->right,key);
	else if (p->key>key)
		return getUtil(p->left,key);
}

template <class Key, class Value>
Value BSTree<Key,Value>::get(const Key& key)
{
	return getUtil(this->root, key);
}

template <class Key, class Value>
Key minUtil(BinaryNode<Key, Value>* p)
{
	if (p==NULL)
		return Key();
	if (p->left==NULL)
		return p->key;
	else
		return minUtil(p->left);
}

template <class Key, class Value>
Key BSTree<Key,Value>::minimum()
{
	return minUtil(this->root);
}

template <class Key, class Value>
Key maxUtil(BinaryNode<Key, Value>* p)
{
	if (p==NULL)
		return Key();
	if (p->right==NULL)
		return p->key;
	else
		return maxUtil(p->right);
}

template <class Key, class Value>
Key BSTree<Key,Value>::maximum()
{
	return maxUtil(this->root);
}

template <class Key, class Value>
BinaryNode<Key,Value>* findUtil(BinaryNode<Key,Value> *p, const Key &key)
{
	if (p==NULL)
		return NULL;
	else if (key<p->key)
		return findUtil(p->left,key);
	else if (key>p->key)
		return findUtil(p->right,key);
	else
		return p;
}

template <class Key, class Value>
Key succUtil(BinaryNode<Key,Value>* root, BinaryNode<Key,Value>* p)
{
	if (p->right!=NULL)
		return minUtil(p->right);
	if (p->parent==NULL)
	 	return p->key;
	BinaryNode<Key,Value>* x=p->parent;
	while (x!=NULL  && p==x->right)
	{
		p=x;
		x=x->parent;
	}
	if (x==NULL)
		return p->key;
	return x->key;
}

template <class Key, class Value>
Key BSTree<Key,Value>::successor(const Key& key)
{
	BinaryNode<Key, Value> *p = this->root;
	while (p)
	{
		if (p->key == key)
			break;
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return key;
	if (p->right)
	{
		p = p->right;
		while (p)
		{
			if (!p->left)
				break;
			p = p->left;
		}
		if (!p)
			return key;
		return p->key;
	}
	else
	{
		while (p)
		{
			if (p->key > key)
				return p->key;
			p = p->parent;
		}
		if (!p)
			return key;
	}
}

template <class Key, class Value>
Key BSTree<Key,Value>::predecessor(const Key& key)
{
	BinaryNode<Key, Value> *p = this->root;
	while (p)
	{
		if (p->key == key)
			break;
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return key;
	if (p->left)
	{
		p = p->left;
		while(p)
		{
			if (!p->right)
				break;
			p = p->right;
		}
		if (!p)
			return key;
		return p->key;
	}
	else
	{
		while (p)
		{
			if (p->key < key)
				return p->key;
			p = p->parent;
		}
		if (!p)
			return key;
	}
}
#endif  /* ifndef BSTREE_HPP */
