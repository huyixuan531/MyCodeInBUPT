#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<ctype.h>
#include<malloc.h> 
#include<limits.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<io.h> 
#include<math.h> 
#include<process.h> 
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;
typedef int Boolean;
typedef char SElemType;//ջ��Ԫ������Ϊchar

#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACK_INCREMENT 2 // �洢�ռ��������

struct SqStack
{
	SElemType* base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType* top; // ջ��ָ��
	int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

//ջ�Ļ�������
void InitStack(SqStack& S);
void DestroyStack(SqStack& S);
Status StackEmpty(SqStack S);
void Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
//��������
int isInt(char str[]);//�ж������Ƿ�Ϊint