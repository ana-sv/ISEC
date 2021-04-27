; Faça um programa que some os elementos de dois 
; vectores colocando o resultado num 3º.

;?????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     Vetor1 db 1,2,3,4,5,6,7,8,9,10
	 Vetor2 db 11,12,13,14,15,16,17,18,19,20
	 Vetor3 dw 10 
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax

ciclo:
	xor ah, ah			; XOR só é 1 se 1 das expressoes é TRUE, entao aqui ah = 0
	mov al,Vetor1[si]	; soma elemento de Vetor 1 a al
	add al,Vetor2[si] 	; em al está a soma dos elementos dos 2 vetores 
	adc ah, 0			; ah=ah+carry+0
	mov Vetor3[si],ax
	inc si				; incrementa si
	loop ciclo			; volta ao inicio do ciclo
	

     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main