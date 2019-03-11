#include "matrix.h"
Status Initmatrix(matrix& m){//初始化 
    int col,row;
    printf("请输入行和列:");
    scanf("%d %d",&row,&col);
    m.data=(double**)malloc(row*sizeof(double*));
    for(int i=0;i<row;i++){
        m.data[i]=(double*)malloc(col*sizeof(double));
    }
    printf("请依次输入元素\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%lf",&m.data[i][j]);
        }
    }
    m.col=col;
    m.row=row;
    return OK;
}
Status transpose(matrix& newm,matrix m){//转置 
    newm.col=m.row;
    newm.row=m.col;
    newm.data=(double**)malloc(newm.row*sizeof(double*));
    for(int i=0;i<newm.row;i++){
        *(newm.data+i)=(double*)malloc(newm.col*sizeof(double));
    }
    for(int i=0;i<newm.row;i++){
        for(int j=0;j<newm.col;j++){
            newm.data[i][j]=m.data[j][i];
        }
    }
    return OK;
}
Status addmatrix(matrix &sum,matrix a,matrix b){//加和，每个位置相应加和即可 
    if(a.col!=b.col||a.row!=b.row) return ERROR;
    sum.col=a.col;
    sum.row=a.row;
    sum.data=(double**)malloc(sum.row*sizeof(double*));
    for(int i=0;i<sum.row;i++){
        *(sum.data+i)=(double*)malloc(sum.col*sizeof(double));
    }
    for(int i=0;i<sum.row;i++){
        for(int j=0;j<sum.col;j++){
            sum.data[i][j]=a.data[i][j]+b.data[i][j];
        }
    }
    return OK;
}
Status submatrix(matrix &sub,matrix a,matrix b){//相减，每个位置对应相减 
    if(a.col!=b.col||a.row!=b.row) return ERROR;
    sub.col=a.col;
    sub.row=a.row;
    sub.data=(double**)malloc(sub.row*sizeof(double*));
    for(int i=0;i<sub.row;i++){
        *(sub.data+i)=(double*)malloc(sub.col*sizeof(double));
    }
    for(int i=0;i<sub.row;i++){
        for(int j=0;j<sub.col;j++){
            sub.data[i][j]=a.data[i][j]-b.data[i][j];
        }
    }
    return OK;
}
Status multmatrix(matrix &c,matrix a,matrix b){//相乘 
    if(a.col!=b.row)return ERROR;
    c.row=a.row;
    c.col=b.col;
    c.data=(double**)malloc(c.row*sizeof(double*));
    for(int i=0;i<c.row;i++){
        *(c.data+i)=(double*)malloc(c.col*sizeof(double));
    }
    int n=a.row;
    int l=b.col;
    int m=a.col;
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            for(int k=0;k<m;k++){
                c.data[i][j]+=a.data[i][k]*b.data[k][j];
            }
        }
    }
    return OK;
}

