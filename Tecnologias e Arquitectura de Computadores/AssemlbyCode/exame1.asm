; Pergunta de Exame - Época Normal 2020

; Faca um programa em Assembly que ,partindo de um vector com valores
; de 0 a 255, devolva a media desses valores. A media final devera ser
; arredondada para o valor inteiro mais proximo da media numerica. 
; Por exemplo:

; VECTOR = 59,112,64,74,130,58,37,255	(media numerica = 98.625)
; MEDIA FINAL = 99

; Dica: Analise o resto da divisao para obter o valor inteiro mais 
; proximo da media numerica 

;?????????????????????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     VECTOR db 59,112,64,74,130,58,37,255
	 MEDIA db ? 
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov ax , 0B800h 	; memoria de video 
	 mov es, ax			;
	 
	 mov si,0
	 mov di,0
	 
ciclo:
	xor ah,ah
	add al, VECTOR[si]	; al fica com copia do valor em VECTOR posicao si
	adc ah,0			; ah = ah+0+flagCarry
	cmp al,0			; compara al com 0
	je fim				; jump if equal, se al for iguala 0 termina
	inc si				; incrementa si 
	inc bl 				; incrementa numero de elementos 
	jmp ciclo			; salta para ciclo
	
	
fim:
	div bl			; divide ax por bl 
	;---------------- falta a parte de arredondar o numero 
	mov MEDIA,al	
	

     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main