#include "cal_expandfunc.h"
template<class T>
Status InitStack(SqStack<T> &S){
    S.base = (T*)malloc(STACK_INIT_SIZE*sizeof(T));
    if(!S.base)exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}
template<class T>
Status GetTop(SqStack<T> S,T &e){
    if(S.top==S.base)return ERROR;//���ջ��
    e=*(S.top-1);
    return OK;
}
template<class T>
Status Push(SqStack<T> &S,T e){
    if(S.top-S.base>=S.stacksize){//���ջ��
        S.base=(T*)realloc(S.base,(S.stacksize<<1)*sizeof(T));
        if(!S.base)exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize=S.stacksize<<1;
    }
    *S.top++ = e;
    return OK;
}
template<class T>
Status Pop(SqStack<T> &S,T &e){//���ջ��
    if(S.top==S.base)return ERROR;
    e = * --S.top;
    return OK;
}
template<class T>
Status DestroyStack(SqStack<T> &S){
    delete[] S.base;//����ջ
    S.base=S.top=NULL;
    S.stacksize=0;
    return OK;
}
template<class T>
T calculate(T a,char op,T b){//��������ı��ʽ
    if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^'){
        if(op=='+')return a+b;
        if(op=='-')return a-b;
        if(op=='*')return a*b;
        if(op=='/')return a/b;
        if(op=='^')return pow(a,b);
    }
    return 0;
}
bool ifop(char c){//�ж��Ƿ��ǲ�����
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')'||c=='\n'||c==',')
    return true;
    else return false;
}
bool ifnum(char c){//�ж��Ƿ�������
    if(c>='0'&&c<='9')
    return true;
    else return false;
}
bool ifidentifier(char *c){//�ж��Ƿ��Ǳ���
    int len=strlen(c);
    int n=0;
    for(int i=0;i<len;i++){
        if((c[i]=='_'||(c[i]>='a'&&c[i]<='z')||c[i]>='A'&&c[i]<='Z')&&(!(c[i]=='e'&&ifnum(c[i-1])==true)))//c�����б������Ժ������֡���Сд��ĸ�� '_'
            n=1;
    }
    return n;
}
bool check(char *c){//�����ʽ���Ƿ��зǷ����ַ�
    int len=strlen(c);
    for(int i=0;i<len;i++){
        if(ifop(c[i])==false&&ifnum(c[i])==false&&(c[i]=='.'||c[i]==','||c[i]=='_'||(c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))==false){
            cout<<"���ʽ���ܺ����쳣����"<<c[i]<<endl;
            return false;
        }
    }
    return true;
}
char *strrpc(char *str,char *oldstr,char *newstr){//�ַ����滻����
    char bstr[6*strlen(str)];//ת��������
    memset(bstr,0,sizeof(bstr));
    for(int i = 0;i < strlen(str);i++){
        if(!strncmp(str+i,oldstr,strlen(oldstr))){//����Ŀ���ַ���
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
        }else{
            strncat(bstr,str + i,1);//����һ�ֽڽ�������
        }
    }
    strcpy(str,bstr);
    return str;
}
int precede(char a,char b){//�ж���������ȼ�
    if(a=='+'||a=='-'){
        if(b=='+') return 1;
        if(b=='-') return 1;
        if(b=='*') return -1;
        if(b=='^') return -1;
        if(b=='/') return -1;
        if(b=='(') return -1;
        if(b==')') return 1;
        if(b=='\n') return 1;
    }
    else if(a=='*'||a=='/'){
        if(b=='+') return 1;
        if(b=='-') return 1;
        if(b=='*') return 1;
        if(b=='/') return 1;
        if(b=='^') return -1;
        if(b=='(') return -1;
        if(b==')') return 1;
        if(b=='\n') return 1;
    }
    else if(a=='^'){
        if(b=='+') return 1;
        if(b=='-') return 1;
        if(b=='*') return 1;
        if(b=='/') return 1;
        if(b=='^') return -1;
        if(b=='(') return -1;
        if(b==')') return 1;
        if(b=='\n') return 1;
    }
    else if(a=='('){
        if(b=='+') return -1;
        if(b=='-') return -1;
        if(b=='*') return -1;
        if(b=='/') return -1;
        if(b=='^') return -1;
        if(b=='(') return -1;
        if(b==')') return 0;
        if(b=='\n') return -2;
    }else if(a==')'){
        if(b=='+') return 1;
        if(b=='-') return 1;
        if(b=='*') return 1;
        if(b=='/') return 1;
        if(b=='^') return 1;
        if(b=='(') return -2;
        if(b==')') return 1;
        if(b=='\n') return 1;
    }else if(a=='\n'){
        if(b=='+') return -1;
        if(b=='-') return -1;
        if(b=='*') return -1;
        if(b=='/') return -1;
        if(b=='^') return -1;
        if(b=='(') return -1;
        if(b==')') return -2;
        if(b=='\n') return 0;
    }
}

