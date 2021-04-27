; Faca um programa, em Assembly, que copie 2 colunas consecutivas
; existentes no ecra (modo texto, policromatico 25x80) e apresente 
; as mesmas 20 colunas a frente. No segmento de dados esta especificada
; a coluna a partir da qual o deslocamento e efectuado.

;?????????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     ; VARIAVEIS...
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax

    17 e 18  aceder á memoria de video

	mov cx, 25 ; para usar o loop 
	
	mov al,coluna  ; multiplicar coluna por 2 
	mov bl,2
	mul bl
	
	mov bx, ax  ; ponto de inicio da copia o resultado da multiplicacao em bx
	mov si, bx 
	add si,40 ; ponto de destino da copia 
	
	ciclo: mov ax, es:[bx]
	mov dx, es:[bx+2]
	mov es:[si],ax
	mov es:[si+2],dx
	mov bx,160
	add si,160
	loop ciclo
	
	loop ciclo
	
	
	;extra limpar ecra 
	; ideia -> carater a preto em loop no ecra todo e "limpa" assim
	
	
	
	mov ah, 4CH
	int 21B
main endp
cseg ends

end main