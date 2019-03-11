#ifndef LISTOPT_H
#define LISTOPT_H
#include "data_struct.h"
Status InitList_Sq(SqList &L);//创建线性表 
Status DeleteList_Sq(SqList &L);//删除线性表 
Status Get(SqList L,int i,ElemType &e);//取得线性表中第i个元素 
Status emptyList_Sq(SqList &L);//清空线性表 

#endif // LISTOPT_H

