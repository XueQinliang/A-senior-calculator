#ifndef LISTPOLYNOMIAL_H
#define LISTPOLYNOMIAL_H
#include "data_struct.h"
#include "listopt.h"
Status createPolynomial(SqList &L);//��������ʽ 
Status addPolynomial(SqList &L,SqList a,SqList b);//����ʽ�ӷ� 
Status subPolynomial(SqList &L,SqList a,SqList b);//����ʽ���� 
SqList derivate_Polynomial(SqList a);//����ʽ�� 
SqList multPolynomial(SqList a,SqList b);//����ʽ��� 
Status showPolynomial(SqList L);//��ʾ����ʽ 
#endif // LISTPOLYNOMIAL_H

