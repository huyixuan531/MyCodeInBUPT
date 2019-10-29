#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX_STR_LEN 40 // 用户可在255(1个字节)以内定义最大串长
typedef char SString[MAX_STR_LEN + 1]; // 字符串，0号单元存放串的长度
extern int mycount;

int isInt(char str[]);
int index(SString S, SString T, int pos);
int strAssign(SString T, char* chars);
int Index_KMP(SString S, SString T, int pos, int next[]);
void get_next(SString T, int next[]);
void get_nextval(SString T, int nextval[]);