bool findFuncName(char* name){//���ĵ����Һ�������
    FILE* fp=fopen("������.txt","r");
    while(fp&&!feof(fp)){
        char fstr[100];
        fgets(fstr,100,fp);
        char fname[20];
        char* pf=strstr(fstr,"(");
        strncpy(fname,fstr,pf-fstr);
        fname[pf-fstr]='\0';
        if(strcmp(fname,name)==0){
            return true;
        }
    }
    return false;
}
double run(struct function func){//���еĺ���������Ԥ��������������ת���ɱ��ʽ��ֵ���͵��ü��㺯��  
    if(check(func.expression)==false) return 0;//������ʽ���зǷ��ַ���ֱ�ӷ���0
    char *ex;
    for(int k=0;k<func.varinum;k++){
        char sd[20];
        sd[0]='(';
        sprintf(sd+1,"%lf",func.p[k].second);
        int l=strlen(sd);
        sd[l]=')';
        sd[l+1]='\0';
        ex=strrpc(func.expression,func.p[k].first,sd);//�ַ����滻���� 
    }
    ex=strrpc(func.expression,"++","+");//�����Ϊ�滻������Щ�쳣���ţ��ٴ��滻��
    ex=strrpc(func.expression,"--","+");
    ex=strrpc(func.expression,"+-","-");
    ex=strrpc(func.expression,"-+","-");
    int len=strlen(func.expression);
    func.expression[len]='\n';//�ڱ��ʽ���ǿ�м���һ�����з�
    func.expression[len+1]='\0';
    return calcuresult(func.expression);//���ñ��ʽ��ֵ���� 
}

function Inifunction(char *str){//��ʼ�����������������ľ�����õ��ִ�������ʵ�ʵĺ����ṹ
    function f;
    int n=1,m=1;
    char* p=strstr(str,"(");
    strncpy(f.name,str,p-str);
    f.name[p-str]='\0';
    strcpy(str,p);
    FILE *fp;
    if((fp=fopen("������.txt","r"))==NULL){
        cout<<"���ļ�ʧ��\n";
        exit(1);
    }
    bool iffind=false;
    while(!feof(fp)){//�����ȡ�ļ� 
        char fstr[100];
        fgets(fstr,100,fp);
        char fname[20];
        char* pf=strstr(fstr,"(");
        strncpy(fname,fstr,pf-fstr);
        fname[pf-fstr]='\0';
        strcpy(fstr,pf);
        if(strcmp(f.name,fname)==0){//��⺯���� 
            iffind=true;
            do{
                if(fstr[n]==','||fstr[n]==')'){//��������ʽ 
                    f.p[f.varinum].first=(char*)malloc((n-m+1)*sizeof(char));
                    strncpy(f.p[f.varinum].first,fstr+m*sizeof(char),(n-m));
                    f.p[f.varinum].first[n-m]='\0';;
                    n++;
                    m=n;
                    f.varinum++;
                    if(fstr[n-1]==')') {
                        break;
                    }
                }else{
                    n++;
                }
            }while(fstr[n]!='\n');
            char* qf=strstr(fstr,")");
            strcpy(f.expression,qf+2);
        }
    }
    if(iffind==false){
        cout<<"���õĺ���������\n";
        exit(1);
    }
    int num=1;
    int varinum=0;
    while(str[num]!='\0'){//���ú��� 
        char strnum[20]={0};
        if(ifop(str[num])==false||(((num>=1&&str[num-1]=='(')||(strnum[num-1]=='e'))&&(str[num]=='-'||str[num]=='+'))){
            int i=0;
            while(ifop(str[num+i])==false||(((i==0&&str[num-1]=='(')||(strnum[num+i-1]=='e'))&&(str[num+i]=='-'||str[num+i]=='+'))){//�����������߱������ַ�����ȡ��
                strnum[i]=str[num+i];
                i++;
            }
            num=num+i;
            strnum[i]='\0';
            double d;
            if(findFuncName(strnum)!=false){
                char *p=str+num;
                char *start;
                start=p;
                char *q;
                SqStack<char> s;
                InitStack(s);
                Push(s,'\n');
                while(p!=NULL){
                    char get;
                    GetTop(s,get);
                    if(get=='\n'||(*p=='(')){
                        Push(s,*p);
                    }
                    if(*p==')'){
                        Pop(s,get);
                    }
                    GetTop(s,get);
                    if(get=='\n'){
                        q=p;
                        break;
                    }
                    p++;
                }
                DestroyStack(s);
                num+=q-start+1;
                char fn[100]={0};
                strcpy(fn,strnum);
                char ex[100];
                strncpy(ex,start,q-start+1);
                ex[strlen(ex)]='\0';
                strcat(fn,ex);
                fn[strlen(fn)]='\0';
                function f=Inifunction(fn);//������ʽ�к��к���������ݹ����
                d=run(f);//�������ʼ��֮��ĺ������
            }else d=atof(strnum);
            f.p[varinum].second=d;
            varinum++;
        }else num++;
    }
    fclose(fp);
    return f;
}

