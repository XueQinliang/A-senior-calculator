#include "vector_cal.h"
Status create_vector(SqList &L){
    int num,i;
    for(i=0;;i++){
        if(i>=L.listsize){//如果向量的大小超过了分配的空间大小
            ElemType* newbase=(ElemType*)realloc(L.elem,(L.listsize<<1)*sizeof(ElemType));//重新分配内存空间
            if(!newbase) exit(OVERFLOW);
            L.elem=newbase;
            L.listsize=L.listsize<<1;//空间大小翻倍
        }
        scanf("%d",&num);
        L.elem[i]=num;
        char c=getchar();
        if(c=='\n') break;//判断输入结束
    }
    L.length=i+1;
}
Status show_vector(SqList L){
    if(L.elem==NULL)
        return ERROR;
    cout<<"(";
    for(int i=0;i<L.length;i++){
        cout<<L.elem[i];
        if(i!=L.length-1)
            cout<<" ";
        else cout<<")";
    }
}
SqList add(SqList a,SqList b){
    SqList L;
    if(a.length!=b.length){//如果向量大小不等
        cout<<"error\n";
        L.elem=NULL;
        L.length=0;
        L.listsize=0;
        return L;
    }
    else {
        InitList_Sq(L);
        for(int i=0;i<a.length;i++){
            L.elem[i]=a.elem[i]+b.elem[i];//对应项相加
        }
        L.length=a.length;
        return L;
    }
}
SqList sub(SqList a,SqList b){
    SqList L;
    if(a.length!=b.length){
        cout<<"error\n";
        L.elem=NULL;
        L.length=0;
        L.listsize=0;
        return L;
    }
    else {
        InitList_Sq(L);
        for(int i=0;i<a.length;i++){
            L.elem[i]=a.elem[i]-b.elem[i];
        }
        L.length=a.length;
        return L;
    }
}
Status mult(int &n,SqList a,SqList b){
    if(a.length!=b.length){//大小不等无法相乘
        cout<<"error\n";
        return ERROR;
    }
    else {
        n=0;
        for(int i=0;i<a.length;i++){
            n+=a.elem[i]*b.elem[i];
        }
        return OK;
    }
}
Status mode(double &n,SqList a){
    if(a.elem==NULL){//向量没有分配空间无法求模，要判断
        cout<<"error\n";
        return ERROR;
    }
    else {
        n=0;
        for(int i=0;i<a.length;i++){
            n+=a.elem[i]*a.elem[i];
        }
        n=sqrt(n);
        return OK;
    }
}
Status cosangle(double &a,SqList L1,SqList L2){
    int m;
    mult(m,L1,L2);
    double mode1,mode2;
    mode(mode1,L1);
    mode(mode2,L2);
    a=1.0*m/(1.0*mode1*mode2);//用数学公式和已有的函数
    return OK;
}

