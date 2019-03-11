#ifndef LINKPOLYNOMIAL_H
#define LINKPOLYNOMIAL_H
#include "data_struct.h"
Status create_LinkPolynomial(LinkList& L);//创建多项式 
Status search(LinkList L,int spow,int &snum);//查找某一元素 
Status DestroyLink(LinkList &L);//销毁多项式 
Status ClearLink(LinkList &L);//清空多项式 
Status show_Link(LinkList L);//显示多项式 
Status addLink(LinkList &L,LinkList a,LinkList b);//多项式加法 
Status subLink(LinkList &L,LinkList a,LinkList b);//多项式减法 
LinkList derivate_linkPolynomial(LinkList L);//多项式求导 
LinkList MultLink(LinkList L1,LinkList L2);//多项式相乘 

#endif // LINKPOLYNOMIAL_H