double calcuresult(char str[]){//���ʽ��ֵ����
    if(check(str)==false) return 0;//������ʽ���зǷ��ַ���ֱ�ӷ���0
    SqStack<char> cstack;//����ջ
    SqStack<double> dstack;
    InitStack(cstack);
    InitStack(dstack);
    Push(cstack,'\n');//�Ȱ�һ�����з�ѹ��ջ�Ϊ����ƥ����ʽ���һ�����з����жϼ������
    Push(dstack,0.0);
    int len=strlen(str);
    str[len]='\n';//�ڱ��ʽ���ǿ�м���һ�����з�
    str[len+1]='\0';
    char get;
    GetTop(cstack,get);//ȡ��ջ��Ԫ��
    int num=0;
    struct identifier{//����һ�������Ľṹ�����飬����֮����ʽ�ظ����������ֵ
        char *strptr;
        double dnum;
    }identifierList[10];
    int idnum=0;//�����ĸ���
    while(str[num]!='\0'||get!='\n'){
        if(ifop(str[num])==false||(((num>=1&&str[num-1]=='(')||(str[num-1]=='e'))&&(str[num]=='-'||str[num]=='+')&&ifnum(str[num+1])==true)){//������ǲ�����������Ϊ�ǲ��������߱���
            int i=0;
            char strnum[20]={0};
            while(ifop(str[num+i])==false||(((i==0&&str[num-1]=='(')||(strnum[num+i-1]=='e'))&&(str[num+i]=='-'||str[num+i]=='+'))){//�����������߱������ַ�����ȡ��
                strnum[i]=str[num+i];
                i++;
            }
            num=num+i;
            strnum[i]='\0';
            double d;
            if(ifidentifier(strnum)){//����Ǳ���
                if(ifnum(strnum[0])==true){//����������ƿ�ͷ�����֣�����Ϊ����������c���Ա�����
                    cout<<strnum;
                    cout<<"�������쳣\n";
                    return 0;
                }
                bool isnewid=true;
                if(findFuncName(strnum)!=false){//����Ǻ�����������������������Ȼ��ݹ�����������
                    char *p=str+num;
                    char *start;
                    start=p;
                    char *q;
                    SqStack<char> s;
                    InitStack(s);
                    Push(s,'\n');
                    while(p!=NULL){//Ѱ��ƥ�������
                        char get;
                        GetTop(s,get);
                        if(get=='\n'||(*p=='(')){
                            Push(s,*p);
                        }
                        if(*p==')'){
                            Pop(s,get);
                        }
                        GetTop(s,get);
                        if(get=='\n'){
                            q=p;
                            break;
                        }
                        p++;
                    }
                    DestroyStack(s);
                    num+=q-start+1;
                    char fn[100]={0};
                    strcpy(fn,strnum);
                    char ex[100];
                    strncpy(ex,start,q-start+1);
                    ex[strlen(ex)]='\0';
                    strcat(fn,ex);
                    fn[strlen(fn)]='\0';
                    function f=Inifunction(fn);
                    d=run(f);
                    goto aim;
                }
                for(int k=0;k<idnum;k++){//�ж���������Ƿ��Ѿ������ֵ
                    if(strcmp(strnum,identifierList[k].strptr)==0){
                        d=identifierList[k].dnum;
                        isnewid=false;
                        break;
                    }
                }
                if(isnewid==true){//�����û�����ֵ�Ļ�
                    cout<<strnum<<"=";
                    cin>>d;
                    identifierList[idnum].dnum=d;
                    identifierList[idnum].strptr=(char*)malloc(20*sizeof(char));
                    strcpy(identifierList[idnum].strptr,strnum);
                    idnum++;
                }
            }
            else d=atof(strnum);//������Ǳ���������Ϊ�����֣����ַ���ת��double�͸�����
            aim:Push(dstack,d);
        }
        else{
            if(precede(get,str[num])==1){//���ջ�ڵĲ��������ȼ���
                char oprater;
                Pop(cstack,oprater);
                double a,b;
                Pop(dstack,a);
                Pop(dstack,b);
                Push(dstack,calculate(b,oprater,a));//��������ѹ�������ջ
            }
            else if(precede(get,str[num])==0){//������ȼ���ͬ
                char oprater;
                Pop(cstack,oprater);//��ջ�ڵĲ�����pop����
                num++;
            }
            else if(precede(get,str[num])==-1){//���ջ�ڵ����ȼ���
                Push(cstack,str[num]);//���²�����ѹ��ջ��
                num++;
            }
        }
        GetTop(cstack,get);//�õ�Ŀǰջ��Ԫ��
    }
    double result=0;
    Pop(dstack,result);//��������ջʣ�µ�һ�����־��ǽ��
    DestroyStack(cstack);
    DestroyStack(dstack);
    return result;
}

