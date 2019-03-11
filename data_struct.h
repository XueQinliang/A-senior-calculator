#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <stack>
#include <string>
#include <fstream>
#include <direct.h>
#include <memory.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVER_FLOW -2
#define Tmax 0x7fffffff
#define Tmin 0x80000000
#define LIST_INT_SIZE 100
#define STACK_INIT_SIZE 100

//需要的一些常量和数据结构的定义 

using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType *elem=NULL;
    int length;
    int listsize;
}SqList;

typedef struct LNode{
    ElemType num;
    ElemType pow;
    struct LNode *next=NULL;
}LNode, *LinkList;

template<class T>
struct SqStack{
    T *base;
    T *top;
    int stacksize;
};

struct function{
    char name[20]={0};
    pair<char*,double> p[10];
    int varinum=0;
    char expression[100]={0};
};

struct matrix{
    double **data;
    int col,row;
};
#endif // DATA_STRUCT_H

