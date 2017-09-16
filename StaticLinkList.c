#include "StaticLinkList.h"
#include <time.h>

Status InitSSL(StaticLinkList space)
{
	int i = 0;
	for (; i < MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int malloc_SSL(StaticLinkList space)
{
	int index = space[0].cur;
	if (!index)
		return ERROR;
	space[0].cur = space[index].cur;
	return index;

}

int ListLength(StaticLinkList space)
{
	int length = 0;
	int i = space[MAXSIZE - 1].cur;
	while (i)
	{
		++length;
		i = space[i].cur;
	}
	return length;
}

Status InsertSSL(StaticLinkList space, int i, ElemType e)
{
	int place;
	int index = space[MAXSIZE - 1].cur, j = 1;
	if (!index)
		return ERROR;
	if (i < 1 || i > ListLength(space) + 1)
		return ERROR;
	place = malloc_SSL(space);
	if (place)	//if found
	{
		space[place].data = e;
		for (; j < i - 1; ++j)
			index = space[index].cur;
		space[place].cur = space[index].cur;
		space[index].cur = place;
		return OK;
	}
	return ERROR;
}


void free_SSL(StaticLinkList space, int i)
{
	space[i].cur = space[0].cur;
	space[0].cur = i;
}

Status DeleteSSL(StaticLinkList space, int i, ElemType *e)
{
	int j = 1, tmp;
	int index = space[MAXSIZE - 1].cur;
	if (!index)
		return ERROR;
	if (i < 1 || i > ListLength(space))
		return ERROR;
	for (; j < i - 1; ++j)
		index = space[index].cur;
	tmp = space[index].cur;
	*e = space[tmp].data;
	space[index].cur = space[tmp].cur;
	free_SSL(space, i);
	return OK;	
}

Status SetSSL(StaticLinkList space, int n)
{
	int i = 1;
	srand(time(NULL));
	for (; i < n + 1; ++i)
	{
		space[i].data = rand() % 100;
	}
	space[n].cur = 0;
	space[0].cur = n + 1;
	space[MAXSIZE - 1].cur = 1;
	return OK;
}