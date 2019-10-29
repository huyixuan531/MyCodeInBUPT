#include"h2.h"

void InitStack(SqStack& S)
{ // 构造一个空栈S
	if (!(S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack& S)
{ // 销毁栈S，S不再存在
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

Status StackEmpty(SqStack S)
{ // 若栈S为空栈，则返回TRUE，否则返回FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

void Push(SqStack& S, SElemType e)
{ // 插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize) // 栈满，追加存储空间
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); // 存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}

Status Pop(SqStack& S, SElemType& e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
