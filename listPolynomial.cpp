#include "listpolynomial.h"
Status createPolynomial(SqList &L){
    L.length=0;
    for(int i=0;i<L.listsize;i++){
        L.elem[i]=0;
    }
    int sign=1;
    for(int i=0;i<L.listsize;i++){
        int num,pow;
        if(scanf("%dx^%d",&num,&pow)==2){//�ж��Ƿ���������
            if(pow>=5000000){
                cout<<"error\n";
                return OVERFLOW;
            }
            if(pow>=L.listsize){//�������ʽָ�������������Ա�Ŀռ�
                ElemType* newbase=(ElemType*)realloc(L.elem,(pow+1)*sizeof(ElemType));
                if(!newbase) {
                    cout<<"error\n";
                    exit(OVERFLOW);
                }
                L.elem=newbase;
                L.listsize=pow+1;
                for(int i=L.length+1;i<L.listsize;i++){
                    L.elem[i]=0;//�¿��Ŀռ�ȫ����ʼ����Ϊ0
                }
            }
            L.elem[pow]+=sign*num;
        }else {
            cout<<"error\n";
            string s;
            getline(cin,s,'\n');//������������⣬��ʣ��������ַ��յ�������Ӱ���������
            return ERROR;
        }
        if(pow>=L.length)
            L.length=pow;
        char d=getchar();
        if(d=='+') sign=1;//�ж�����ķ�����������һ��ķ���
        if(d=='-') sign=-1;
        if(d=='\n') break;
    }
}
Status addPolynomial(SqList &L,SqList a,SqList b){
    InitList_Sq(L);
    L.length=0;
    int i;
    int maxlength=a.length>b.length?a.length:b.length;//ȡ�����Ϊ�Ͷ���ʽ�ĳ���
    int minlength=a.length<b.length?a.length:b.length;//ȡ��̳���
    if(maxlength>=L.listsize){//�������ʽ���ָ�������������Ա�Ŀռ�
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
    int maxlength=a.length>b.length?a.length:b.length;//ͬ�ӷ���ԭ��
    int minlength=a.length<b.length?a.length:b.length;//ȡ��̳���
    if(maxlength>=L.listsize){//�������ʽ���ָ�������������Ա�Ŀռ�
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
    if(L.listsize<a.listsize){//�������ʽ���ָ�������������Ա�Ŀռ�
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
            L.elem[i-1]=i*a.elem[i];//�󵼹�ʽ��d(x^n)/dx=n*x^(n-1)
    }
    L.length=(a.length-1)>0?(a.length-1):0;//����Ϊԭ�г���-1��0֮������ֵ
    return L;
}
SqList multPolynomial(SqList a,SqList b){
    SqList L;
    InitList_Sq(L);
    if(a.length+b.length>=LIST_INT_SIZE){//�����ߴ���ָ���ʹ�������Ŀռ��С
        ElemType* newbase=(ElemType*)realloc(L.elem,(a.length+b.length+1)*sizeof(ElemType));//�������µĿռ�
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize=a.length+b.length+1;//�¿ռ��С��Ϊ���Ⱥ�+1
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
                    L.elem[i+j]+=a.elem[i]*b.elem[j];//��a��һ��������b�ĸ�����ˣ�Ȼ���������ۼ�
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
    bool isall0=true;//��¼�Ƿ����ȫΪ0
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
    if(isall0==true)//���ȫΪ0��Ӧ�����һ��0
        printf("0");
    return OK;
}
