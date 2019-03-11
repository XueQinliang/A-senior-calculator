#ifndef CAL_EXPANDFUNC_H
#define CAL_EXPANDFUNC_H
#include "data_struct.h"

template<class T>
Status InitStack(SqStack<T> &S);//初始化栈 
template<class T>
Status GetTop(SqStack<T> S,T &e);//得到栈顶元素 
template<class T>
Status Push(SqStack<T> &S,T e);//将元素e入栈 
template<class T>
Status Pop(SqStack<T> &S,T &e);//出栈并赋值给e 
template<class T>
Status DestroyStack(SqStack<T> &S);//销毁栈 
//以上为栈的相关操作

bool ifop(char c);//判断是否是操作符，是则返回true，否则返回false 
bool ifnum(char c);//判断是否是数字，是则返回true，否则返回false 
bool ifidentifier(char *c);//判断是否是c语言的变量识别符，是则返回true，否则返回false 
bool check(char *c);//检测表达式中是否有非法的字符
char *strrpc(char *str,char *oldstr,char *newstr);//字符串替换函数
bool findFuncName(char* name);//寻找函数名称的函数
int precede(char a,char b);//判断操作符优先级
template<class T>
T calculate(T a,char op,T b);
//以上为表达式求值过程中用到的辅助函数

function Inifunction(char *str);//初始化函数，即将函数的具体调用的字串解析成实际的函数结构
double run(struct function func);//运行的函数，负责预处理（将函数调用转化成表达式求值）和调用计算函数  
double calcuresult(char str[]);//表达式求值函数，也可用于函数求值

#endif // CAL_EXPANDFUNC_H

