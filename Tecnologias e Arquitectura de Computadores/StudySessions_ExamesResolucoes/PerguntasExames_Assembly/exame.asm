; Pergunta 7 - Exame TAC Época Normal 2020
; Resolução Ana Videira - 2015012218


;Construa um programa em Assembly que calcule e armazene na 
;variável NUM, o número médio de letras das duas primeiras 
;palavras de uma string. Assuma que a string começa com uma
;palavra, que existe apenas um espaço entre palavras e que termina 
;com o valor 0 (zero). Deve apresentar o resultado sob a forma de 
;um valor inteiro, descartando a parte fraccionária.

;Exemplo:
;TEXTO = ‘Instituto Superior de Engenharia de Coimbra’
;NUM = 8





.8086
.model	small
.stack	2048

dados	segment para	'data'
	texto	db	'Instituto Superior de Engenharia de Coimbra',0  
	num 	db	0
	
dados	ends


codigo	segment para 'code'
	main	proc
	assume cs:codigo, ds:dados
	
		mov	ax,dados
		mov	ds,ax

		xor	si,si				
ciclo:	mov	ah, texto[si]     
		
		
        inc num		
		
		inc	si					
		cmp	ah,0			
        jne ciclo			
		
		
        mov     ah,4Ch   
		int     21h      

	main	endp
codigo	ends
end	main
