assume cs:codesg

data segment
  arry1 dw 223,4037,5635,8226,11542,14430,45257,811
  len equ $-arry1  ;将arry1的地址赋给len
  res1 db len dup(0) ;定义一个数组存有arry长度个0
data ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    mov ax, data   ;将data段存入ds
    mov ds, ax 
    mov di,0       ;di为数组res1内的偏移量
    mov si,0       ;si为数组arry内的偏移量
    mov cx,len/2   ;外循环次数设为8 
     
s1: ;外循环，指向下一个数
    mov bl,0        ;将计数变量置为0
    mov ax,arry1[si];将arry1的数放入ax
    
s2: ;内循环，左移一位数到CF
    test ax,0FFFFH  ;测试是否移位完毕
    jz END0         ;若移完，则返回外循环
    shl ax,1  ;将ax中的数左移一位，移出位存入CF
    jnc N     ;若CF位为0，则跳转到N
    inc res1[di];计数变量自增1
    N:
    jmp s2;若CF位为0，计数变量不变，继续内循环
    END0:    
    inc di           ;数组res内偏移量加1
    add si,2         ;arry内偏移量加2
    loop s1
          
    mov ax, 4c00h ;返回操作系统
    int 21h    
    ends

end start
