#include "data_struct.h"
#include "listopt.h"
#include "vector_cal.h"
#include "listPolynomial.h"
#include "linkPolynomial.h"
#include "cal_expandfunc.h"
#include "matrix.h"
int main(int argc, char** argv) {
    system("color f0");
    cout<<"****************���� & ����ʽ & ���� & ���� ���׼�����****************\n";
    while(1){
        int num;
        cout<<"	1.��������\n";
        cout<<"		1.�������\n";
        cout<<"		2.�������\n";
        cout<<"		3.������ģ\n";
        cout<<"		4.�������\n";
        cout<<"		5.������н�����ֵ\n";
        cout<<"		6.��ѯ������ĳһλ��Ԫ��ֵ\n";
        cout<<"		7.�������\n";
        cout<<"		8.ɾ���������˳�����ģʽ\n";
        cout<<"		9.��ʾ����\n";
        cout<<"	2.���ɶ���ʽ��˳����涨�ݴβ��ôﵽ5,000,000\n";
        cout<<"		1.����ʽ���\n";
        cout<<"		2.����ʽ���\n";
        cout<<"		3.����ʽ���\n";
        cout<<"		4.����ʽ��\n";
        cout<<"		5.��ѯ����ʽĳһ�ݴ������ϵ��ֵ\n";
        cout<<"		6.��ն���ʽ\n";
        cout<<"	 	7.ɾ������ʽ\n";
        cout<<"		8.��ʾ����ʽ\n";
        cout<<"	3.���ɶ���ʽ�������涨�ݴβ��ôﵽ2,147,483,647\n";
        cout<<"		1.����ʽ���\n";
        cout<<"		2.����ʽ���\n";
        cout<<"		3.��ѯ����ʽĳһ�ݴ������ϵ��ֵ\n";
        cout<<"		4.����ʽ��\n";
        cout<<"		5.����ʽ���\n";
        cout<<"		6.��ն���ʽ\n";
        cout<<"	 	7.ɾ������ʽ���˳�����ʽģʽ\n";
        cout<<"		8.��ʾ����ʽ\n";
        cout<<"	4.���ʽ��ֵ��������0-10��������֧�ָ���������Ϳ�ѧ������\n";
        cout<<"	5.�Զ��庯������⣬������Ƕ�׶��壬�������ʮ���Ա���\n";
        cout<<"	6.������ؼ���\n";
        cout<<"		1��ת�þ���\n";
        cout<<"		2���������\n";
        cout<<"		3���������\n";
        cout<<"		4���������\n";
        cout<<"		5������ʽ��ֵ\n";
        cout<<"		6��������ֵ\n";
        cout<<"		7������\n";
        cout<<"		8�����پ����˳���ģ��\n";
        cout<<"	7.��ȫ�˳�ϵͳ\n";
        cout<<"������\n";
        if(scanf("%d",&num)!=1){
            cout<<"�������룬������ѡ��\n";
            getchar();
            continue;
        }
        switch(num){
            case 1:{
                getchar();
                cout<<"��������������  #��ʽΪ��(1 3 4 5 7\n";
                SqList l1,l2;
                InitList_Sq(l1);
                InitList_Sq(l2);
                cout<<"1��(";
                create_vector(l1);
                cout<<"2��(";
                create_vector(l2);
                while(1){
                    int choice;
                    cout<<"\n	��ѡ�����\n";
                    cout<<"		1.�������\n";
                    cout<<"		2.�������\n";
                    cout<<"		3.������ģ\n";
                    cout<<"		4.�������\n";
                    cout<<"		5.������н�����ֵ\n";
                    cout<<"		6.��ѯ������ĳһλ��Ԫ��ֵ\n";
                    cout<<"		7.�������\n";
                    cout<<"		8.ɾ���������˳�����ģʽ\n";
                    cout<<"		9.��ʾ����\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"�������룬������ѡ��\n";
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
                            cout<<"�������������:";
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
                            cout<<"�������������:";
                            int n,m,g;
                            cin>>n;
                            cout<<"������Ҫ��ѯ��λ��:";
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
                            cout<<"�������������:";
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
                cout<<"��������������ʽ  #��ʽ���磺3x^0+4x^4+1x^3+7x^1\n";
                SqList l1,l2;
                InitList_Sq(l1);
                InitList_Sq(l2);
                createPolynomial(l1);
                createPolynomial(l2);
                while(1){
                    int choice;
                    cout<<"\n	��ѡ�����\n";
                    cout<<"		1.����ʽ���\n";
                    cout<<"		2.����ʽ���\n";
                    cout<<"		3.����ʽ���\n";
                    cout<<"		4.����ʽ��\n";
                    cout<<"		5.��ѯ����ʽĳһ�ݴ������ϵ��ֵ\n";
                    cout<<"		6.��ն���ʽ\n";
                    cout<<"	 	7.ɾ������ʽ���˳�����ʽģʽ\n";
                    cout<<"		8.��ʾ����ʽ\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"�������룬������ѡ��\n";
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
                            cout<<"��ѡ��Ҫ�󵼵Ķ���ʽ������1��2\n";
                            int c;
                            SqList d;
                            cin>>c;
                            int n=0,num=0;
                            cout<<"�������󵼴���\n";
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
                            cout<<"���������ʽ���:";
                            int n,m,g;
                            cin>>n;
                            cout<<"������Ҫ��ѯ����Ĵ���:";
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
                            cout<<"���������ʽ���:";
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
                cout<<"��������������ʽ  #��ʽ���磺3x^0+4x^4+1x^3+7x^1\n";
                LinkList l1,l2;
                create_LinkPolynomial(l1);
                create_LinkPolynomial(l2);
                while(1){
                    int choice;
                    cout<<"\n	��ѡ�����\n";
                    cout<<"		1.����ʽ���\n";
                    cout<<"		2.����ʽ���\n";
                    cout<<"		3.��ѯ����ʽĳһ�ݴ������ϵ��ֵ\n";
                    cout<<"		4.����ʽ��\n";
                    cout<<"		5.����ʽ���\n";
                    cout<<"		6.��ն���ʽ\n";
                    cout<<"	 	7.ɾ������ʽ���˳�����ʽģʽ\n";
                    cout<<"		8.��ʾ����ʽ\n";
                    if(scanf("%d",&choice)!=1){
                        cout<<"�������룬������ѡ��\n";
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
                            cout<<"���������ʽ���:";
                            int n,m,g;
                            cin>>n;
                            cout<<"������Ҫ��ѯ����Ĵ���:";
                            int d=scanf("%d",&m);
                            if(n==1&&d==1)search(l1,m,g);
                            else if(n==2&&d==1)search(l2,m,g);
                            else cout<<"error\n";
                            cout<<g<<endl;
                            break;
                        }
                        case 4:{
                            cout<<"��ѡ��Ҫ�󵼵Ķ���ʽ������1��2\n";
                            int c;
                            LinkList d;
                            cin>>c;
                            int n=0,num=0;
                            cout<<"�������󵼴���\n";
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
                            cout<<"���������ʽ���:";
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
                cout<<"��������ʽ:";
                cin>>str;
                int n=1;
                while(n){
                    cout<<"result:"<<calcuresult(str)<<endl;
                    ret:cout<<"�����˱��ʽ��ֵ������1���˳�����0\n";
                    cin>>n;
                    if(n!=0&&n!=1){
                        cout<<"�������\n";
                        goto ret;
                    }
                }
                break;
            }
            case 5:{
                cout<<"����ͨ����def���͡�run��������������������ʽ����:\ndef ������(����1,����2,��,����n)=�������ʽ\nrun ������(����ֵ1,����ֵ2,��,����ֵn)\n";
                cout<<"���⣬����ͨ�����ls�����鿴���е����к�����ͨ�����rm��ɾ�����к�����¼��ͨ�����qt���˳���ģʽ\n";
                LOOP:function f;
                char str[40];
                char cmd[4];
                cout<<">>";
                cin>>cmd;
                if(strcmp(cmd,"ls")==0){
                    FILE *fp;
                    if((fp=fopen("������.txt","r"))==NULL){
                        cout<<"���ļ�ʧ��\n";
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
                    system("del ������.txt");
                    goto LOOP;
                }
                if(strcmp(cmd,"qt")==0){
                    break;
                }
                cin>>str;
                if(strcmp(cmd,"def")==0){
                    FILE *fp;
                    if((fp=fopen("������.txt","a"))==NULL){
                        cout<<"���ļ�ʧ��\n";
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
                    cout<<"��������޷�ʶ��\n";
                    goto LOOP;
                }
            }
            case 6:{
                matrix m,n;
                cout<<"���ʼ������1\n";
                Initmatrix(m);
                cout<<"���ʼ������2\n";
                Initmatrix(n);
                while(1){
                    int a;
                    cout<<"		1��ת�þ���\n";
                    cout<<"		2���������\n";
                    cout<<"		3���������\n";
                    cout<<"		4���������\n";
                    cout<<"		5������ʽ��ֵ\n";
                    cout<<"		6��������ֵ\n";
                    cout<<"		7������\n";
                    cout<<"		8�����پ����˳���ģ��\n";
                    cin>>a;
                    switch (a){
                        case 1:{
                            cout<<"��Ҫת���ĸ�������ѡ��1����2��";
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
                            cout<<"��Ҫ���ĸ����������ʽ��ֵ����ѡ��1����2��";
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
                            cout<<"��Ҫ���ĸ����������ֵ����ѡ��1����2��";
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
                            cout<<"��Ҫ���ĸ�������ȣ���ѡ��1����2��";
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
            	cout<<"��ӭ�´�ʹ�ñ�����(*^_^*)\n"; 
                exit(0);
                break;
            }
        }
    }
    return 0;
}

