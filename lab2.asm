assume cs:codesg

data segment
    YEA db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995'
    ;以上是存入表示21年的21个字符串,每个4字节
    INCOME dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140317,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
    ;以上是存入表示21年公司总收入的21个dword型数据，每个4字节
    EMPLOYEE dw 3,7,10,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11542,14430,15257,17800
    ;以上是存入表示21年公司雇员人数的21个word型数据，每个2字节
data ends

table segment
    TAB db 21 dup ('year summ ne ?? ');建立一个21行带有格式的数据表格
table ends 

stack segment
dw 0, 0
stack ends

code segment
start:
    ;转移数据和table
    mov ax,data
    mov ds,ax      ;将data移入ds
    mov ax,table
    mov es,ax      ;将table中原有数据移入es，使table的起始地址为es
 
    mov bx,0       ;bx为ds内年份和收入的偏移量           
    mov cx,21      ;循环变量设为21
    mov di,0       ;di为table内的偏移量
    mov si,0       ;si为雇员人数的偏移量
    
STORE_LINE:        ;外循环21次，共存入21年数据
    ;存年份
    mov ax,ds:[bx] ;将年份的高两位存入表中
    mov es:[di],ax
    mov ax,ds:[bx+2] ;将年份的低两位存入表中
    mov es:[di+2],ax
    ;存收入
    mov ax,54H[bx] ;将收入的高两位存入表中
    mov es:[di+5],ax
    mov ax,54H[bx+2] ;将收入的低两位存入表中
    mov es:[di+7],ax
    ;存人数
    mov ax,0A8H[si]
    mov es:[di+10],ax
    ;计算，保存人均收入
    mov ax,es:[di+5] ;将被除数的高两位存入ax
    mov dx,es:[di+7] ;将被除数的低两位存入dx
    div word ptr es:[di+10] ;除
    mov es:[di+13],ax   ;结果存入表中
    
    add bx, 4     ;年份和收入的偏移量向后偏移4个字节
    add si,2      ;雇员人数的偏移量向后偏移2个字节
    add di,16     ;table内偏移量移到下一行
    loop STORE_LINE  
            
                             
    mov ax, 4c00h ;返回操作系统
    int 21h    
code ends

end start
