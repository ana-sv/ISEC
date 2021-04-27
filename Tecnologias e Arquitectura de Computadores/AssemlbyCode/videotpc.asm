;Imprime a string na posição indicada pelas variaveis linha e coluna

.8086
.model small
.stack 2048

dseg segment para public 'data'
     string db 'Trabalho para casa'
	 linha  db 5
	 coluna db 10
	 
	 ; para colocar no centro do ecra seria
	 ; linha db 12
	 ; coluna db 40
	 
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg 
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov ax, 0B800h   ;para memoria de video, sem isto ela nao funciona
	 mov es,ax
	 
	 ;obter a posição	 
	 mov bl,160
	 mov al,linha	; al fica com o valor de linha 
	 mul bl			; ax<- bl*al
	 mov dx,ax		; dx guardou o inicio da linha onde comeca a escrever
	 
	 mov bl,2
	 mov al, coluna
	 mul bl  		; resultado ficou novamente em ax 
	 add dx,ax  	
	 mov bx,dx 
	 
	 mov ah,0Fh
	 xor si,si
ciclo:
	 mov al,string[si]
	 cmp al,0
	 je fim 
	 mov 	byte ptr es:[bx],al		; escrever na memoria de video byte a byte
	 mov 	byte ptr es:[bx+1],ah
	 inc si
	 add bx,2 		;sub di,2 caso fosse para escrever a string ao contrario
	 jmp ciclo 
	 
fim:
     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main


