#ifndef VECTOR_CAL_H
#define VECTOR_CAL_H
#include "data_struct.h"
#include "listopt.h"
Status create_vector(SqList &L);
//创建向量

Status show_vector(SqList L);
//显示向量

SqList add(SqList a,SqList b);
//向量加和

SqList sub(SqList a,SqList b);
//向量相减

Status mult(int &n,SqList a,SqList b);
//向量乘法

Status mode(double &n,SqList a);
//向量求模

Status cosangle(double &a,SqList L1,SqList L2);
//计算夹角余弦值

#endif // VECTOR_CAL_H

