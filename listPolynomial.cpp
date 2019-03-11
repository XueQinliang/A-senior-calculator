#include "listpolynomial.h"
Status createPolynomial(SqList &L){
    L.length=0;
    for(int i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    int sign=1;
    for(int i=0;i<L.listsize;i++){
        int num,pow;
        if(scanf("%dx^%d",&num,&pow)==2){//判断是否正常输入
            if(pow>=5000000){
                cout<<"error\n";
                return OVERFLOW;
            }
            if(pow>=L.listsize){//如果多项式指数大于现在线性表的空间
                ElemType* newbase=(ElemType*)realloc(L.elem,(pow+1)*sizeof(ElemType));
                if(!newbase) {
                    cout<<"error\n";
                    exit(OVERFLOW);
                }
                L.elem=newbase;
                L.listsize=pow+1;
                for(int i=L.length+1;i<L.listsize;i++){
                    L.elem[i]=0;//新开的空间全部初始化置为0
                }
            }
            L.elem[pow]+=sign*num;
        }else {
            cout<<"error\n";
            string s;
            getline(cin,s,'\n');//如果输入有问题，将剩余的杂乱字符收掉，以免影响程序运行
            return ERROR;
        }
        if(pow>=L.length)
            L.length=pow;
        char d=getchar();
        if(d=='+') sign=1;//判断输入的符号来决定下一项的符号
        if(d=='-') sign=-1;
        if(d=='\n') break;
    }
}
Status addPolynomial(SqList &L,SqList a,SqList b){
    InitList_Sq(L);
    L.length=0;
    int i;
    int maxlength=a.length>b.length?a.length:b.length;//取最长长度为和多项式的长度
    int minlength=a.length<b.length?a.length:b.length;//取最短长度
    if(maxlength>=L.listsize){//如果多项式最大指数大于现在线性表的空间
        ElemType* newbase=(ElemType*)realloc(L.elem,(maxlength+1)*sizeof(ElemType));
        if(!newbase) {
            cout<<"error\n";
            exit(OVERFLOW);
        }
        L.elem=newbase;
        L.listsize=maxlength+1;
    }
    for(i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    for(int i=0;i<=maxlength;i++){
        if(i<=minlength)
        L.elem[i]=a.elem[i]+b.elem[i];
        else if(i<=a.length){
            L.elem[i]+=a.elem[i];
        }else if(i<=b.length){
            L.elem[i]+=b.elem[i];
        }
    }
    L.length=maxlength;
    return OK;
}
Status subPolynomial(SqList &L,SqList a,SqList b){
    InitList_Sq(L);
    L.length=0;
    int i;
    for(i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    int maxlength=a.length>b.length?a.length:b.length;//同加法的原理
    int minlength=a.length<b.length?a.length:b.length;//取最短长度
    if(maxlength>=L.listsize){//如果多项式最大指数大于现在线性表的空间
        ElemType* newbase=(ElemType*)realloc(L.elem,(maxlength+1)*sizeof(ElemType));
        if(!newbase) {
            cout<<"error\n";
            exit(OVERFLOW);
        }
        L.elem=newbase;
        L.listsize=maxlength+1;
    }
    for(i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    for(int i=0;i<=maxlength;i++){
        if(i<=minlength)
        L.elem[i]=a.elem[i]-b.elem[i];
        else if(i<=a.length){
            L.elem[i]+=a.elem[i];
        }else if(i<=b.length){
            L.elem[i]-=b.elem[i];
        }
    }
    L.length=maxlength;
    return OK;
}
SqList derivate_Polynomial(SqList a){
    SqList L;
    InitList_Sq(L);
    L.length=0;
    if(L.listsize<a.listsize){//如果多项式最大指数大于现在线性表的空间
        ElemType* newbase=(ElemType*)realloc(L.elem,(a.listsize)*sizeof(ElemType));
        if(!newbase) {
            cout<<"error\n";
            exit(OVERFLOW);
        }
        L.elem=newbase;
        L.listsize=a.listsize;
    }
    int i;
    for(i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    for(int i=1;i<=a.length;i++){
        if(a.elem[i]!=0)
            L.elem[i-1]=i*a.elem[i];//求导公式：d(x^n)/dx=n*x^(n-1)
    }
    L.length=(a.length-1)>0?(a.length-1):0;//长度为原有长度-1和0之间的最大值
    return L;
}
SqList multPolynomial(SqList a,SqList b){
    SqList L;
    InitList_Sq(L);
    if(a.length+b.length>=LIST_INT_SIZE){//如果最高次项指数和大于数组的空间大小
        ElemType* newbase=(ElemType*)realloc(L.elem,(a.length+b.length+1)*sizeof(ElemType));//就增加新的空间
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize=a.length+b.length+1;//新空间大小设为长度和+1
        for(int i=0;i<L.listsize;i++){
            L.elem[i]=0;
        }
    }
    L.length=0;
    int i,j;
    for(i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    for(i=0;i<=a.length;i++){
        if(a.elem[i]!=0){
            for(j=0;j<=b.length;j++){
                if(b.elem[j]!=0){
                    L.elem[i+j]+=a.elem[i]*b.elem[j];//先a的一项轮流和b的各项相乘，然后再依次累加
                    if(i+j>=L.length){
                        L.length=i+j;
                    }
                }
            }
        }
    }
    return L;
}
Status showPolynomial(SqList L){
    int i=L.length;
    bool isall0=true;//记录是否表中全为0
    for(;i>=0;i--){
        if(L.elem[i]!=0){
            isall0=false;
            if(i!=L.length){
                if(L.elem[i]>0)
                printf("+");
            }
            if(L.elem[i]!=1)
                if(i==1)
                    printf("%dx",L.elem[i]);
                else if(i==0)printf("%d",L.elem[i]);
                else printf("%dx^%d",L.elem[i],i);
            else{
                if(i==1)
                    printf("x");
                else if(i==0)printf("1");
                else printf("x^%d",i);
            }
        }
    }
    if(isall0==true)//如果全为0，应该输出一个0
        printf("0");
    return OK;
}
