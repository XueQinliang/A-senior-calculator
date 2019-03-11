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
    if(S.top==S.base)return ERROR;//检测栈空
    e=*(S.top-1);
    return OK;
}
template<class T>
Status Push(SqStack<T> &S,T e){
    if(S.top-S.base>=S.stacksize){//检测栈满
        S.base=(T*)realloc(S.base,(S.stacksize<<1)*sizeof(T));
        if(!S.base)exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize=S.stacksize<<1;
    }
    *S.top++ = e;
    return OK;
}
template<class T>
Status Pop(SqStack<T> &S,T &e){//检测栈空
    if(S.top==S.base)return ERROR;
    e = * --S.top;
    return OK;
}
template<class T>
Status DestroyStack(SqStack<T> &S){
    delete[] S.base;//销毁栈
    S.base=S.top=NULL;
    S.stacksize=0;
    return OK;
}
template<class T>
T calculate(T a,char op,T b){//计算基本的表达式
    if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^'){
        if(op=='+')return a+b;
        if(op=='-')return a-b;
        if(op=='*')return a*b;
        if(op=='/')return a/b;
        if(op=='^')return pow(a,b);
    }
    return 0;
}
bool ifop(char c){//判断是否是操作符
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')'||c=='\n'||c==',')
    return true;
    else return false;
}
bool ifnum(char c){//判断是否是数字
    if(c>='0'&&c<='9')
    return true;
    else return false;
}
bool ifidentifier(char *c){//判断是否是变量
    int len=strlen(c);
    int n=0;
    for(int i=0;i<len;i++){
        if((c[i]=='_'||(c[i]>='a'&&c[i]<='z')||c[i]>='A'&&c[i]<='Z')&&(!(c[i]=='e'&&ifnum(c[i-1])==true)))//c语言中变量可以含有数字、大小写字母及 '_'
            n=1;
    }
    return n;
}
bool check(char *c){//检测表达式中是否有非法的字符
    int len=strlen(c);
    for(int i=0;i<len;i++){
        if(ifop(c[i])==false&&ifnum(c[i])==false&&(c[i]=='.'||c[i]==','||c[i]=='_'||(c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))==false){
            cout<<"表达式可能含有异常符号"<<c[i]<<endl;
            return false;
        }
    }
    return true;
}
char *strrpc(char *str,char *oldstr,char *newstr){//字符串替换函数
    char bstr[6*strlen(str)];//转换缓冲区
    memset(bstr,0,sizeof(bstr));
    for(int i = 0;i < strlen(str);i++){
        if(!strncmp(str+i,oldstr,strlen(oldstr))){//查找目标字符串
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
        }else{
            strncat(bstr,str + i,1);//保存一字节进缓冲区
        }
    }
    strcpy(str,bstr);
    return str;
}
int precede(char a,char b){//判断运算符优先级
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

bool findFuncName(char* name){//在文档中找函数名称
    FILE* fp=fopen("函数库.txt","r");
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
double run(struct function func){//运行的函数，负责预处理（将函数调用转化成表达式求值）和调用计算函数  
    if(check(func.expression)==false) return 0;//如果表达式含有非法字符则直接返回0
    char *ex;
    for(int k=0;k<func.varinum;k++){
        char sd[20];
        sd[0]='(';
        sprintf(sd+1,"%lf",func.p[k].second);
        int l=strlen(sd);
        sd[l]=')';
        sd[l+1]='\0';
        ex=strrpc(func.expression,func.p[k].first,sd);//字符串替换函数 
    }
    ex=strrpc(func.expression,"++","+");//如果因为替换出现这些异常符号，再次替换掉
    ex=strrpc(func.expression,"--","+");
    ex=strrpc(func.expression,"+-","-");
    ex=strrpc(func.expression,"-+","-");
    int len=strlen(func.expression);
    func.expression[len]='\n';//在表达式最后强行加上一个换行符
    func.expression[len+1]='\0';
    return calcuresult(func.expression);//调用表达式求值函数 
}

function Inifunction(char *str){//初始化函数，即将函数的具体调用的字串解析成实际的函数结构
    function f;
    int n=1,m=1;
    char* p=strstr(str,"(");
    strncpy(f.name,str,p-str);
    f.name[p-str]='\0';
    strcpy(str,p);
    FILE *fp;
    if((fp=fopen("函数库.txt","r"))==NULL){
        cout<<"打开文件失败\n";
        exit(1);
    }
    bool iffind=false;
    while(!feof(fp)){//具体读取文件 
        char fstr[100];
        fgets(fstr,100,fp);
        char fname[20];
        char* pf=strstr(fstr,"(");
        strncpy(fname,fstr,pf-fstr);
        fname[pf-fstr]='\0';
        strcpy(fstr,pf);
        if(strcmp(f.name,fname)==0){//检测函数名 
            iffind=true;
            do{
                if(fstr[n]==','||fstr[n]==')'){//解析计算式 
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
        cout<<"调用的函数不存在\n";
        exit(1);
    }
    int num=1;
    int varinum=0;
    while(str[num]!='\0'){//调用函数 
        char strnum[20]={0};
        if(ifop(str[num])==false||(((num>=1&&str[num-1]=='(')||(strnum[num-1]=='e'))&&(str[num]=='-'||str[num]=='+'))){
            int i=0;
            while(ifop(str[num+i])==false||(((i==0&&str[num-1]=='(')||(strnum[num+i-1]=='e'))&&(str[num+i]=='-'||str[num+i]=='+'))){//将操作数或者变量从字符串中取出
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
                function f=Inifunction(fn);//如果表达式中含有函数名，则递归调用
                d=run(f);//计算出初始化之后的函数结果
            }else d=atof(strnum);
            f.p[varinum].second=d;
            varinum++;
        }else num++;
    }
    fclose(fp);
    return f;
}

double calcuresult(char str[]){//表达式求值函数
    if(check(str)==false) return 0;//如果表达式含有非法字符则直接返回0
    SqStack<char> cstack;//构造栈
    SqStack<double> dstack;
    InitStack(cstack);
    InitStack(dstack);
    Push(cstack,'\n');//先把一个换行符压入栈里，为的是匹配表达式最后一个换行符来判断计算结束
    Push(dstack,0.0);
    int len=strlen(str);
    str[len]='\n';//在表达式最后强行加上一个换行符
    str[len+1]='\0';
    char get;
    GetTop(cstack,get);//取出栈顶元素
    int num=0;
    struct identifier{//构造一个变量的结构体数组，以免之后表达式重复输入变量的值
        char *strptr;
        double dnum;
    }identifierList[10];
    int idnum=0;//变量的个数
    while(str[num]!='\0'||get!='\n'){
        if(ifop(str[num])==false||(((num>=1&&str[num-1]=='(')||(str[num-1]=='e'))&&(str[num]=='-'||str[num]=='+')&&ifnum(str[num+1])==true)){//如果不是操作符，就认为是操作数或者变量
            int i=0;
            char strnum[20]={0};
            while(ifop(str[num+i])==false||(((i==0&&str[num-1]=='(')||(strnum[num+i-1]=='e'))&&(str[num+i]=='-'||str[num+i]=='+'))){//将操作数或者变量从字符串中取出
                strnum[i]=str[num+i];
                i++;
            }
            num=num+i;
            strnum[i]='\0';
            double d;
            if(ifidentifier(strnum)){//如果是变量
                if(ifnum(strnum[0])==true){//如果变量名称开头是数字，则认为不是正常的c语言变量名
                    cout<<strnum;
                    cout<<"变量名异常\n";
                    return 0;
                }
                bool isnewid=true;
                if(findFuncName(strnum)!=false){//如果是函数名，把整个函数读出来然后递归调用这个函数
                    char *p=str+num;
                    char *start;
                    start=p;
                    char *q;
                    SqStack<char> s;
                    InitStack(s);
                    Push(s,'\n');
                    while(p!=NULL){//寻找匹配的括号
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
                for(int k=0;k<idnum;k++){//判断这个变量是否已经输入过值
                    if(strcmp(strnum,identifierList[k].strptr)==0){
                        d=identifierList[k].dnum;
                        isnewid=false;
                        break;
                    }
                }
                if(isnewid==true){//如果是没输入过值的话
                    cout<<strnum<<"=";
                    cin>>d;
                    identifierList[idnum].dnum=d;
                    identifierList[idnum].strptr=(char*)malloc(20*sizeof(char));
                    strcpy(identifierList[idnum].strptr,strnum);
                    idnum++;
                }
            }
            else d=atof(strnum);//如果不是变量，则认为是数字，将字符串转成double型浮点数
            aim:Push(dstack,d);
        }
        else{
            if(precede(get,str[num])==1){//如果栈内的操作符优先级高
                char oprater;
                Pop(cstack,oprater);
                double a,b;
                Pop(dstack,a);
                Pop(dstack,b);
                Push(dstack,calculate(b,oprater,a));//计算结果并压入操作数栈
            }
            else if(precede(get,str[num])==0){//如果优先级相同
                char oprater;
                Pop(cstack,oprater);//将栈内的操作符pop出来
                num++;
            }
            else if(precede(get,str[num])==-1){//如果栈内的优先级低
                Push(cstack,str[num]);//将新操作符压入栈内
                num++;
            }
        }
        GetTop(cstack,get);//得到目前栈顶元素
    }
    double result=0;
    Pop(dstack,result);//最后操作数栈剩下的一个数字就是结果
    DestroyStack(cstack);
    DestroyStack(dstack);
    return result;
}

