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
typedef char SElemType;//栈的元素类型为char

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACK_INCREMENT 2 // 存储空间分配增量

struct SqStack
{
	SElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType* top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

//栈的基本操作
void InitStack(SqStack& S);
void DestroyStack(SqStack& S);
Status StackEmpty(SqStack S);
void Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
//其他函数
int isInt(char str[]);//判断输入是否为int