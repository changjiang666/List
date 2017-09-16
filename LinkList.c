#include "LinkList.h"
#include <time.h>

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList curr = L->next;
	while (curr && j < i)
	{
		curr = curr->next;
		++j;
	}
	if (!curr || j > i)
		return ERROR;
	*e = curr->data;
	return OK;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
	int j = 1;
	LinkList curr = L, s;
	while (curr && j < i)
	{
		curr = curr->next;
		++j;
	}
	if (!curr || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = curr->next;
	curr->next = s;
	return OK;
}

Status LinkDelete(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList curr = L, q;
	while (curr && j < i)
	{
		curr = curr->next;
		++j;
	}
	if (!curr || j > i)
		return ERROR;
	q = curr->next;
	*e = q->data;
	curr->next = q->next;
	free(q);
	return OK;
}

LinkList CreateLinkTail(int n)
{
	LinkList curr ,L, new;
	L = (LinkList)malloc(sizeof(Node));
	curr = L;
	int i = 0;
	srand(time(NULL));
	for (; i < n; ++i)
	{
		new = (LinkList)malloc(sizeof(Node));
		new->data = rand() % 100;
		curr->next = new;
		curr = new;
	}
	curr->next = NULL;
	return L;
}

LinkList CreateLinkHead(int n)
{
	LinkList new, L;
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	int i = 0;
	srand(time(NULL));
	for (; i < n; ++i)
	{
		new = (LinkList)malloc(sizeof(Node));
		new->data = rand() % 100;
		new->next = L->next;
		L->next = new;
	}
	return L;
}

Status ClearList(LinkList L)
{
	LinkList p, q;
	if (!L)
		return ERROR;
	p = L->next;
	q = L->next;
	while (!p)
	{
		p = q->next;
		free(q);
		q = p;
	}
	L->next = NULL;
	return OK;
}