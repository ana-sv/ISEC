; Pergunta de Exame

; Construa um porgrama em Assemble que obtenha as letras que surgem um 
; número par de vezes, tendo em consideracao que a string original se 
; encontra apresentada num formato compacto, no qual é especificado o 
; numero de vezes que a letra se repete. Considere ainda que a string 
; original termina com o valor 0 (zero), que os digitos existentes 
; correspondem a quantidades que um caracter se repete e que um caracter 
; se pode repetir ate 99. 

; Exemplo: 

; Nota: No exemplo apenas as letras S e E surgem um número par de vezes) 

;StrORIGINAL = 'I1S2E14c3'
;LETRAS = 'SE'

;?????????????????????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
		StrORIGINAL db 'I1S2E14c3',0
		LETRAS db ?
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov ax , 0B800h 	; memoria de video 
	 mov es, ax			;
	 
	 mov ah,0111b   ; atributos dos caracteres -> cinza sem piscar
	 xor si,si 				; indice da string (+1)
	 xor di,di 				; indice da memória de video (+2)
	 mov bl,2
	 
ciclo:
	mov al,StrORIGINAL[si]	; caracter do vetor Texto da posicao si em al
	cmp al,0
	je fim 
	ja incPosicao
	cmp al,9
	jb incPosicao
	
	div bl
	cmp ah,0
	je letraPar
	jmp incPosicao

	
incPosicao:
	inc si				; incrementa posicao no vetor Texto
	cmp al,0			; compara al com zero 
	jne	ciclo 			; jump if not equal, se não for zero, continua saltando para o inicio do ciclo
	
letraPar:
	mov LETRAS[di],al	
	mov es:[di],al		; letra no memória de video
	mov es:[di+1],ah	; atributos na memória de video
	jmp ciclo 
	
fim:	
    mov al, 0
    mov ah, 4ch
    int 21h
main endp
cseg ends

end main