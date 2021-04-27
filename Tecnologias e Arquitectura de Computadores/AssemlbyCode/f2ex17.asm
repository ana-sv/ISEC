;  Faça um programa em Assembly que transforme uma sequência de caracteres,
; cada um representando um valor inteiro de um único dígito, num único valor
; numérico em que cada um dos seus dígitos são os elementos referidos. Assuma
; que o primeiro elemento da cadeia de caracteres tem um valor indicativo do
; número total de elementos que a constitui. Assuma também que o valor gerado
; não é superior a 65535.

; Exemplo: String 5, ‘1’,’2’, ‘3’, ‘4’, ‘8’
; Número gerado 12348

; NOTA: subtrair 30h para converter de caracter para numero

.8086
.model small
.stack 2048

dseg	segment para public 'data'
	var1	db	5,'1','2','3','4','8'
	var2	dw	?
dseg	ends

cseg	segment para public 'code'
assume	cs:cseg, ds:dseg
	Main  proc
		mov	ax, dseg
		mov	ds,ax

		xor	ax,ax			; inicializa ax a 0
		xor	bh,bh			; inicializa bh a 0
		xor	si,si			; inicializa si a 0
		mov	cl,var1[si]		; cl fica com uma copia do valor de var1 na posicao si
		xor	ch,ch			; inicializa ch a o
		inc	si				; incrementa si
		mov	di,10			; di fica com o valor de 10 
		
	ciclo:	
		mul	di				; se di -> 8 bits -> ax= al*di
							; se di -> 16 bits -> dx:ax=ax*di
		mov	bl,var1[si]		; bl fica com uma copia do valor de var1 na posicao si
		sub	bl,48			; bl = bl - 48 - flagCarry 
		add	ax,bx			; ax = ax + bx 
		inc	si				; incrementa si
		loop ciclo			; salta para ciclo 
		
		mov	var2,ax 	;var2 fica com uma copia do valor em ax 		
		mov	ah,4CH
		int	21H
Main	endp
Cseg	ends
end	Main


