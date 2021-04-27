.8086
.model small
.stack 2048

cseg	segment para public 'code'
	assume  cs:cseg

Main  proc

	mov   ax,0b800h			; segmento da memoria de video 
	mov   es,ax				;

	mov	al,'*'			; caracter a ser apresentado no ecra
	mov	ah,00h 			; atributos do caracter 
	mov	bx,0			;
	mov	cx,25*80		; colocar em cx o numero de linhas x numero de colunas , neste caso, em todo o ecra
	; em cx porque o loop esta automaticamente associado ao cx assim utilizamos o ecra todo
	; o loop decrementa o cx a cada ciclo e ver se cx já chegou a zero.
	; o loop corre sempre pelo menos uma vez porque o teste é feito no fim 

ciclo:    
	mov	es:[bx],al			; responsavel escreve o *
	mov	es:[bx+1],ah		; responsavel pelo atributo, pela cor 
	inc	bx
	inc	bx
	inc	ah
	loop ciclo  			; loop vai executar em todo o ecra

	mov al,0
	mov ah,4CH
	int 21H

main	endp

cseg    ends
end     main



