#pragma once
#define ERROR 0
#define OK 1
#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;

//data
typedef struct
{
	ElemType data;
	int cur;
}StaticLinkList[MAXSIZE];

//operations
Status InitSSL(StaticLinkList space);      ///
int malloc_SSL(StaticLinkList space);
int ListLength(StaticLinkList space);
Status InsertSSL(StaticLinkList space, int i, ElemType e);
void free_SSL(StaticLinkList space, int i); //删除第i个结点  
Status DeleteSSL(StaticLinkList space, int i, ElemType *e);
Status SetSSL(StaticLinkList space, int n);    ///