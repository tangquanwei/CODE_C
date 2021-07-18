#ifndef _ARRAY_H_
#define _ARRAY_H_
#define MAXSIZE 20
#include <stdbool.h>

typedef int ElemType;

typedef struct item
{
    ElemType date[MAXSIZE];
    int length;
} SqList;

bool Init(SqList *L);

bool isEmpty(SqList L);

bool Clean(SqList *L);

void GetElem(SqList L, int i, ElemType e);

bool LocateElem(SqList L, ElemType e);

bool Insert(SqList *L, int i, ElemType e);

bool Delete(SqList *L, int i, ElemType e);

bool Length(SqList L);

#endif