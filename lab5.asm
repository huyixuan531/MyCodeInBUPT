data segment
    maxlen db 15           ;0AH子功能入口参数，指定最大字符数
    inputlen db 0          ;0AH子功能出口参数，返回实际输入的字符数
    str1 db 15 dup(0)      ;0AH子功能（输入）的字符串缓存区
    str2 db 15 dup(0)      ;09H子功能（输出）的字符串缓存区 
data ends

stack1 segment stack
    dw  40h dup(0)
stack1 ends

code segment
start:
    ;将数据段移动到ds
    mov ax, data
    mov ds, ax  
    ;字符串输入，存入str1
    lea dx,maxlen   
    mov ah,0ah
    int 21h  
    ;循环判断是否为数字
    mov di,0;str1内偏移量    
    mov si,0;str2内偏移量
    mov cl,inputlen;循环次数 
L: 
    mov bl,str1[di];取str1中的一个数据       
    ;不是数字则跳转到J（存入str2）
    cmp bl,30h;若小于0
    jb J
    cmp bl,39h;若大于9
    ja J
BACK:
    inc di;偏移量加1
    loop L  
    ;给str2加'$'符
    mov str2[si],24h
    ;跳转子程序
    CALL SUB1
    ;字符串str2输出    
    lea dx,str2
    mov ah,09h
    int 21h
    ;返回操作系统    
    mov ax, 4c00h
    int 21h   
J:  
    mov str2[si],bl;存入str2 
    inc si;偏移量加1                                        BBB:      ......
    jmp BACK 
SUB1 PROC ;输出换行回车
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
