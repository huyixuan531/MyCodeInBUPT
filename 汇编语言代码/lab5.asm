data segment
    maxlen db 15           ;0AH�ӹ�����ڲ�����ָ������ַ���
    inputlen db 0          ;0AH�ӹ��ܳ��ڲ���������ʵ��������ַ���
    str1 db 15 dup(0)      ;0AH�ӹ��ܣ����룩���ַ���������
    str2 db 15 dup(0)      ;09H�ӹ��ܣ���������ַ��������� 
data ends

stack1 segment stack
    dw  40h dup(0)
stack1 ends

code segment
start:
    ;�����ݶ��ƶ���ds
    mov ax, data
    mov ds, ax  
    ;�ַ������룬����str1
    lea dx,maxlen   
    mov ah,0ah
    int 21h  
    ;ѭ���ж��Ƿ�Ϊ����
    mov di,0;str1��ƫ����    
    mov si,0;str2��ƫ����
    mov cl,inputlen;ѭ������ 
L: 
    mov bl,str1[di];ȡstr1�е�һ������       
    ;������������ת��J������str2��
    cmp bl,30h;��С��0
    jb J
    cmp bl,39h;������9
    ja J
BACK:
    inc di;ƫ������1
    loop L  
    ;��str2��'$'��
    mov str2[si],24h
    ;��ת�ӳ���
    CALL SUB1
    ;�ַ���str2���    
    lea dx,str2
    mov ah,09h
    int 21h
    ;���ز���ϵͳ    
    mov ax, 4c00h
    int 21h   
J:  
    mov str2[si],bl;����str2 
    inc si;ƫ������1                                        BBB:      ......
    jmp BACK 
SUB1 PROC ;������лس�
    mov dl,0dh
    mov ah,02h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h    
    RET
SUB1 ENDP
  
ends

end start ; set entry point and stop the assembler.
