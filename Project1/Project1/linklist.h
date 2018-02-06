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

 Position Linklist_Create();                               //��������
void Linklist_Print(List L);                              //��ӡ����
int Linklist_IsEmpty(List L);                             //�鿴�����Ƿ�Ϊ��
int Linklist_IsLast(Position P, List L);                  //�鿴λ��P�Ƿ�ΪL�����һ���ڵ�
Position Linklist_Find(ElementType X, List L);            //������L���ҵ�Ԫ��X��λ��
Position Linklist_FindPrevious(ElementType X, List L);    //������L���ҵ�Ԫ��X֮ǰ��λ��
Position Linklist_Delete(ElementType X, List L);          //������L��ɾ��Ԫ��X
void Linklist_Insert(ElementType X, Position P, List L);  //������L��Pλ�ú����Ԫ��X

#endif // !__LINKLIST_H

