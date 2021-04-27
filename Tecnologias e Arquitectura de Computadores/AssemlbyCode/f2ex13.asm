; Elabore um programa que permita contar os caracteres minúsculos,
; maiúsculos e dígitos numéricos de uma cadeia de caracteres em memória.
; A cadeia de caracteres é guardada como um conjunto de células
; terminadas pelo carácter $

;??????????????????????????????????????????????????????????????

; $ ----> [Numeros 0 - 9] ----> [Letras Maiusculas A - Z] ----> [Letras Minusculas a - z ]


.8086
.model small
.stack 2048

dseg segment para public 'data'
     START db '1 dois 3 macaquinho do chines$'
	 NUM db 0
	 MAI db 0
	 MIN db 0
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
	 
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov si,si
	 
ciclo: mov al, START[si] 	; inicializa-se em al ou em qq registo que ocupe 1 byte que é o tamanho do vetor
	cmp al, '$'      		; compara al com $ 
	je fim 					; jump if equal , se al == $ salta para fim 
	cmp al, '0'				; compara al com 0 
	jb incPosicao			; jumb if bellow, se menor que 0 salta para incPosicao
	cmp al, '9'				; compara al com 9
	ja letras      			; jump above, se maior salta para letras
	jb numeros				; jump bellow, se for menor salta para numeros 
	

numeros:
	inc NUM 		; incrementa contador de numeros
	inc si			; incrementa posicao 
	jmp incPosicao
	

letras: 
	cmp al, 'A'  
	jb incPosicao		; jump bellow, se menor que A incrementa posicao 
	cmp al, 'Z'
	ja minuscula		; jump above, se maior de Z pode ser minucula
	inc MAI		; se nao saltou na instrucao anterior, entao é maiuscula 
	jmp incPosicao 		
	
minuscula:
	cmp al,'a'			; compara al com a minusculo
	jb incPosicao		; jump bellow , se al é menor que a salta para incPosicao
	cmp al, 'z'		 	; compara al com z minusculo
	ja incPosicao  		; jump above, se al é maior que z entao nao é minuscula
	inc MIN				; se nao saltou na alterior , é porque é minuscula e incrementa-se a variavel das minusculas 
	jmp incPosicao
	
incPosicao:
	inc si		; incrementa posicao 
	jmp ciclo	; salta para ciclo
	
fim:

     mov al, 0
     mov ah, 4ch
     int 21h
	 
main endp
cseg ends

end main