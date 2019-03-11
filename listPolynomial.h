#ifndef LISTPOLYNOMIAL_H
#define LISTPOLYNOMIAL_H
#include "data_struct.h"
#include "listopt.h"
Status createPolynomial(SqList &L);//创建多项式 
Status addPolynomial(SqList &L,SqList a,SqList b);//多项式加法 
Status subPolynomial(SqList &L,SqList a,SqList b);//多项式减法 
SqList derivate_Polynomial(SqList a);//多项式求导 
SqList multPolynomial(SqList a,SqList b);//多项式相乘 
Status showPolynomial(SqList L);//显示多项式 
#endif // LISTPOLYNOMIAL_H

