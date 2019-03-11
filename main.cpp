#include "data_struct.h"
#include "listopt.h"
#include "vector_cal.h"
#include "listPolynomial.h"
#include "linkPolynomial.h"
#include "cal_expandfunc.h"
#include "matrix.h"
int main(int argc, char** argv) {
    system("color f0");
    cout<<"****************向量 & 多项式 & 函数 & 矩阵 简易计算器****************\n";
    while(1){
        int num;
        cout<<"	1.生成向量\n";
        cout<<"		1.向量相加\n";
        cout<<"		2.向量相减\n";
        cout<<"		3.向量求模\n";
        cout<<"		4.向量求积\n";
        cout<<"		5.向量求夹角余弦值\n";
        cout<<"		6.查询向量中某一位置元素值\n";
        cout<<"		7.清空向量\n";
        cout<<"		8.删除向量并退出向量模式\n";
        cout<<"		9.显示向量\n";
        cout<<"	2.生成多项式（顺序表）规定幂次不得达到5,000,000\n";
        cout<<"		1.多项式相加\n";
        cout<<"		2.多项式相减\n";
        cout<<"		3.多项式求积\n";
        cout<<"		4.多项式求导\n";
        cout<<"		5.查询多项式某一幂次数项的系数值\n";
        cout<<"		6.清空多项式\n";
        cout<<"	 	7.删除多项式\n";
        cout<<"		8.显示多项式\n";
        cout<<"	3.生成多项式（链表）规定幂次不得达到2,147,483,647\n";
        cout<<"		1.多项式相加\n";
        cout<<"		2.多项式相减\n";
        cout<<"		3.查询多项式某一幂次数项的系数值\n";
        cout<<"		4.多项式求导\n";
        cout<<"		5.多项式求积\n";
        cout<<"		6.清空多项式\n";
        cout<<"	 	7.删除多项式并退出多项式模式\n";
        cout<<"		8.显示多项式\n";
        cout<<"	4.表达式求值，允许含有0-10个变量，支持浮点数运算和科学计数法\n";
        cout<<"	5.自定义函数并求解，允许函数嵌套定义，允许最多十个自变量\n";
        cout<<"	6.矩阵相关计算\n";
        cout<<"		1，转置矩阵\n";
        cout<<"		2，矩阵求和\n";
        cout<<"		3，矩阵求差\n";
        cout<<"		4，矩阵求积\n";
        cout<<"		5，行列式求值\n";
        cout<<"		6，求特征值\n";
        cout<<"		7，求秩\n";
        cout<<"		8，销毁矩阵并退出此模块\n";
        cout<<"	7.安全退出系统\n";
        cout<<"请输入\n";
        if(scanf("%d",&num)!=1){
            cout<<"错误输入，请重新选择\n";
            getchar();
            continue;
        }
        switch(num){
            case 1:{
                getchar();
                cout<<"请输入两个向量  #格式为：(1 3 4 5 7\n";
                SqList l1,l2;
                InitList_Sq(l1);
                InitList_Sq(l2);
                cout<<"1、(";
                create_vector(l1);
                cout<<"2、(";
                create_vector(l2);
                while(1){
                    int choice;
                    cout<<"\n	请选择操作\n";
                    cout<<"		1.向量相加\n";
                    cout<<"		2.向量相减\n";
                    cout<<"		3.向量求模\n";
                    cout<<"		4.向量求积\n";
                    cout<<"		5.向量求夹角余弦值\n";
                    cout<<"		6.查询向量中某一位置元素值\n";
                    cout<<"		7.清空向量\n";
                    cout<<"		8.删除向量并退出向量模式\n";
                    cout<<"		9.显示向量\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"错误输入，请重新选择\n";
                        getchar();
                        continue;
                    }
                    switch(choice){
                        case 1:{
                            SqList sum=add(l1,l2);
                            show_vector(sum);
                            break;
                        }case 2:{
                            SqList minus=sub(l1,l2);
                            show_vector(minus);
                            break;
                        }
                        case 3:{
                            cout<<"请输入向量序号:";
                            int n;
                            double m;
                            cin>>n;
                            if(n==1){
                                mode(m,l1);
                                cout<<m;
                            }
                            else if(n==2){
                                mode(m,l2);
                                cout<<m;
                            }
                            else cout<<"error\n";
                            break;
                        }
                        case 4:{
                            int m;
                            mult(m,l1,l2);
                            cout<<m;
                            break;
                        }
                        case 5:{
                            double m;
                            cosangle(m,l1,l2);
                            cout<<m;
                            break;
                        }
                        case 6:{
                            cout<<"请输入向量序号:";
                            int n,m,g;
                            cin>>n;
                            cout<<"请输入要查询的位置:";
                            cin>>m;
                            if(n==1)Get(l1,m-1,g);
                            else if(n==2)Get(l2,m-1,g);
                            else cout<<"error\n";
                            cout<<g<<endl;
                            break;
                        }
                        case 7:{
                            emptyList_Sq(l1);
                            emptyList_Sq(l2);
                            break;
                        }
                        case 8:{
                            DeleteList_Sq(l1);
                            DeleteList_Sq(l2);
                            goto end1;
                            break;
                        }
                        case 9:{
                            cout<<"请输入向量序号:";
                            int n;
                            cin>>n;
                            if(n==1)
                            show_vector(l1);
                            else if(n==2)
                            show_vector(l2);
                            else cout<<"error\n";
                            break;
                        }
                    }
                }
                end1:break;
            }
            case 2:{
                getchar();
                cout<<"请输入两个多项式  #格式例如：3x^0+4x^4+1x^3+7x^1\n";
                SqList l1,l2;
                InitList_Sq(l1);
                InitList_Sq(l2);
                createPolynomial(l1);
                createPolynomial(l2);
                while(1){
                    int choice;
                    cout<<"\n	请选择操作\n";
                    cout<<"		1.多项式相加\n";
                    cout<<"		2.多项式相减\n";
                    cout<<"		3.多项式求积\n";
                    cout<<"		4.多项式求导\n";
                    cout<<"		5.查询多项式某一幂次数项的系数值\n";
                    cout<<"		6.清空多项式\n";
                    cout<<"	 	7.删除多项式并退出多项式模式\n";
                    cout<<"		8.显示多项式\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"错误输入，请重新选择\n";
                        getchar();
                        continue;
                    }
                    switch(choice){
                        case 1:{
                            SqList sum;
                            addPolynomial(sum,l1,l2);
                            showPolynomial(sum);
                            break;
                        }
                        case 2:{
                            SqList minus;
                            subPolynomial(minus,l1,l2);
                            showPolynomial(minus);
                            break;
                        }
                        case 3:{
                            SqList p;
                            p=multPolynomial(l1,l2);
                            showPolynomial(p);
                            break;
                        }
                        case 4:{
                            cout<<"请选择要求导的多项式，输入1或2\n";
                            int c;
                            SqList d;
                            cin>>c;
                            int n=0,num=0;
                            cout<<"请输入求导次数\n";
                            cin>>num;
                            if(c==1){
                                d=l1;
                                while((n++)<num)
                                d=derivate_Polynomial(d);
                            }
                            else if(c==2){
                                d=l2;
                                while((n++)<num)
                                d=derivate_Polynomial(d);
                            }

                            if(d.elem)showPolynomial(d);
                            break;
                        }
                        case 5:{
                            cout<<"请输入多项式序号:";
                            int n,m,g;
                            cin>>n;
                            cout<<"请输入要查询的项的次数:";
                            int d=scanf("%d",&m);
                            if(n==1&&d==1)Get(l1,m,g);
                            else if(n==2&&d==1)Get(l2,m,g);
                            else cout<<"error\n";
                            cout<<g<<endl;
                            break;
                        }
                        case 6:{
                            emptyList_Sq(l1);
                            emptyList_Sq(l2);
                            break;
                        }
                        case 7:{
                            DeleteList_Sq(l1);
                            DeleteList_Sq(l2);
                            goto end2;
                            break;
                        }
                        case 8:{
                            cout<<"请输入多项式序号:";
                            int n;
                            cin>>n;
                            if(n==1)
                            showPolynomial(l1);
                            else if(n==2)
                            showPolynomial(l2);
                            else cout<<"error\n";
                            break;
                        }
                    }
                }
                end2:break;
            }
            case 3:{
                getchar();
                cout<<"请输入两个多项式  #格式例如：3x^0+4x^4+1x^3+7x^1\n";
                LinkList l1,l2;
                create_LinkPolynomial(l1);
                create_LinkPolynomial(l2);
                while(1){
                    int choice;
                    cout<<"\n	请选择操作\n";
                    cout<<"		1.多项式相加\n";
                    cout<<"		2.多项式相减\n";
                    cout<<"		3.查询多项式某一幂次数项的系数值\n";
                    cout<<"		4.多项式求导\n";
                    cout<<"		5.多项式求积\n";
                    cout<<"		6.清空多项式\n";
                    cout<<"	 	7.删除多项式并退出多项式模式\n";
                    cout<<"		8.显示多项式\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"错误输入，请重新选择\n";
                        getchar();
                        continue;
                    }
                    switch(choice){
                        case 1:{
                            LinkList L;
                            addLink(L,l1,l2);
                            show_Link(L);
                            DestroyLink(L);
                            break;
                        }
                        case 2:{
                            LinkList L;
                            subLink(L,l1,l2);
                            show_Link(L);
                            DestroyLink(L);
                            break;
                        }
                        case 3:{
                            cout<<"请输入多项式序号:";
                            int n,m,g;
                            cin>>n;
                            cout<<"请输入要查询的项的次数:";
                            int d=scanf("%d",&m);
                            if(n==1&&d==1)search(l1,m,g);
                            else if(n==2&&d==1)search(l2,m,g);
                            else cout<<"error\n";
                            cout<<g<<endl;
                            break;
                        }
                        case 4:{
                            cout<<"请选择要求导的多项式，输入1或2\n";
                            int c;
                            LinkList d;
                            cin>>c;
                            int n=0,num=0;
                            cout<<"请输入求导次数\n";
                            cin>>num;
                            if(c==1){
                                d=l1;
                                while((n++)<num)
                                d=derivate_linkPolynomial(d);
                            }
                            else if(c==2){
                                d=l2;
                                while((n++)<num)
                                d=derivate_linkPolynomial(d);
                            }
                            show_Link(d);
                            DestroyLink(d);
                            break;
                        }
                        case 5:{
                            LinkList l=MultLink(l1,l2);
                            show_Link(l);
                            DestroyLink(l);
                            break;
                        }
                        case 6:{
                            ClearLink(l1);
                            ClearLink(l2);
                            break;
                        }
                        case 7:{
                            DestroyLink(l1);
                            DestroyLink(l2);
                            goto end3;
                            break;
                        }
                        case 8:{
                            cout<<"请输入多项式序号:";
                            int n;
                            cin>>n;
                            if(n==1)
                            show_Link(l1);
                            else if(n==2)
                            show_Link(l2);
                            else cout<<"error\n";
                            break;
                        }
                    }
                }
                end3:break;
            }
            case 4:{
                char str[100];
                cout<<"请输入表达式:";
                cin>>str;
                int n=1;
                while(n){
                    cout<<"result:"<<calcuresult(str)<<endl;
                    ret:cout<<"继续此表达式求值，请输1，退出请输0\n";
                    cin>>n;
                    if(n!=0&&n!=1){
                        cout<<"输入错误\n";
                        goto ret;
                    }
                }
                break;
            }
            case 5:{
                cout<<"可以通过“def”和“run”两个命令来操作，格式形如:\ndef 函数名(变量1,变量2,…,变量n)=函数表达式\nrun 函数名(变量值1,变量值2,…,变量值n)\n";
                cout<<"此外，可以通过命令“ls”来查看现有的所有函数，通过命令“rm”删除所有函数记录，通过命令“qt”退出此模式\n";
                LOOP:function f;
                char str[40];
                char cmd[4];
                cout<<">>";
                cin>>cmd;
                if(strcmp(cmd,"ls")==0){
                    FILE *fp;
                    if((fp=fopen("函数库.txt","r"))==NULL){
                        cout<<"打开文件失败\n";
                        goto LOOP;
                    }
                    while(!feof(fp)){
                        char func[100];
                        memset(func,0,100*sizeof(char));
                        fgets(func,100,fp);
                        cout<<func;
                    }
                    fclose(fp);
                    goto LOOP;
                }
                if(strcmp(cmd,"rm")==0){
                    system("del 函数库.txt");
                    goto LOOP;
                }
                if(strcmp(cmd,"qt")==0){
                    break;
                }
                cin>>str;
                if(strcmp(cmd,"def")==0){
                    FILE *fp;
                    if((fp=fopen("函数库.txt","a"))==NULL){
                        cout<<"打开文件失败\n";
                        goto LOOP;
                    }
                    fputs(str,fp);
                    fputc('\n',fp);
                    fclose(fp);
                    goto LOOP;
                }else if(strcmp(cmd,"run")==0){
                    f=Inifunction(str);
                    cout<<"   = "<<run(f)<<endl;
                    goto LOOP;
                }else{
                    cout<<"命令错误，无法识别\n";
                    goto LOOP;
                }
            }
            case 6:{
                matrix m,n;
                cout<<"请初始化矩阵1\n";
                Initmatrix(m);
                cout<<"请初始化矩阵2\n";
                Initmatrix(n);
                while(1){
                    int a;
                    cout<<"		1，转置矩阵\n";
                    cout<<"		2，矩阵求和\n";
                    cout<<"		3，矩阵求差\n";
                    cout<<"		4，矩阵求积\n";
                    cout<<"		5，行列式求值\n";
                    cout<<"		6，求特征值\n";
                    cout<<"		7，求秩\n";
                    cout<<"		8，销毁矩阵并退出此模块\n";
                    cin>>a;
                    switch (a){
                        case 1:{
                            cout<<"你要转置哪个矩阵？请选择1或者2：";
                            int x;
                            cin>> x;
                            if(x==1){
                                matrix l;
                                transpose(l,m);
                                showmatrix(l);
                                freematrix(l);
                            }else if(x==2){
                                matrix l;
                                transpose(l,n);
                                showmatrix(l);
                                freematrix(l);
                            }
                            break;
                        }
                        case 2:{
                            matrix sum;
                            addmatrix(sum,m,n);
                            showmatrix(sum);
                            freematrix(sum);
                            break;
                        }
                        case 3:{
                            matrix sub;
                            submatrix(sub,m,n);
                            showmatrix(sub);
                            freematrix(sub);
                            break;
                        }
                        case 4:{
                            matrix mul;
                            multmatrix(mul,m,n);
                            showmatrix(mul);
                            freematrix(mul);
                            break;
                        }
                        case 5:{
                            cout<<"你要求哪个矩阵的行列式的值？请选择1或者2：";
                            int x;
                            cin>> x;
                            if(x==1){
                                cout<<valuematrix(m);
                            }else if(x==2){
                                cout<<valuematrix(n);
                            }
                            cout<<endl;
                            break;
                        }
                        case 6:{
                            cout<<"你要求哪个矩阵的特征值？请选择1或者2：";
                            int x;
                            cin>> x;
                            if(x==1){
                                character(m);
                            }else if(x==2){
                                character(n);
                            }
                            cout<<endl;
                            break;
                        }
                        case 7:{
                            cout<<"你要求哪个矩阵的秩？请选择1或者2：";
                            int x;
                            int y;
                            cin>> x;
                            if(x==1){
                                Rank(m,y);
                            }else if(x==2){
                                Rank(n,y);
                            }
                            cout<<y<<endl;
                            break;
                        }
                        case 8:{
                            freematrix(m);
                            freematrix(n);
                            goto b;
                        }
                    }
                }
                b:break;
            }
            case 7:{
            	cout<<"欢迎下次使用本程序(*^_^*)\n"; 
                exit(0);
                break;
            }
        }
    }
    return 0;
}

