; Faça um programa, em Assembly, que copie 2 linhas consecutivas 
; existentes no ecrã (modo texto, policromático 25x80) e apresente 
; as mesmas, 15 linhas abaixo. No segmento de dados está especificada
; a linha a partir da qual o deslocamento é efectuado.

; ?????????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     Linha db 3
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
	 
main proc
     mov ax, cseg
     mov ds, ax
	 
	 ;linha
	 mov bl,160
	 mov al,Linha
	 mul bl			
	 mov si,ax
	 
	 ;coluna ,  porque para 15 linhas abaixo, descemos na coluna
	 mov al,15
	 mul bl		
	 mov di,ax
	 
	 ; posicao , porque ir para coluna X e linha Y ->  X*160 + Y*2
	 add di,si

	 
ciclo: 
	mov ax,es:[si]
	mov es:[di+1],ax 
	add si,2
	add di,2
	loop ciclo
     
	 
     mov al, 0
     mov ah, 4CH
     int 21H
main endp
cseg ends

end main