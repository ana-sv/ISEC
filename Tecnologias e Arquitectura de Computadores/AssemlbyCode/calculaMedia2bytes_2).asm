; Programa que usa um procedimento para calcular a
; media de dois bytes, usando posicoes de memoria para 
; implementar a passagem de parametros
;
DATA_HERE 	SEGMENT
		lo_num DB 64h
		hi_num DB 11001000b
		average DB ?
DATA_HERE	ENDS

STACK_HERE 	SEGMENT STACK
		DW 40 DUP(0)
STACK_HERE	ENDS

CODE_HERE	SEGMENT
		ASSUME CS:CODE_HERE, DS:DATA_HERE, SS: STACK_HERE
Main		Proc
		mov ax, DATA_HERE
		mov ds, ax
		
		call MEDIA
		mov ah, 4ch
		int 21h
Main		endp

MEDIA		PROC
		pushf
		push ax
		push bx
		mov al, lo_num
		add al, hi_num
		mov ah, 00h
		adc ah, 00h
		mov bl, 02h
		div bl
		mov average, al
		pop bx
		pop ax
		popf
		ret
MEDIA		ENDP
CODE_HERE	ENDS
		END Main

