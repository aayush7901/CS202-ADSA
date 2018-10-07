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
	void printrbtree();
	BinaryNode<Key,Value>* deleteHelper(BinaryNode<Key,Value>* p, const Key& key);
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
			{
				rightRotate(gpa);
				swap(pa->color, gpa->color);
			}
			else if (p==pa->right && pa==gpa->right) //RR
			{
				leftRotate(gpa);
				swap(pa->color, gpa->color);
			}
			else if (p==pa->right && pa==gpa->left) //LR
			{
				leftRotate(pa);
				rightRotate(gpa);
				swap(p->color, gpa->color);
			}
			else if (p==pa->left && pa==gpa->right) //RL
			{
				rightRotate(pa);
				leftRotate(gpa);
				swap(p->color, gpa->color);
			}
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
int getColor(BinaryNode<Key,Value>* p)
{
	if (p==NULL)
		return BLACK;
	return p->color;
}

template <class Key, class Value>
void setColor(BinaryNode<Key,Value>* p, Color color)
{
	if (p==NULL)
		return;
	p->color=color;
}

template <class Key, class Value>
void RBTree<Key,Value>::deleteRBFixup(BinaryNode<Key,Value>* p)
{
	if (p==NULL) // Not found
		return;
	if (p==this->root)  // root to delete when only one node present
	{
		this->root=NULL;
		return;
	}
	if (getColor(p)==RED || getColor(p->left)==RED || getColor(p->right)==RED)
	{
		BinaryNode<Key,Value> *child;
		if (p->left!=NULL)
			child=p->left;
		else
			child=p->right;
		if (p==p->parent->left)
			p->parent->left=child;
		else
			p->parent->right=child;
		if (child!=NULL)
			child->parent=p->parent;
		setColor(child,BLACK);
		delete p;
	}
	else
	{
		BinaryNode<Key,Value> *sib= NULL;
		BinaryNode<Key,Value> *pa=NULL;
		BinaryNode<Key,Value> *ptr=p;
		setColor(ptr,DOUBLE_BLACK);
		while (ptr!=this->root && ptr->color==DOUBLE_BLACK)
		{
			pa=ptr->parent;
			if (ptr==pa->left)
			{
				sib=pa->right;
				if (getColor(sib)==RED)
				{
					setColor(sib,BLACK);
					setColor(pa,RED);
					leftRotate(pa);
				}
				else
				{
					if (getColor(sib->left)==BLACK && getColor(sib->right)==BLACK)
					{
						setColor(sib,RED);
						if(getColor(pa)==RED)
							setColor(pa,BLACK);
						else
							setColor(pa,DOUBLE_BLACK);
						ptr=pa;
					}
					else
					{
						if (getColor(sib->right)==BLACK)
						{
							setColor(sib->left,BLACK);
							setColor(sib,RED);
							rightRotate(sib);
							sib=pa->right;
						}
						setColor(sib,pa->color);
						setColor(pa,BLACK);
						setColor(sib->right,BLACK);
						leftRotate(pa);
						break;
					}
				}
			}
			else
			{
				sib=pa->left;
				if (getColor(sib)==RED)
				{
					setColor(sib,BLACK);
					setColor(pa,RED);
					rightRotate(pa);
				}
				else
				{
					if (getColor(sib->left)==BLACK && getColor(sib->right)==BLACK)
					{
						setColor(sib,RED);
						if(getColor(pa)==RED)
							setColor(pa,BLACK);
						else
							setColor(pa,DOUBLE_BLACK);
						ptr=pa;
					}
					else
					{
						if (getColor(sib->left)==BLACK)
						{
							setColor(sib->right,BLACK);
							setColor(sib,RED);
							leftRotate(sib);
							sib=pa->left;
						}
						setColor(sib,pa->color);
						setColor(pa,BLACK);
						setColor(sib->left,BLACK);
						rightRotate(pa);
						break;
					}
				}
			}
		}
		if (p==p->parent->left)
			p->parent->left=NULL;
		else
			p->parent->right=NULL;
		delete p;
		setColor(this->root, BLACK);
	}
}

template <class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::deleteHelper(BinaryNode<Key,Value>* p, const Key& key)
{
	if (p==NULL)
		return p;
	if (key<p->key)
		return deleteHelper(p->left,key);
	if (key>p->key)
		return deleteHelper(p->right,key);
	if (p->left==NULL || p->right==NULL)
		return p;
	BinaryNode<Key,Value>*tmp=findUtil(this->root,succUtil(this->root,p));
	p->key=tmp->key;
	p->val=tmp->val;
	return deleteHelper(p->right, key);
}

template <class Key, class Value>
void RBTree<Key,Value>::deleteKey(const Key& key)
{
	BinaryNode<Key,Value> *p = deleteHelper(this->root, key);
	deleteRBFixup(p);
}

template <class Key, class Value>
void printrb(BinaryNode<Key,Value> *root)
{
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->val)<<" "<<(root->color)<<"\n";
	printrb(root->left);
	printrb(root->right);
}

template <class Key, class Value>
void RBTree<Key,Value> :: printrbtree()
{
//	std::cout<<this->root->color<<"\n";
	printrb(this->root);
}

#endif /* ifndef RBTree_HPP_ */
