; Considerando que a variável NUMERO contém um valor numérico
; compreendido entre [0 - 65535], faça um programa, em linguagem Assembly
; que conte o número de dígitos a zero existentes em NUMERO. Suponha que o
; número se encontra na base 10. O resultado deverá ficar armazenado na
; variável QUANT. (Ex: Para NUMERO=10230, QUANT=2)

;??????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     NUMERO dw 10230
	 QUANT db 0
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax

     mov bx,10		; inicializa bx com 10
	 mov ax,NUMERO	; ax fica com o valor da variavel NUMERO
	 
ciclo:
	xor dx,dx		; se dx=dx -> 0 , se dx!=dx -> 1
	div bx			; 
	cmp ax,0		; compara ax com 0
	je fim			; jump if equal, se ax for 0 salta para fim
	cmp dx,0		; compara dx com 0
	jne ciclo		; se dx nao for zero, salta para o inicio do ciclo
	inc QUANT		; se nao saltou na intrucao anterior, incrementa a variavel QUANT
	jmp ciclo 		; salta para o inicio do ciclo

fim:
	mov ah, 4ch
    int 21E
	
main endp
cseg ends

end main


