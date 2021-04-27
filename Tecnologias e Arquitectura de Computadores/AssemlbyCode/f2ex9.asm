; Faça um programa que copie uma cadeia de caracteres de um
; vector de bytes para outro. 
; Os endereços iniciais dos vectores são respectivamente 
; Vector1 e Vector2. A cadeia de caracteres é terminada por 
; um caracter de valor zero.


.8086
.model	small
.stack	2048

dados	segment para	'data'
	Vector1	db	'Cadeira - T.I.',0        
	Vector2	db	 100 dup(?)
dados	ends


codigo	segment para 'code'
	main	proc
	assume cs:codigo, ds:dados
	
		mov	ax,dados
		mov	ds,ax

		xor	si,si				; si = 0 
ciclo:	mov	ah, Vector1[si]     ; ah fica com caracter de vector 1 
        mov Vector2[si],ah		;  vector 2 fica com cacarcter em ah 
		inc	si					; incrementa si
		cmp	ah,0				; compara -> equanto ah não for zero
        jne ciclo				; volta ao inicio do ciclo
		
        mov     ah,4Ch    ; Escolha da Funcao DOS a executar de seguida
		int     21h       ; Chamada a uma funcao de DOS

	main	endp
codigo	ends
end	main

