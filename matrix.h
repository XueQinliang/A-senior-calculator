#ifndef MATRIX_H
#define MATRIX_H
#include "data_struct.h"
Status Initmatrix(matrix& m);//创建矩阵 
Status transpose(matrix& newm,matrix m);//矩阵转置 
Status addmatrix(matrix &sum,matrix a,matrix b);//矩阵加法 
Status submatrix(matrix &sub,matrix a,matrix b);//矩阵减法 
Status multmatrix(matrix &c,matrix a,matrix b);//矩阵乘法 
double valuematrix(matrix m);//求行列式的值 
Status Rank(matrix m,int &mrank);//求矩阵的秩 
Status character(matrix m);//求矩阵的特征值 
Status showmatrix(matrix m);//显示矩阵 
Status freematrix(matrix& m);//删除矩阵 
#endif // MATRIX_H

