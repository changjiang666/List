#pragma once
#define OK 1
#define ERROR 0

//data  
typedef int Status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef Node *LinkList;

//operation
Status GetElem(LinkList L, int i, ElemType *e); 
Status ListInsert(LinkList L, int i, ElemType e);
Status LinkDelete(LinkList L, int i, ElemType *e);
LinkList CreateLinkHead(int n);
LinkList CreateLinkTail(int n);
Status ClearList(LinkList L);

