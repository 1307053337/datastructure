#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct node
{
	ElementType data;
	struct node *next;
}*Stack;

int Stack_IsEmpty(Stack S);

#endif // !__STACK_H

