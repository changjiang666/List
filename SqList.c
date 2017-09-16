
#include "SqList.h"

Status GetElem(SqList L, int i, ElemType *e)
{
	if (i < 1 || i > L.length || !L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int j = L ->length - 1;
	if (i < 1 || i > L->length + 1)
		return ERROR;
	if (i < L->length)
		for (; j > i - 2; --j)
			L->data[j + 1] = L->data[j];
	L->data[i-1] = e;
	++L->length;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	if (i < 1 || i > L->length || !L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
		for (; i < L->length; ++i)
			L->data[i - 1] = L->data[i];
	--L->length;
	return OK;
}

Status InitList(SqList *L)
{
	int i = 0;
	L->length = 0;
	for (; i < INITLEN; ++i)
	{
		L->data[i] = i;
		++L->length;
	}
	return OK;
}

Status ListIsEmpty(SqList L)
{
	return (L.length) ? FALSE : TRUE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

Index LocateElem(SqList L, ElemType e)
{
	int i = 0;
	for (; i < L.length; ++i)
		if (L.data[i] == e)
			return i;
	return NOTFOUND;
}

