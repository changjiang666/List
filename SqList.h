#pragma once
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INITLEN 20
#define NOTFOUND -1
typedef int ElemType;
typedef int Status;
typedef int Index;

//data
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//operation
Status GetElem(SqList L, int i, ElemType *e);   //
Status ListInsert(SqList *L, int i, ElemType e);  //
Status ListDelete(SqList *L, int i, ElemType *e); //
Status InitList(SqList *L);   //
Status ListIsEmpty(SqList L);  //
Status ClearList(SqList *L);    //
Index LocateElem(SqList L, ElemType e);  //




