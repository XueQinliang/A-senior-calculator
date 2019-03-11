#include "vector_cal.h"
Status create_vector(SqList &L){
    int num,i;
    for(i=0;;i++){
        if(i>=L.listsize){//��������Ĵ�С�����˷���Ŀռ��С
            ElemType* newbase=(ElemType*)realloc(L.elem,(L.listsize<<1)*sizeof(ElemType));//���·����ڴ�ռ�
            if(!newbase) exit(OVERFLOW);
            L.elem=newbase;
            L.listsize=L.listsize<<1;//�ռ��С����
        }
        scanf("%d",&num);
        L.elem[i]=num;
        char c=getchar();
        if(c=='\n') break;//�ж��������
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
    if(a.length!=b.length){//���������С����
        cout<<"error\n";
        L.elem=NULL;
        L.length=0;
        L.listsize=0;
        return L;
    }
    else {
        InitList_Sq(L);
        for(int i=0;i<a.length;i++){
            L.elem[i]=a.elem[i]+b.elem[i];//��Ӧ�����
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
    if(a.length!=b.length){//��С�����޷����
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
    if(a.elem==NULL){//����û�з���ռ��޷���ģ��Ҫ�ж�
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
    a=1.0*m/(1.0*mode1*mode2);//����ѧ��ʽ�����еĺ���
    return OK;
}

