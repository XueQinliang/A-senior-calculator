#ifndef LINKPOLYNOMIAL_H
#define LINKPOLYNOMIAL_H
#include "data_struct.h"
Status create_LinkPolynomial(LinkList& L);//��������ʽ 
Status search(LinkList L,int spow,int &snum);//����ĳһԪ�� 
Status DestroyLink(LinkList &L);//���ٶ���ʽ 
Status ClearLink(LinkList &L);//��ն���ʽ 
Status show_Link(LinkList L);//��ʾ����ʽ 
Status addLink(LinkList &L,LinkList a,LinkList b);//����ʽ�ӷ� 
Status subLink(LinkList &L,LinkList a,LinkList b);//����ʽ���� 
LinkList derivate_linkPolynomial(LinkList L);//����ʽ�� 
LinkList MultLink(LinkList L1,LinkList L2);//����ʽ��� 

#endif // LINKPOLYNOMIAL_H

