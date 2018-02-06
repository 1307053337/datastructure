
#include "linklist.h"

/*create list end of num 0*/
Position Linklist_Create()
{
	int n;
	Position head, p1, p2;
	head = NULL;
	p1 = NULL;   //开辟新节点
	p2 = NULL;   //保留原链表最后一个元素
	n = 0;       //节点数
	p1 = (Position)malloc(sizeof(node));
	if (p1 == NULL)
	{
		printf_s("Error\n");
		return NULL;
	}
	else
	{
		n++;
		printf_s("please input data %d \n",n);
		scanf_s("%d", &(p1->data));
		p2 = p1;
	
		while (p1->data != 0)
		{
			if (n == 1)
			{
				head = p1;
				p2->next = NULL;
			}
			else
			{
				p2->next = p1;
			}
			p2 = p1;
			p1 = (Position)malloc(sizeof(node));
			n++;
			if (p1==NULL)
			{
				printf_s("Error");
				return NULL;
			}
			else
			{
				printf_s("please input data %d\n",n);
				scanf_s("%d", &(p1->data));
			}
			
		}
		p2->next = NULL;
		free(p1);
		p1 = NULL;
		return head;
	}


	return head;
}

/*print list L*/
void Linklist_Print(List L)
{
	Position p;
	int n;
	p = L;
	n = 1;
	if (L == NULL)
	{
		printf_s("NULL\n");
	}
	else
	{
		printf_s("This is the List\n");
		while (p!= NULL)
		{
			printf_s("node %d : postion %o data %d next %o\n", n++, p, p->data, p->next);
			p = p->next;
		}
	}

}
/*Return true if L is empty*/
int Linklist_IsEmpty(List L)
{
	return L->next == NULL;
}

/*Return true if P is the last postion in list L*/
int Linklist_IsLast(Position P, List L)
{
	return L->next == NULL;
}

/*Return first postion of X in list L*/
Position Linklist_Find(ElementType X, List L)
{
	Position P;
	P = L->next;
	while (P != NULL && P->data != X)
	{
		P = P->next;
	}
	return P;
}

Position Linklist_FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P ->next!= NULL && P->next->data != X)
	{
		P = P->next;
	}
	return P;
}

/*Delete first X from a list*/
Position Linklist_Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->next;
		P->next = TmpCell->next;
		free(TmpCell);
	}
	return L;
}

/*Insert X after legal Postion P in list L*/
void Linklist_Insert(ElementType X, Position P, List L)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(node));
	if (TmpCell == NULL)
	{
		printf_s("Error");
		exit(1);
	}
	TmpCell->data = X;
	TmpCell->next = P->next;
	P->next = TmpCell;
}
