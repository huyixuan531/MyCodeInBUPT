#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX_STR_LEN 40 // �û�����255(1���ֽ�)���ڶ�����󴮳�
typedef char SString[MAX_STR_LEN + 1]; // �ַ�����0�ŵ�Ԫ��Ŵ��ĳ���
extern int mycount;

int isInt(char str[]);
int index(SString S, SString T, int pos);
int strAssign(SString T, char* chars);
int Index_KMP(SString S, SString T, int pos, int next[]);
void get_next(SString T, int next[]);
void get_nextval(SString T, int nextval[]);