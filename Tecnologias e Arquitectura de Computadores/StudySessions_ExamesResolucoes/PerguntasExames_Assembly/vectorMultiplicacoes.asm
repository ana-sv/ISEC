; Faça um programa em Assembly que, partindo de um vector com valores
; entre 0 a 255, calcule um novo vector com o resultado da 
; multiplicação dos valores desde a extremidade para o centro
; ( primeiro X ultimo , segundo X penultimo , etc ) 
;

.8086
.model small
.stack 2048

dseg segment para public 'data'
     vectorinic db 59, 112, 64, 74, 0, 130, 58, 37, 255
	 vecto final dw ? 
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 xor si, si
	 mov cx , 9 
	 mov bl, 2
	 xor dx, dx 
	 
ciclo:
	 mov al, vectorinic[si]
	 xor ah, ah 
	 div bl
	 mul ah, 0 
	 je proximo
	 add dl, vectorinic[si]
	 adc dh, 0

proximo:
	 inc si 
	 cmp vectorinic[si], 0
	 loopne ciclo
	
	 mov vectorfinal, dx

     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main