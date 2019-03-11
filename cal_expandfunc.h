#ifndef CAL_EXPANDFUNC_H
#define CAL_EXPANDFUNC_H
#include "data_struct.h"

template<class T>
Status InitStack(SqStack<T> &S);//��ʼ��ջ 
template<class T>
Status GetTop(SqStack<T> S,T &e);//�õ�ջ��Ԫ�� 
template<class T>
Status Push(SqStack<T> &S,T e);//��Ԫ��e��ջ 
template<class T>
Status Pop(SqStack<T> &S,T &e);//��ջ����ֵ��e 
template<class T>
Status DestroyStack(SqStack<T> &S);//����ջ 
//����Ϊջ����ز���

bool ifop(char c);//�ж��Ƿ��ǲ����������򷵻�true�����򷵻�false 
bool ifnum(char c);//�ж��Ƿ������֣����򷵻�true�����򷵻�false 
bool ifidentifier(char *c);//�ж��Ƿ���c���Եı���ʶ��������򷵻�true�����򷵻�false 
bool check(char *c);//�����ʽ���Ƿ��зǷ����ַ�
char *strrpc(char *str,char *oldstr,char *newstr);//�ַ����滻����
bool findFuncName(char* name);//Ѱ�Һ������Ƶĺ���
int precede(char a,char b);//�жϲ��������ȼ�
template<class T>
T calculate(T a,char op,T b);
//����Ϊ���ʽ��ֵ�������õ��ĸ�������

function Inifunction(char *str);//��ʼ�����������������ľ�����õ��ִ�������ʵ�ʵĺ����ṹ
double run(struct function func);//���еĺ���������Ԥ��������������ת���ɱ��ʽ��ֵ���͵��ü��㺯��  
double calcuresult(char str[]);//���ʽ��ֵ������Ҳ�����ں�����ֵ

#endif // CAL_EXPANDFUNC_H

