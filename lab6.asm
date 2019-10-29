data segment
    welcome db 'Welcome to the Piano! qwertyu:high1-7 asdfghj:middle1-7 zxcvbnm:low1-7$'
    keys dw 'q','w','e','r','t','y','u','a','s','d','f','g','h','j','z','x','c','v','b','n','m'
    frequent dw 523,587,659,698,784,880,988,262,294,330,349,392,440,494,131,147,165,175,196,220,247
    err db 'This key is invalid!$'
data ends

stack segment stack
    db   128  dup(0)
stack ends

code segment  
assume ds:data,cs:code
start:   
    mov dx,28bh
    mov al,10000000b
    out dx,al
    
    mov dx,288h
    mov al,03h
    out dx,al
    
    mov dx,283h
    mov al,00110110b
    out dx,al
    
    mov ax, data
    mov ds, ax  
    mov bp,0;keys��ƫ������0 
    mov di,0;frequent��ƫ������0 
    
    mov al,0b6h;��˿�д������ֽ��г�ʼ��
    out 43h,al    
       
    lea dx,welcome 
    mov ah,9 ;��Ļ���welcome���ַ���
    int 21h      
    ;���лس�
    mov dl,0dh
    mov ah,02h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h    
    
input:
    mov ah,7 ;�Ӽ��̻�ȡ����
    int 21h
    cmp al,0dh;�ж������Ƿ�Ϊ�س�
    je exit;��Ϊ�س�����ת��exit  
    ;�����벻��Сд��ĸ��������myerror
    cmp al,61h;��С��a
    jb myerror
    cmp al,7ah;������z
    ja myerror                           
    
    lea di,keys;��keys��ַ�͵�di 
    lea bp,frequent;��frequent��ַ�͵�bp
    mov cx,21;ѭ������Ϊ21  
    
find:
    cmp al,ds:[di];�Ƚ������ַ���keys��ASCII��
    je sing ;ƥ��ɹ�������sing
    add di,2;keys��ƫ������2  
    add bp,2;frequent��ƫ������2 
    loop find      
     
myerror:
    lea dx,err
    mov ah,9 ;��Ļ���err���ַ���
    int 21h     
    ;���лس�
    mov dl,0dh
    mov ah,02h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h    
     
    jmp input
 
sing:   
    in al,61h;��������   
    or al,3      
    out 61h,al     
   
    mov bx,ds:[bp];�ҵ���Ӧ��ָ��Ƶ�ʷ���bx��,������
    mov ax,2870h;������Ϊ��׼Ƶ��122870H
    mov dx,12h
    div bx;��Ĭ�Ϸ���ax
     
    out 42h,al;��Ƶ�ʵ�λ�͵�42h�˿� 
    mov al,ah;
    out 42h,al;��Ƶ�ʸ�λ�͵�42h�˿�
      
    call delay;������ʱ�ӳ���   
    ;�ر�������
    and al,0fch
    out 61h,al
    jmp input;�ȴ���һ������
    
exit:          
    mov ax, 4c00h;���ز���ϵͳ
    int 21h   
    
delay proc;��ʱ�ӳ��� 
    push ax;�����ֳ�
    push dx  
    mov ah,00h;��ʱ
    int 1ah
    mov si,dx 
s2:      
    mov ah,00h
    int 1ah
    sub dx,si   
    cmp dx,7
    jna s2
  
    pop dx;�ָ��ֳ�
    pop ax
    ret
delay endp
     
code ends

end start ; set entry point and stop the assembler.
