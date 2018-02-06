#include "stack.h"

/*If empty return true*/
int Stack_IsEmpty(Stack S)
{
	return S->next == NULL;
}

ElementType Stack_Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->data;
	}
	else
	{
		printf("Stack is empty");
		exit(1);
	}
}
ElementType Stack_Pop(Stack S)
{
	ElementType X;
	Stack head = S;
	Stack p = NULL;
	if (IsEmpty(S))
	{
		printf_s("Stack is empty now");
		exit(1);
	}
	else
	{
		X = head->data;
		p = head->next;
		head->next = p->next;
		free(p);
		p = NULL;
		return X;
	}
}

void Stack_MakeEmpty(Stack S)
{
	if (IsEmpty(S))
	{
		printf("Stack is empty");
		exit(1);
	}
	else
	{
		while (!IsEmpty(S))
		{
			Pop(S);
		}
	}
}

Stack Stack_Push(Stack S)
{
	Stack head = NULL;
	Stack p= NULL;
	p = (Stack)malloc(sizeof(struct node));
	if (p == NULL)
	{
		printf("Error");
		exit(1);
	}
	else
	{
		scanf_s("%d", &(p->data));
	}

}