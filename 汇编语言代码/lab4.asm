assume cs:codesg

data segment
    var1 db 92h, 95h, 12h, 71h, 08h, 27h, 92h, 0c3h  ;����var1���泤��Ϊ8���ֽڵ��з�����1
    var2 db 8eh, 3dh, 0c2h, 0abh,7ah, 35h, 0a5h, 09h ;����var2���泤��Ϊ8���ֽڵ��з�����2
    len equ $-var2        ;len����ÿ��������ռ�ֽ�����len��ռ���ڴ�
    sum db len dup(0)     ;���ڱ���������
data ends

stack1 segment stack      ;�ӳ�����Ʊ��붨���ջ��
    dw   40  dup(0)
stack1 ends

code segment
start:
    mov ax, data;�����ݶδ���ds
    mov ds, ax
    mov di,0    ;ƫ����Ϊ0
    clc  ;ʹCF��0   
    mov cx,len  ;����ѭ������Ϊ8
L:
    mov al,sum[di];��sumѹ��ջ��
    push ax 
    mov al,var1[di];��var1ѹ��ջ
    push ax
    mov al,var2[di];��var2ѹ��ջ
    push ax
    call ADDP;������ӵ��ӳ���
    inc di       ;ƫ������1
    loop L
      
    ; ���ز���ϵͳ   
    mov ax, 4c00h
    int 21h
    
ADDP PROC           ;������ӵ��ӳ���
    ;��ax,cxѹ��ջ�������ֳ�
    push ax
    push cx    
    mov bp,sp;����ǰջ��ָ��ֵ����bp
    ;�Ӷ�ջȡ�������ڵͰ�λ              
    mov al,[bp+6];var1����al
    mov bl,[bp+8];var2����bl
    adc al,bl;����ǰ��al,bl��ӣ�������λ��
    mov sum[di],al;����ӽ������sum
    ;�ָ��ֳ� 
    pop cx
    pop ax     
    RET 6;��ջ��var2,var1,sum���ε���,����������
ADDP ENDP    
        
ends

end start ; set entry point and stop the assembler.
