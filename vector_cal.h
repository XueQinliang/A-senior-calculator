#ifndef VECTOR_CAL_H
#define VECTOR_CAL_H
#include "data_struct.h"
#include "listopt.h"
Status create_vector(SqList &L);
//��������

Status show_vector(SqList L);
//��ʾ����

SqList add(SqList a,SqList b);
//�����Ӻ�

SqList sub(SqList a,SqList b);
//�������

Status mult(int &n,SqList a,SqList b);
//�����˷�

Status mode(double &n,SqList a);
//������ģ

Status cosangle(double &a,SqList L1,SqList L2);
//����н�����ֵ

#endif // VECTOR_CAL_H

