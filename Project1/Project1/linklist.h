#ifndef __LINKLIST_H
#define __LINKLIST_H
#include <stdio.h>
#include <malloc.h>
typedef int ElementType;

typedef struct Node
{
	ElementType data;
	struct Node *next;
}*List,*Position,node;

 Position Linklist_Create();                               //创建链表
void Linklist_Print(List L);                              //打印链表
int Linklist_IsEmpty(List L);                             //查看链表是否为空
int Linklist_IsLast(Position P, List L);                  //查看位置P是否为L的最后一个节点
Position Linklist_Find(ElementType X, List L);            //在链表L中找到元素X的位置
Position Linklist_FindPrevious(ElementType X, List L);    //在链表L中找到元素X之前的位置
Position Linklist_Delete(ElementType X, List L);          //在链表L中删除元素X
void Linklist_Insert(ElementType X, Position P, List L);  //在链表L的P位置后插入元素X

#endif // !__LINKLIST_H

