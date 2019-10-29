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
    mov bp,0;keys中偏移量置0 
    mov di,0;frequent中偏移量置0 
    
    mov al,0b6h;向端口写入控制字进行初始化
    out 43h,al    
       
    lea dx,welcome 
    mov ah,9 ;屏幕输出welcome中字符串
    int 21h      
    ;换行回车
    mov dl,0dh
    mov ah,02h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h    
    
input:
    mov ah,7 ;从键盘获取输入
    int 21h
    cmp al,0dh;判断输入是否为回车
    je exit;若为回车，跳转到exit  
    ;若输入不是小写字母，则跳到myerror
    cmp al,61h;若小于a
    jb myerror
    cmp al,7ah;若大于z
    ja myerror                           
    
    lea di,keys;将keys地址送到di 
    lea bp,frequent;将frequent地址送到bp
    mov cx,21;循环次数为21  
    
find:
    cmp al,ds:[di];比较输入字符和keys的ASCII码
    je sing ;匹配成功则跳到sing
    add di,2;keys中偏移量加2  
    add bp,2;frequent中偏移量加2 
    loop find      
     
myerror:
    lea dx,err
    mov ah,9 ;屏幕输出err中字符串
    int 21h     
    ;换行回车
    mov dl,0dh
    mov ah,02h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h    
     
    jmp input
 
sing:   
    in al,61h;打开扬声器   
    or al,3      
    out 61h,al     
   
    mov bx,ds:[bp];找到对应的指定频率放在bx里,做除数
    mov ax,2870h;被除数为基准频率122870H
    mov dx,12h
    div bx;商默认放入ax
     
    out 42h,al;将频率低位送到42h端口 
    mov al,ah;
    out 42h,al;将频率高位送到42h端口
      
    call delay;进入延时子程序   
    ;关闭扬声器
    and al,0fch
    out 61h,al
    jmp input;等待下一个输入
    
exit:          
    mov ax, 4c00h;返回操作系统
    int 21h   
    
delay proc;延时子程序 
    push ax;保护现场
    push dx  
    mov ah,00h;计时
    int 1ah
    mov si,dx 
s2:      
    mov ah,00h
    int 1ah
    sub dx,si   
    cmp dx,7
    jna s2
  
    pop dx;恢复现场
    pop ax
    ret
delay endp
     
code ends

end start ; set entry point and stop the assembler.
