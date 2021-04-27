;Assembly Notes


; INTEIROS
;Sem Sinal (binário puro): DB / BYTE  (1  byte  = 0...255)
;                          DW / WORD  (2  bytes = 0...65535)
;                          DD / DWORD (4  bytes = 0...???)
;                               FWORD (6  bytes = 0...???)
;                               QWORD (8  bytes = 0...???)
;                               TBYTE (10 bytes = 0...???)
;
;Com Sinal (complementos 2): SBYTE  (1  byte  = -128...+127)
;                            SWORD  (2  bytes = -32768...32767)
;                            SDWORD (4  bytes = ???...???)


;REAIS
;Reais (IEEE754): REAL4   ( 4 Bytes -> IEEE754 Simples)
;                 REAL8   ( 8 Bytes -> IEEE754 Dupla)
;                 REAL10  (10 Bytes -> IEEE754 Expandida)





;INSTRUCAO LOOP 

	
	 xor al,al
	 mov cx,2
	 ciclo: add al, 1   ;loop ciclo » decrementa cx e verififca se cx-0. se sim o ciclo termina 
						; o ciclo é feito tantas vezes quanto o valor em cx 
						; o ciclo é feito sempre pelo menos 1 vez , tem funcionamento semelhante a um do-while em C 


;MEMÓRIA DE VIDEO

; array bi.dimensional de words -> cada word corresponde a um caracter no ecra
; byte menos significativo - caracter 
; byte mais significativo - formatação
; tamanho: 25 * 80 

; ir para coluna X -> X*2
; ir para linha Y -> Y*160
; ir para coluna X e linha Y ->  X*160 + Y*2

; add di, 2 -> escreve na horizontal normalmente 
; sub di, 2 -> escreve na horizonal mas ao contrario
; add di,160 -> escreve na vertical, a cada iteração mudamos de linha 
; add di,162 -> escreve na diagonal, ou seja 160+2 , a cada iteracao muda de linha e avança duas colunas 
	
	
; B800:0000 -> extra segment (es)
; array monocromático -> B000h:0000h
; array de cores -> B800h:000h

; assim para memoria de video funcionar é necessesáro

	mov ah, 0B800h
	mov es, ax 
	

	
	
	