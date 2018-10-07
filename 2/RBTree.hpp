#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it.
 */
// enum Color { RED, BLACK };

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	void insertRBFixup(BinaryNode<Key,Value>* p);

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(BinaryNode<Key,Value>* p);

public:
	RBTree()
	{
		this->root=NULL;
	}
	void insert(const Key& key, const Value& value);
	void deleteKey(const Key& key);
	BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value> *p);
	BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value> *p);
	/* Function : blackHeight
	 *
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */
	int blackHeight(BinaryNode<Key,Value>* p);
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
};

template <class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::rightRotate(BinaryNode<Key,Value>* p)
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
BinaryNode<Key,Value>* RBTree<Key,Value>::leftRotate(BinaryNode<Key,Value>* p)
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
void RBTree<Key,Value>::insertRBFixup(BinaryNode<Key,Value>* p)
{
	if (p==this->root)
		p->color=BLACK;
	else if (p->parent->color!=BLACK)
	{
		//Find parent's sibling (uncle)
		BinaryNode<Key,Value> *unc;
		if (p->parent->parent==NULL)
			unc=NULL;
		else
		{
			if (p->parent->parent->right==p->parent)
				unc=p->parent->parent->left;
			else
				unc=p->parent->parent->right;
		}

		if (unc && unc->color==RED) // uncle present with color red
		{
			unc->color=BLACK;
			p->parent->color=BLACK;
			p->parent->parent->color=RED;
			insertRBFixup(p->parent->parent);
		}
		else // uncle present with color black or no uncle present
		{
			BinaryNode<Key,Value> *pa=p->parent;
			BinaryNode<Key,Value> *gpa=p->parent->parent;
			if (p==pa->left && pa==gpa->left) //LL
				rightRotate(gpa);
			else if (p==pa->right && pa==gpa->right) //RR
				leftRotate(gpa);
			else if (p==pa->right && pa==gpa->left) //LR
			{
				leftRotate(pa);
				rightRotate(gpa);
			}
			else if (p==pa->left && pa==gpa->right) //RL
			{
				rightRotate(pa);
				leftRotate(gpa);
			}
			swap(pa->color, gpa->color);
		}
	}
}

template <class Key, class Value>
void RBTree<Key,Value>::insert(const Key& key, const Value& value)
{
	this->root = putUtil(this->root,key,value); 	// BST Insert
	BinaryNode<Key,Value> *p = findUtil(this->root, key);
	p->color=RED; 		// set color of inserted node to RED
	insertRBFixup(p); 	// recolor or rotate
}

template <class Key, class Value>
int RBTree<Key,Value>::blackHeight(BinaryNode<Key,Value>* p)
{
	if (p==NULL)
		return 0;
	if (p->color==BLACK)
		return 1+blackHeight(p->left);
	else
		return blackHeight(p->left);
}

template <class Key, class Value>
void RBTree<Key,Value>::deleteRBFixup(BinaryNode<Key,Value>* p)
{
	BinaryNode<Key,Value> *s;
	while (p!=this->root && p->color==BLACK)
	{
		if (p->parent->left==p)
		{
			s=p->parent->right;
			if (s->color==RED)
			{
				s->color=BLACK;
				p->parent->color=RED;
				leftRotate(p->parent);
				s=p->parent->right;
			}
			if (s->right->color==BLACK && s->left->color==BLACK)
			{
				s->color=RED;
				p=p->parent;
			}
			else
			{
				if (s->right->color==BLACK)
				{
					s->left->color=BLACK;
					s->color=RED;
					rightRotate(s);
					s=p->parent->right;
				}
				s->color=p->parent->color;
				p->parent->color=BLACK;
				s->right->color=BLACK;
				leftRotate(p->parent);
				p=this->root;
			}
		}
		else
		{
			s=p->parent->left;
			if (s->color==RED)
			{
				s->color=BLACK;
				p->parent->color=RED;
				rightRotate(p->parent);
				s=p->parent->left;
			}
			if (s->left->color==BLACK && s->right->color==BLACK)
			{
				s->color=RED;
				p=p->parent;
			}
			else
			{
				if (s->left->color==BLACK)
				{
					s->right->color=BLACK;
					s->color=RED;
					leftRotate(s);
					s=p->parent->left;
				}
				s->color=p->parent->color;
				p->parent->color=BLACK;
				s->left->color=BLACK;
				rightRotate(p->parent);
				p=this->root;
			}
		}
		p->color=BLACK;
		this->root->color=BLACK;
	}
}

template <class Key, class Value>
void RBTree<Key,Value>::deleteKey(const Key& key)
{
		BinaryNode<Key,Value> *q,*y,*p = findUtil(this->root, key);
		if (p->left==NULL || p->right==NULL)
			y=p;
		else
			y=findUtil(this->root,succUtil(this->root,p));
		if (y->left!=NULL)
			q=y->left;
		else
		{
			if (y->right!=NULL)
				q=y->right;
			else
				q=NULL;
		}
		if (q!=NULL)
			q->parent=y->parent;
		if (y->parent==NULL)
			this->root=q;
		else
		{
			if (y==y->parent->left)
				y->parent->left=q;
			else
				y->parent->right=q;
		}
		if (y!=p)
		{
			p->color=y->color;
			p->key=y->key;
			p->val=y->val;
		}
		if (y->color==BLACK)
			deleteRBFixup(q);
}

#endif /* ifndef RBTree_HPP_ */
