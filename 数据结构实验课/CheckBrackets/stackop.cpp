#include"h2.h"

void InitStack(SqStack& S)
{ // ����һ����ջS
	if (!(S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
		exit(OVERFLOW); // �洢����ʧ��
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack& S)
{ // ����ջS��S���ٴ���
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

Status StackEmpty(SqStack S)
{ // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

void Push(SqStack& S, SElemType e)
{ // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize) // ջ����׷�Ӵ洢�ռ�
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); // �洢����ʧ��
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack& S, SElemType& e)
{ // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
