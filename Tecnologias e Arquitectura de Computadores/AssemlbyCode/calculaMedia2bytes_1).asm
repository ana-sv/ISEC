; Programa que usa um procedimento para calcular a
; media de dois bytes, usando registos para implementar
; a passagem de parametros
;
DATA_HERE 	SEGMENT
		lo_num	DB 64h
		hi_num	DB 11001000b
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


		mov al, lo_num 
		mov ah, hi_num
		call MEDIA
		mov average, al
		mov ah, 4ch
		int 21h

Main		endp

MEDIA	PROC 
		pushf
		push bx
		add al, ah
		mov ah, 00h
		adc ah, 00h
		mov bl, 02h
		div bl
		pop bx
		popf
		ret
MEDIA		ENDP

CODE_HERE	ENDS
		END Main

