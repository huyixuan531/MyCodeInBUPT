assume cs:codesg

data segment
    var1 db 92h, 95h, 12h, 71h, 08h, 27h, 92h, 0c3h  ;变量var1保存长度为8个字节的有符号数1
    var2 db 8eh, 3dh, 0c2h, 0abh,7ah, 35h, 0a5h, 09h ;变量var2保存长度为8个字节的有符号数2
    len equ $-var2        ;len计算每个加数所占字节数，len不占用内存
    sum db len dup(0)     ;用于保存运算结果
data ends

stack1 segment stack      ;子程序设计必须定义堆栈段
    dw   40  dup(0)
stack1 ends

code segment
start:
    mov ax, data;将数据段存入ds
    mov ds, ax
    mov di,0    ;偏移量为0
    clc  ;使CF置0   
    mov cx,len  ;设置循环次数为8
L:
    mov al,sum[di];将sum压入栈底
    push ax 
    mov al,var1[di];将var1压入栈
    push ax
    mov al,var2[di];将var2压入栈
    push ax
    call ADDP;调用相加的子程序
    inc di       ;偏移量加1
    loop L
      
    ; 返回操作系统   
    mov ax, 4c00h
    int 21h
    
ADDP PROC           ;两数相加的子程序
    ;将ax,cx压入栈，保护现场
    push ax
    push cx    
    mov bp,sp;将当前栈顶指针值传给bp
    ;从堆栈取参数放在低八位              
    mov al,[bp+6];var1存入al
    mov bl,[bp+8];var2存入bl
    adc al,bl;将当前字al,bl相加（包括进位）
    mov sum[di],al;将相加结果存入sum
    ;恢复现场 
    pop cx
    pop ax     
    RET 6;将栈底var2,var1,sum依次弹出,返回主程序
ADDP ENDP    
        
ends

end start ; set entry point and stop the assembler.
