#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int key;
	struct Node *p;
	struct Node *l;
	struct Node *r;
};
class BSTree
{
public:
	Node *T;
	BSTree();
	~BSTree();
	void insert(Node *now, Node *in);
	void del(Node *d);
	Node *findMinimum(Node *n);
	Node *findMaximum(Node *n);
	Node *findKey(int key);
	Node *findsuc(Node *n);
	Node *findpre(Node *n);
private:
	int nNodes;
};

BSTree::BSTree()
{
	T = NULL;
	nNodes = 0;
}

BSTree::~BSTree()
{
}

void BSTree::insert(Node *now, Node * in)
{
	if (now == NULL)
	{
		T = in;
		nNodes++;
		return;
	}
	else if (now->key > in->key)
	{
		if (now->l != NULL)
			insert(now->l, in);
		else
		{
			in->p = now;
			now->l = in;
			nNodes++;
			return;
		}
	}
	else
	{
		if (now->r != NULL)
			insert(now->r, in);
		else
		{
			in->p = now;
			now->r = in;
			nNodes++;
			return;
		}
	}
}

void BSTree::del(Node * d)
{
	if (d->l == NULL)
	{
		if (d->p == NULL)
		{
			T = d->r;
			return;
		}
		if (d->r != NULL)
			d->r->p = d->p;
		if (d->key < d->p->key)
			d->p->l = d->r;
		else
			d->p->r = d->r;
		free(d);
	}
	else if (d->r == NULL)
	{
		if (d->p == NULL)
		{
			T = d->l;
			return;
		}
		if (d->l != NULL)
			d->l->p = d->p;
		if (d->key < d->p->key)
			d->p->l = d->l;
		else
			d->p->r = d->l;
		free(d);
	}
	else
	{
		Node *y = findsuc(d);
		if (y != d->r)
		{
			if (y->r != NULL)
				y->r->p = y->p;
			if (y->key < y->p->key)
				y->p->l = y->r;
			else
				y->p->r = y->r;
			y->r = d->r;
			y->r->p = y;
		}
		y->p = d->p;
		if (d->p == NULL)
			T = y;
		else if (d->key < d->p->key)
			d->p->l = y;
		else
			d->p->r = y;
		y->l = d->l;
		y->l->p = y;
		free(d);
	}
	nNodes--;
}

Node * BSTree::findMinimum(Node *n)
{
	if (T == NULL)
		return NULL;
	while (n->l != NULL)
		n = n->l;
	return n;
}

Node * BSTree::findMaximum(Node *n)
{
	if (T == NULL)
		return NULL;
	while (n->r != NULL)
		n = n->r;
	return n;
}

Node * BSTree::findKey(int key)
{
	Node *n = T;
	while (n != NULL)
	{
		if (n->key > key)
			n = n->l;
		else if (n->key < key)
			n = n->r;
		else
			return n;
	}
	return n;
}

Node * BSTree::findsuc(Node * n)
{
	if (n->r != NULL)
		return findMinimum(n->r);
	else
	{
		Node *y = n->p;
		while (y != NULL && y->l != n)
		{
			n = y;
			y = y->p;
		}
		return y;
	}
}

void printtree(Node *p, int blk)
{
	if (p == NULL) return;
	for (int i = 0; i < blk; i++)
		printf("    ");
	printf("|--<%d>\n", p->key);
	printtree(p->r, blk + 1);
	printtree(p->l, blk + 1);
}
int main()
{
	int num[13] = { 7, 2, 15, 1, 5, 10, 17, 4, 6, 8, 11, 16, 19 };
	Node *nn[13];
	BSTree bst = BSTree();
	for (int i = 0; i < 13; i++)
	{
		nn[i] = (Node *)malloc(sizeof(Node));
		nn[i]->l = NULL;
		nn[i]->r = NULL;
		nn[i]->p = NULL;
		nn[i]->key = num[i];
		bst.insert(bst.T, nn[i]);
	}
	printtree(bst.T, 0);
	printf("%d\n", bst.findMinimum(bst.T)->key);
	printf("%d\n", bst.findMaximum(bst.T)->key);
	if (bst.findKey(123))
		printf("yes\n");
	else
		printf("no\n");
	if (bst.findsuc(nn[2]))
		printf("%d\n", bst.findsuc(nn[2])->key);
	else
		printf("no\n");
	bst.del(nn[0]);
	printtree(bst.T, 0);
}