assume cs:codesg

data segment
    YEA db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995'
    ;�����Ǵ����ʾ21���21���ַ���,ÿ��4�ֽ�
    INCOME dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140317,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
    ;�����Ǵ����ʾ21�깫˾�������21��dword�����ݣ�ÿ��4�ֽ�
    EMPLOYEE dw 3,7,10,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11542,14430,15257,17800
    ;�����Ǵ����ʾ21�깫˾��Ա������21��word�����ݣ�ÿ��2�ֽ�
data ends

table segment
    TAB db 21 dup ('year summ ne ?? ');����һ��21�д��и�ʽ�����ݱ��
table ends 

stack segment
dw 0, 0
stack ends

code segment
start:
    ;ת�����ݺ�table
    mov ax,data
    mov ds,ax      ;��data����ds
    mov ax,table
    mov es,ax      ;��table��ԭ����������es��ʹtable����ʼ��ַΪes
 
    mov bx,0       ;bxΪds����ݺ������ƫ����           
    mov cx,21      ;ѭ��������Ϊ21
    mov di,0       ;diΪtable�ڵ�ƫ����
    mov si,0       ;siΪ��Ա������ƫ����
    
STORE_LINE:        ;��ѭ��21�Σ�������21������
    ;�����
    mov ax,ds:[bx] ;����ݵĸ���λ�������
    mov es:[di],ax
    mov ax,ds:[bx+2] ;����ݵĵ���λ�������
    mov es:[di+2],ax
    ;������
    mov ax,54H[bx] ;������ĸ���λ�������
    mov es:[di+5],ax
    mov ax,54H[bx+2] ;������ĵ���λ�������
    mov es:[di+7],ax
    ;������
    mov ax,0A8H[si]
    mov es:[di+10],ax
    ;���㣬�����˾�����
    mov ax,es:[di+5] ;���������ĸ���λ����ax
    mov dx,es:[di+7] ;���������ĵ���λ����dx
    div word ptr es:[di+10] ;��
    mov es:[di+13],ax   ;����������
    
    add bx, 4     ;��ݺ������ƫ�������ƫ��4���ֽ�
    add si,2      ;��Ա������ƫ�������ƫ��2���ֽ�
    add di,16     ;table��ƫ�����Ƶ���һ��
    loop STORE_LINE  
            
                             
    mov ax, 4c00h ;���ز���ϵͳ
    int 21h    
code ends

end start
