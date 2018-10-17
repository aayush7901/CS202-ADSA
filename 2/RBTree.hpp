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
	void deleteRBFixup(BinaryNode<Key,Value>* x, BinaryNode<Key,Value>* xparent, bool xIsLeft);
public:
	RBTree()
	{
		this->root=NULL;
	}
	void insert(const Key& key, const Value& value);
	void deleteKey(const Key& key);
	void printrbtree();
	BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value> *g);
	BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value> *g);
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
	BinaryNode<Key,Value>* getRoot();
};

template<class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::getRoot()
{
	return (this->root);
}

template<class Key,class Value>
int size(BinaryNode<Key,Value>* p)
{
	if (p==NULL)
		return 0;
	return 1+size(p->left)+size(p->right);
}

template<class Key,class Value>
void sizeUpdate(BinaryNode<Key,Value>* p)
{
	while (p!=NULL)
	{
		p->size=1+size(p->left)+size(p->right);
		p=p->parent;
	}
}

template <class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::rightRotate(BinaryNode<Key,Value>* g)
{
	BinaryNode<Key,Value> *p=g->left;
	p->parent=g->parent;
	if (g->parent==NULL) // g root
		this->root=p;
	else if (g->parent->left==g) //g left child
		g->parent->left=p;
	else if (g->parent->right==g) //g right child
		g->parent->right=p;
	BinaryNode<Key,Value> *rchild=p->right;
	if (rchild)
		rchild->parent=g;
	g->parent=p;
	g->left=rchild;
	p->right=g;
	return p;
}

template <class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::leftRotate(BinaryNode<Key,Value>* g)
{
	BinaryNode<Key,Value> *p=g->right;
	p->parent=g->parent;
	if (g->parent==NULL) // g root
		this->root=p;
	else if (g->parent->left==g) //g left child
		g->parent->left=p;
	else if (g->parent->right==g) //g right child
		g->parent->right=p;
	BinaryNode<Key,Value> *lchild=p->left;
	if (lchild)
		lchild->parent=g;
	g->parent=p;
	g->right=lchild;
	p->left=g;
	return p;
}

template <class Key, class Value>
void RBTree<Key,Value>::insertRBFixup(BinaryNode<Key,Value>* p)
{
	if (p==this->root)
		p->color=BLACK;
	else if (p->parent->color!=BLACK)  // problem only when parent is red of red
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
	this->root->color=BLACK;
}

template <class Key, class Value>
void RBTree<Key,Value>::insert(const Key& key, const Value& value)
{
	this->root = putUtil(this->root,key,value); 	// BST Insert
	BinaryNode<Key,Value> *p = findUtil(this->root, key);
	p->color=RED; 		// set color of inserted node to RED
	p->size=1;
	insertRBFixup(p); 	// recolor or rotate
	sizeUpdate(p);
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
bool isRed(BinaryNode<Key,Value> *p)
{
	if (p==NULL)
		return false;
	return (p->color==RED);
}

template <class Key, class Value>
bool isBlack(BinaryNode<Key,Value> *p)
{
	if (p==NULL)
		return true;
	return (p->color==BLACK);
}

template <class Key, class Value>
void RBTree<Key,Value> :: deleteRBFixup(BinaryNode<Key,Value>* x, BinaryNode<Key,Value>* xparent, bool xIsLeft)
{
	BinaryNode<Key,Value> *w;
	while (x!=this->root && isBlack(x))
	{
		if (xIsLeft)
		{
			w=xparent->right;	// w is sibling
			if (isRed(w))
			{
				w->color=BLACK;
				xparent->color=RED;
				leftRotate(xparent);
				w=xparent->right;
			}
			if (isBlack(w->left) && isBlack(w->right))
			{
				w->color=RED;
				x=xparent;
				xparent=x->parent;
				xIsLeft=(xparent!=NULL && x==xparent->left);
			}
			else
			{
				if (isBlack(w->right))
				{
					w->left->color=BLACK;
					w->color=RED;
					rightRotate(w);
					w=xparent->right;
				}
				w->color=xparent->color;
				xparent->color=BLACK;
				if (w->right!=NULL)
					w->right->color=BLACK;
				leftRotate(xparent);
				x=this->root;
				xparent=NULL;
			}
		}
		else
		{
			w=xparent->left;	// w is sibling
			if (isRed(w))
			{
				w->color=BLACK;
				xparent->color=RED;
				rightRotate(xparent);
				w=xparent->left;
			}
			if (isBlack(w->right) && isBlack(w->left))
			{
				w->color=RED;
				x=xparent;
				xparent=x->parent;
				xIsLeft=(xparent!=NULL && x==x->parent->left);
			}
			else
			{
				if (isBlack(w->left))
				{
					w->right->color=BLACK;
					w->color=RED;
					leftRotate(w);
					w=xparent->left;
				}
				w->color=xparent->color;
				xparent->color=BLACK;
				if (w->left!=NULL)
					w->left->color=BLACK;
				rightRotate(xparent);
				x=this->root;
				xparent=NULL;
			}
		}
	}
	if (x!=NULL)
		x->color=BLACK;
}

template<class Key, class Value>
void RBTree<Key, Value>::deleteKey(const Key& key)
{
	BinaryNode<Key,Value> *xparent, *x, *y, *p = findUtil(this->root, key);
	if (p->left==NULL || p->right==NULL)  // always delete single child or no child node y
		y=p;
	else
		y=findUtil(this->root,succUtil(this->root,p));
	if (y->left)	// x is child of y that replaces y
		x=y->left;
	else
		x=y->right;
	if (x!=NULL)
		x->parent=y->parent;
	xparent=y->parent;   // used to pass parent to fixup when x is null
	bool yIsLeft=false;
	if (y->parent==NULL)
		this->root=x;
	else if (y->parent->left==y)
	{
		y->parent->left=x;
		yIsLeft=true;
	}
	else
	{
		y->parent->right=x;
		yIsLeft=false;
	}
	if (y!=p)				//replace contents of succ y to p and then delete y
	{
		p->key=y->key;
		p->val=y->val;
	}
	if (y->color==BLACK)   // fixup needed only when node deleted was black
		deleteRBFixup(x,xparent,yIsLeft);  //xparent,yIsLeft is passed for cases where x is NIL node as this code does not use NIL node implementation
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
	std::cout<<this->root->color<<"\n";
	printrb(this->root);
}

#endif /* ifndef RBTree_HPP_ */
