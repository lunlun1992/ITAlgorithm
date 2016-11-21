#include <stdio.h>
#include <stdlib.h>


struct Set
{
	void *head;
	void *tail;
	int nNodes;
};

struct Node
{
	struct Set *s;
	char c;
	struct Node *next;
};

typedef struct Node Node;
typedef struct Set Set;
void make_set(Set *s, Node *n)
{
	(Node *)(s->head) = n;
	s->nNodes = 1;
	(Node *)(s->tail) = n;
	n->s = s;
	n->next = NULL;
}

Set *find_set(Node *n)
{
	return n->s;
}

void uni(Node *n1, Node *n2)
{
	if (n1->s == n2->s)
		return;
	if (n1->s->nNodes < n2->s->nNodes)
	{
		Node *n = (Node *)(n1->s->head);
		Set *ss = n1->s;
		while (n != NULL)
		{
			n->s = n2->s;
			n->next = NULL;
			((Node *)(n2->s->tail))->next = n;
			(Node *)(n2->s->tail) = n;
			n2->s->nNodes++;
			n = n->next;
		}
		free(ss);
	}
	else
	{
		Node *n = (Node *)(n2->s->head);
		Set *ss = n2->s;
		while (n != NULL)
		{
			n->s = n1->s;
			n->next = NULL;
			((Node *)(n1->s->tail))->next = n;
			(Node *)(n1->s->tail) = n;
			n1->s->nNodes++;
			n = n->next;
		}
		free(ss);
	}
}

int main()
{
	int i;
	Set *sarr[100];
	for (i = 0; i < 11; i++)
	{
		Node *node = (Node *)malloc(sizeof(Node));
		sarr[i] = (Set *)malloc(sizeof(Set));
		node->c = 'a' + i;
		node->s = NULL;
		node->next = NULL;
		make_set(sarr[i], node);
	}
	for (i = 1; i < 11; i++)
	{
		uni((Node *)(sarr[0]->head), (Node *)(sarr[i]->head));
	}
	Node *n = sarr[0]->head;
	return 0;
}