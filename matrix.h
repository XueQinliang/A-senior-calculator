#ifndef MATRIX_H
#define MATRIX_H
#include "data_struct.h"
Status Initmatrix(matrix& m);//�������� 
Status transpose(matrix& newm,matrix m);//����ת�� 
Status addmatrix(matrix &sum,matrix a,matrix b);//����ӷ� 
Status submatrix(matrix &sub,matrix a,matrix b);//������� 
Status multmatrix(matrix &c,matrix a,matrix b);//����˷� 
double valuematrix(matrix m);//������ʽ��ֵ 
Status Rank(matrix m,int &mrank);//�������� 
Status character(matrix m);//����������ֵ 
Status showmatrix(matrix m);//��ʾ���� 
Status freematrix(matrix& m);//ɾ������ 
#endif // MATRIX_H

