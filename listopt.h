#ifndef LISTOPT_H
#define LISTOPT_H
#include "data_struct.h"
Status InitList_Sq(SqList &L);//�������Ա� 
Status DeleteList_Sq(SqList &L);//ɾ�����Ա� 
Status Get(SqList L,int i,ElemType &e);//ȡ�����Ա��е�i��Ԫ�� 
Status emptyList_Sq(SqList &L);//������Ա� 

#endif // LISTOPT_H

