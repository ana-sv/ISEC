; Escrever string com memoria de video 

.8086
.model small
.stack 2048

dseg segment para public 'data'
     Texto byte 'Exemplo de Memoria de Video',0
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax,dseg
     mov ds,ax
	 
	 mov ax,0B800h	; memoria de video
	 mov es,ax 		;
	 
	 mov ah,01110100b		; atributos -> cores
	 xor si,si 				; indice da string (+1)
	 xor di,di 				; indice da memória de video (+2)
	 
ciclo:
	mov al,Texto[si]	; caracter do vetor Texto da posicao si em al 
	mov es:[di],al		; letra no memória de video
	mov es:[di+1],ah	; atributos na memória de video
	inc si				; incrementa posicao no vetor Texto
	add di,2			; incrementa posicao na memoria de video
	cmp al,0			; compara al com zero 
	jne	ciclo 			; jump if not equal, se não for zero, continua saltando para o inicio do ciclo
	 
	mov al,0
    mov ah,4ch
    int 21h
main endp
cseg ends

end main


;NOTES 

; linha 28 
; add di, 2 -> escreve na horizontal normalmente 
; add di,160 -> escreve na vertical, a cada iteração mudamos de linha 
; add di,162 -> escreve na diagonal, ou seja 160+2 , a cada iteracao muda de linha e avança duas colunas 
