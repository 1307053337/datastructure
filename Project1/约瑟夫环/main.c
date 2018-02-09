#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}*Node,*Linklist;

Linklist Looplist_Create(int n)
{
	Node p1, p2, head;
	int i = 1;
	p1 = NULL;
	p2 = NULL;
	head = NULL;
	p1 = (Node)malloc(sizeof(struct Node));
	if (p1 == NULL)
	{
		return NULL;
	}
	else
	{
		p1->data = i;
		head = p1;
		p1->next = head;
		p2 = p1;
	}
	while (i < n)
	{
		p1= (Node)malloc(sizeof(struct Node));
		if (p1 == NULL)
		{
			return NULL;
		}
		else
		{
			i++;
			p1->data=i;
			p2->next = p1;
			p2 = p1;
			p2->next = head;
		}
	}
	return head;
	
}

Node Looplist_Delete(Node p, int a)
{
	int i=1;
	Node ptr = NULL;
	while (i != a-1)
	{
		p = p->next;
		i++;
	}
	ptr = p->next;
	printf("-> %d ->", ptr->data);
	p->next = ptr->next;
	free(ptr);
	return p->next;
}

int Looplist_Num(Linklist L)
{
	Node p = L;
	int n = 1;
	if (L == NULL)
		return -1;
	while (p->next != L)
	{
		n++;
		p = p->next;
	}
	return n;
}

int Yousefu(Linklist L, int n, int m) //m:Ô¤ÖÃÊı£¬n:Á´±íÊı
{
	int i = 0;
	int x;
	Node p = L;
	while (Looplist_Num != 1)
	{
		x = m % n;
		p = Looplist_Delete(p, x);
		n = Looplist_Num(p);
	}
	return x;
}

int main()
{
	int n = 6,m=11;
	Linklist L;
	L = Looplist_Create(n);
	Yousefu(L, n, m);
	return 0;
}