double valuematrix(matrix m){//将行列式化成三角形行列式然后计算行列式的值 
    if(m.col!=m.row)exit(1);
    int n=m.col;
    double**a=(double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++){
        a[i]=(double*)malloc(n*sizeof(double));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=m.data[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            for(int l=i+1;l<n;l++){
                if(a[l][i]!=0){
                    for(int p=0;p<n;p++){
                        a[i][p]+=a[l][p];
                    }
                    break;
                }
            }
        }
        for(int j=i+1;j<n;j++){
            if(a[j][i]!=0)
            for(int k=n-1;k>=0;k--){
                a[j][k]-=(a[j][i]/a[i][i])*a[i][k];
            }
        }
    }
    double s=1;
    for(int i=0;i<n;i++){
        s=s*a[i][i];
    }
    return s;
}
Status Rank(matrix m,int &mrank){//求矩阵的秩：先化成三角矩阵然后看有多少行全为0 
    if(m.col!=m.row)exit(1);
    int n=m.col;
    double**a=(double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++){
        a[i]=(double*)malloc(n*sizeof(double));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=m.data[i][j];
        }
    }
    mrank=0;
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            for(int l=i+1;l<n;l++){
                if(a[l][i]!=0){
                    for(int p=0;p<n;p++){
                        a[i][p]+=a[l][p];
                    }
                    break;
                }
            }
        }
        for(int j=i+1;j<n;j++){
            if(a[j][i]!=0)
            for(int k=n-1;k>=0;k--){
                a[j][k]-=(a[j][i]/a[i][i])*a[i][k];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(fabs(a[i][j])>=0.00001){
                mrank++;
                break;
            }
        }
    }
    return OK;
}
Status showmatrix(matrix m);
Status freematrix(matrix& m);
Status character(matrix m){//求特征值，用牛顿法的变法：双点割线法，结合随机数求出所有的特征值 
    int num=m.col;
    matrix n;
    n.data=(double**)malloc(num*sizeof(double*));
    for(int i=0;i<num;i++){
        n.data[i]=(double*)malloc(num*sizeof(double));
    }
    n.col=num;
    n.row=num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            n.data[i][j]=0;
        }
    }
    int pnum=0,vnum=0,rpt=0;//pnum为算上重根已经求出来的个数，vnum为不算重根求出来的个数，rpt为反复次数 
    int exp;
    int cnum=0;//cnum为迭代次数 
    double max,min,Sparsity;
    double x1,x2;//迭代的两个数值
    double *value=(double*)malloc(num*sizeof(double));
    memset(value,0,num*sizeof(double));
    srand((unsigned)time(0));//设置随机种子
    double vsub=Tmax;
    matrix result;//存储计算结果
    Loop:
    exp=0;//之后用来表示随机范围 
    max=-Tmax;
    min=Tmax;
    if(vnum>1){
        for(int i=0;i<pnum;i++){
            if(value[i]>max){
                max=value[i];
            }
            if(value[i]<min){
                min=value[i];
            }
        }
        Sparsity=num*1.0/vsub;//定义稀疏度
        if(Sparsity<100)
        vsub=max-min;
        exp=vsub*10000;
    }else exp=Tmax;
    if(exp==Tmax){
        x1=rand()*rand()*pow(-1,rand());
        x2=rand()*rand()*pow(-1,rand());
    }else{
        x1=(rand()*rand()%(exp))/10000.0+min;
        x2=(rand()*rand()%(exp))/10000.0+min;
    }
    cnum=0;//循环计数
    while((fabs(x2-x1)>0.000001)&&cnum<1000000){
        for(int i=0;i<num;i++){
            n.data[i][i]=x1;
        }
        matrix sub1;
        submatrix(sub1,n,m);
        double d1=valuematrix(sub1);
        for(int i=0;i<num;i++){
            n.data[i][i]=x2;
        }
        matrix sub2;
        submatrix(sub2,n,m);
        double d2=valuematrix(sub2);
        double x3=x2-(d2/(d2-d1))*(x2-x1);//运用双点割线法多次迭代
        x1=x2;
        x2=x3;
        cnum++;
        freematrix(sub1);
        freematrix(sub2);
    }
    for(int i=0;i<num;i++){
            n.data[i][i]=(x1+x2)/2;
    }
    submatrix(result,n,m);
    int R;
    Rank(result,R);
    freematrix(result);
    for(int i=0;i<pnum;i++){
        if(fabs(value[i]-(x1+x2)/2)<=0.00001){
            rpt++;
            if(rpt>100*num*num){
                return OK;
            }
            goto Loop;
        }
    }
    if(R!=num){//如果没有满秩，说明运算结果为0，应该是一个特征值 
        value[pnum]=(x1+x2)/2;
        if(fabs(value[pnum])<0.0001)value[pnum]=0.0;
        if(isnan(value[pnum])==0){
            printf(" %d 重根 ",num-R);
            printf("%.5lf\n",value[pnum]);
        }
        pnum+=(num-R);
        vnum++;
    }
    if((pnum<num)&&rpt<=100*num*num) goto Loop;
    return OK;
}
Status showmatrix(matrix m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            printf("%16lf ",m.data[i][j]);
        }printf("\n");
    }
    return OK;
}
Status freematrix(matrix& m){
    for(int i=0;i<m.row;i++){
        free(m.data[i]);
    }
    free(m.data);
    return OK;
}
