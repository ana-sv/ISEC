; Faça um programa que permita contar todos os espaços em branco de
; uma cadeia de caracteres em memória. A cadeia de caracteres é guardada
; como um conjunto de células terminadas pelo valor zero e de início no
; endereço START.

;????????????????????????????????????????????????????????????????????

.8086
.model	small
.stack	2048

DADOS	SEGMENT PARA 'DATA'
	START db 'Contar espacos embranco ',0  ;0 é o caracter de término de vetor, diz que o vetor terminou com o numero 0
	NUM db ?
DADOS	ENDS

CODIGO	SEGMENT PARA 'CODE'
	ASSUME CS:CODIGO, DS:DADOS
INICIO:
	mov si,0
	mov di,0
	
ciclo:
	mov al,START[si]  ;valor de START na posicao si para al
	cmp al,' '		  ;compara para ver se é espaco em branco
	jne fim			  ; jump if not equal, salta para fim se nao for espaco 
	inc bl 			  ; incrementa contador de espacos
	
fim: 				; se nao for espaco
	inc si 			; incrementa posicao
	cmp al,0 		; compara para ver se esta no final da string
	jne ciclo		; jump in not equal , se nao for o final da string continua para cilco
	mov NUM, bl		; se for final da string guarda numero de espacos na variavel NUM

	mov al,0
    mov ah, 4ch 
    int 21h 

CODIGO	ENDS
END	INICIO