; Faça um programa que converta todos os caracteres 
; maiúsculos de uma string, terminada pelo caracter 
; zero, para minúsculos

;??????????????????????????????????????????????????????????????

; $ ----> [Numeros 0 - 9] ----> [Letras Maiusculas A - Z] ----> [Letras Minusculas a - z ]
; assim apenas queremos alterar entre A e Z , para tras de A e para a frente de Z nao se faz nada 

;	'A' = 65   	'a'= 94      ->			assim, para tornar maiusculas em minusculas, add 32 ou 20h  

.8086
.model small
.stack 2048

dseg segment para public 'data'
     START db 'Um 2 Tres maCAQuinHO do CHINES0'
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 xor si,si ; iniciar si a zero 
	 
ciclo:
	mov al, START[si]
	cmp al,'0'
	je fim
	cmp al,'A'		; compara al com A
	jb incPosicao 	; jumb if bellow, se al for menor que A entao salta para incrementar posicao
	cmp al,'Z'		; compara al com Z
	ja incPosicao	; jump if above, se al for maior que Z entao salta para incrementar posicao
	add al, 20h		; chegam a esta linha apenas os caracteres amiusculos e tornam-se minusculas
	mov START[si], al ; e guarda-se no vetor
	
incPosicao: 
	inc si
	jmp ciclo
		
fim: 
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main