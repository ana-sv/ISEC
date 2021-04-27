.model small
.8086
.stack 2048h

dseg	segment para public 'data'
	nelem	db	10
	operando1	db	dup(10)
	operando2	db  dup(10)
	multiplic 	dw	dup(10)
	quodiv		db	dup(10)
dseg ends

cseg	segment para public 'data'
	assume cs:cseg,ds:dseg
	
	xor si,si
	xor di,di
	
	mov cx,nelem
	
	main:
	
		mov ax,0
		mov bx,0
		mov dx,0
		mov al,operando1[si]
		mov bl,operando2[si]
		mov multiplic[si],0
		mov quodiv[si],0
		
		ciclo1:
		
		add ax,al
		mov multiplic[si],ax
		inc dx
		cmp dx,operando2[si]
		jne ciclo1
		
		
		mov ax,0
		mov bx,0		
		mov al,operando1[si]
		mov bl,operando2[si]
		mov dx,0
		
		ciclo2:
		cmp al,bl
		jge subtrai
		mov quodiv[si],cx
		inc si
		inc cx
		cmp cx,10
		jne:main
		
		jmp fim:
		
		subtrai:
		sub al,bl
		inc dx
		jmp ciclo2
		
		fim:
		
		cseg ends

		
		
		;saltar para main se a si for diferente de nelem
		

