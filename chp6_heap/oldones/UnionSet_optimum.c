#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char c;
	int rank;
	struct Node *p;
}Node;

void make_set(Node *n)
{
	n->p = n;
	n->rank = 0;
}

Node *find_set(Node *n)
{
	if (n != n->p)
		n->p = find_set(n->p);
	return n->p;//因为要返回赋值给n->p，所以返回n->p不返回n
}

void uni(Node *n1, Node *n2)
{
	Node *p1 = find_set(n1);
	Node *p2 = find_set(n2);
	if (p1->rank < p2->rank)
		p1->p = p2;
	else
	{
		p2->p = p1;
		if (p1->rank == p2->rank)	
			p1->rank++;
	}
}

