#include "listopt.h"
Status InitList_Sq(SqList &L){
    L.elem=(ElemType*)malloc(LIST_INT_SIZE*sizeof(ElemType));
    if(!L.elem) exit(OVER_FLOW);//如果分配失败返回溢出
    L.length=0;
    L.listsize=LIST_INT_SIZE;
    return OK;
}
Status DeleteList_Sq(SqList &L){
    if(L.elem==NULL) return ERROR;
    delete[] L.elem;
    return OK;
}
Status Get(SqList L,int i,ElemType &e){
    if(i>L.length||i<0) {
        cout<<"error\n";
        return ERROR;
    }
    e=L.elem[i];
    return OK;
}
Status emptyList_Sq(SqList &L){
    memset(L.elem,0,sizeof(L.elem)*L.length);//全部置为0
    L.length=0;
    return OK;
}

