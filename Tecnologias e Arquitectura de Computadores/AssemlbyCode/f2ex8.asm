; Faça um programa que some dois números de 8 bits,
; cujos endereços iniciais são Address1 e Address2,
; deixando o resultado num espaço reservado a partir
; de Address3. Identifique cada uma das instruções.


.8086
.model  small
.stack  2048

dados	segment		para	'data'
        Address1	db	5
        Address2  	db	6
        Address3	dw	?
dados	ends

codigo	segment para 'code'
	main	proc
        assume cs:codigo, ds:dados
	
	mov	ax,dados
	mov	ds,ax
	
	xor     bh,bh				; poe bh a zero
	mov		bl,Address1
	add		bl,Address2
    adc     bh,0				;bh=0+0+c
	mov 	Address3,bx

	mov ah,4Ch    ; Escolha da Funcao DOS a executar de seguida
	int 21h       ; Chamada a uma funcao de DOS

	main	endp
codigo	ends
end	main
