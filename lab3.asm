assume cs:codesg

data segment
  arry1 dw 223,4037,5635,8226,11542,14430,45257,811
  len equ $-arry1  ;��arry1�ĵ�ַ����len
  res1 db len dup(0) ;����һ���������arry���ȸ�0
data ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    mov ax, data   ;��data�δ���ds
    mov ds, ax 
    mov di,0       ;diΪ����res1�ڵ�ƫ����
    mov si,0       ;siΪ����arry�ڵ�ƫ����
    mov cx,len/2   ;��ѭ��������Ϊ8 
     
s1: ;��ѭ����ָ����һ����
    mov bl,0        ;������������Ϊ0
    mov ax,arry1[si];��arry1��������ax
    
s2: ;��ѭ��������һλ����CF
    test ax,0FFFFH  ;�����Ƿ���λ���
    jz END0         ;�����꣬�򷵻���ѭ��
    shl ax,1  ;��ax�е�������һλ���Ƴ�λ����CF
    jnc N     ;��CFλΪ0������ת��N
    inc res1[di];������������1
    N:
    jmp s2;��CFλΪ0�������������䣬������ѭ��
    END0:    
    inc di           ;����res��ƫ������1
    add si,2         ;arry��ƫ������2
    loop s1
          
    mov ax, 4c00h ;���ز���ϵͳ
    int 21h    
    ends

end start
