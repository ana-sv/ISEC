.8086
.model small
.stack 2048

; EXERCICIO TIPO EXAME
; Faça um programa em Assembly que some os valores impares
; presentes num vetor de bytes. O vector tera no maximo 20 elementos.
; Caso tenha menos elementos , o ultimo valor sera seguido do valor 0

; ALGORITMO TIPS
; usamos ciclo para os 20 e dentro do ciclo comparamos com 0
; ver se o numero é impar -> dividir por 2 e tem que dar resto 0


dseg segment para public 'data'
     Vetor db  3,4,5,6,7,8,0
	 Resto dw  0
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
	
	main proc
		mov ax, dseg
		mov ds, ax

		xor si,si	; inicializa si a 0 
		mov cx,20	; inicializa cx a 20 
		mov bl,2	; inicializa bl a 2
		xor dx,dx	; inicializa dx a 0 
	
ciclo:	xor ah,ah			; inicializa ah a 0
		mov al,Vetor[si]	; al fica com uma copia do valor na posicao si do Vetor
		cmp al,0			; compara al com 0
		je fim				; jump if equal , se al for igual a 0 salta para fim 
		div bl				; divide ax por bl ficando quociente em al e resto em ah 
		cmp ah,0			; compara ah com 0 
		je incPosicao 		; jump if equal, se ah for igual a zero dalta para incPosicao
		add dl,Vetor[si] 	; adiciona o valor de Vector na posicao si a dl
		adc dh,0 			; dh = dh+0+flagCarry
		
incPosicao: 
		inc si
		loop ciclo 
	
fim:
	mov Resto, dx	; copia o valor de dx para a variavel Resto
	mov ah, 4ch		; Escolha da funcao DOS  a executar de seguida 
    int 21h 		; Chamada a uma funcao de DOS 
		
	main endp
cseg ends

end main