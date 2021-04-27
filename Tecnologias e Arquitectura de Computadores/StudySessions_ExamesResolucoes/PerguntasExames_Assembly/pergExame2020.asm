; Pergunta exame especial 2020
;
;Contrua um programa em Assembly que localize, numa string, uma sequência 
; de caracteres e crie uma nova string, substituindo essa sequência por 
; outra. Caso não encontre a cadeia de caracteres, a string final deverá 
; ser igual à original. Considere que a string termina com o valor 0 
; (zero) e que, caso exista a cadeia de carateres, esta apenas existe umavez.
;
; Exemplo:
;
; STROriginal = ‘TaaTaCCCCCCCCC’      
; StrSUBSTITUIR = ‘TaC,ISEC’
; STRFinal = ‘TaaISECCCCCCCCC’



.8086
.model small
.stack 2048

dseg segment para public 'data'
	STROriginal		db	‘TaaTaCCCCCCCCC’,0
	StrSUBSTITUIR	db	‘TaC,ISEC’
	STRFinal		db	?
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov si, 0
	 mov di, 0 
	 mov ch, 0

ciclo:
	 mov al, STROriginal[si]
	 cmp al, 0
	 je fim
	 mov bl, StrSUBSTITUIR[di]
	 cmp al, bl
	 je conta

conta:
	inc ch
	cmp ch, 3
	je substitui
	jne incPosicao
	
substitui:
	mov ch, 0 
	inc di 
	sub si,3
	jmp cicloSubstituir 
	
cicloSubstituir:
	mov al, StrSUBSTITUIR[di]
	mov STROriginal[si], al 
	inc di
	inc si 
	cmp si, 3
	jne cicloSubstituir
	je ciclo

   
incPosicao:
	inc si
	inc di 
	jmp ciclo
	 
fim:  
     mov al, 0
     mov ah, 4ch
     int 21h
	 
main endp
cseg ends

end main