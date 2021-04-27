.8086
.model small
.stack 2048

dseg	segment para public 'data'
		string	db	"Teste prático de T.I",0
		Car		db	32	; Guarda um caracter do Ecran 
		Cor		db	7	; Guarda os atributos de cor do caracter
		
		POSy	db	5	; a linha pode ir de [1 .. 25]
		POSx	db	10	; POSx pode ir [1..80]	
		PROXy	db  5
		PROXx	db 	10
		POSya	db	5	; Posição anterior de y
		POSxa	db	10	; Posição anterior de x
		
		guardaCar 		db ?
		handle			dw ?
		handle_conf 	dw ?
		car_conf		db ?
		guardaCarConf	dw ?
								   
		menu 	db '--------------- Menu ----------------',13,10
				db ' 		1- Jogar						 ',13,10
				db ' 		2- Configuracao do Labirinto	 ',13,10
				db ' 		3- Carregar Labirinto			 ',13,10
				db ' 		4- Sair 						 ',13,10
				db '	  -------------------------------------$',13,10
				
		fimlabirinto db "						Parabens! Completaste o labirinto$"
		legendaconf db "-----	1 - Parede ;	2 - Caminho ; 	esc - Guardar -----$"
				
		nomef	db 	"Maze.txt", 0
		nomefconf db "MazeConf.txt", 0
		
dseg	ends

cseg	segment para public 'code'
assume		cs:cseg, ds:dseg

;############## POSICAO SEGUINTE #######################################
prox_xy macro	PROXx, PROXY
		mov 	ah,02h
		mov		bh,0		; numero da página
		mov		dl,PROXx
		mov		dh,PROXy
		int		10h
		
		mov 	ah, 08h
		mov 	bh, 0
		int 	10h
		mov 	Car, al 	; guarda o caracter em al
endm

;############### POSICAO ATUAL ########################################
goto_xy	macro		POSx,POSy
		mov		ah,02h
		mov		bh,0		; numero da página
		mov		dl,POSx
		mov		dh,POSy
		int		10h
endm

;################ APAGA ECRA ##########################################
apaga_ecran	proc
		xor		bx,bx
		mov		cx,25*80
		
apaga:			mov	byte ptr es:[bx],' '
		mov		byte ptr es:[bx+1],7
		inc		bx
		inc 	bx
		loop	apaga
		ret
apaga_ecran	endp


;################## LER TECLA ###########################################
LE_TECLA	PROC
		mov		ah,08h
		int		21h
		mov		ah,0
		cmp		al,0
		jne		SAI_TECLA
		mov		ah, 08h
		int		21h
		mov		ah,1
SAI_TECLA:	RET
LE_TECLA	endp

;################## MAIN ###############################################
Main  proc
		mov		ax, dseg
		mov		ds,ax
		mov		ax,0B800h
		mov		es,ax
		xor 	si, si
	
		goto_xy	POSx,POSy	; Vai para nova posição
		mov 	ah, 08h		; Guarda o Caracter que está na posição do Cursor
		mov		bh,0		; numero da página
		int		10h			
		mov		Car, al		; Guarda o Caracter que está na posição do Cursor
		mov		Cor, ah		; Guarda a cor que está na posição do Cursor	

INICIO:
		call 	apaga_ecran
		mov 	POSy, 5
		mov 	POSx, 10
		goto_xy	POSx,POSy
		
		mov 	ah, 09h
		lea		dx, menu
		int 	21h
		mov		ah, 00h
		int 	16h
		goto_xy	POSx, POSy
		
		cmp 	al, 49 		; 1 do menu
		je 		ABRE_LABIRINTO
		cmp 	al, 50		; 2 do menu
		je 		CONF_INICIO
		cmp		al, 51		; 3 do menu 
		je 		ABRE_PERSONALIZADO
		cmp 	al, 52		; 4 do menu
		je 		FIM

;################### ABRE LABIRINTO NORMAL ##############################
ABRE_LABIRINTO:
		mov		ax, 0b800h
		mov 	es, ax
		xor 	si, si
		
		mov 	ah, 3Dh		; Abre o ficheiro
		mov 	cx, 0 		; Aberto para leitura e escrita
		lea 	dx, nomef
		int 	21h
		mov 	handle, ax
		
LER_FICHEIRO:
		mov 	ah, 3fh		; Indica o inicio da leitura
		mov 	bx, handle	; bx deve contar o handle do ficheiro ja aberto
		mov 	cx, 1		; Numero de bytes a ler
		lea 	dx, guardaCar	; Define para que local da memoria se vai ler (guardaCar)
		int 	21h			; Faz a leitura
		cmp 	ax, 0 		; EOF?
		je 		FIM_FICHEIRO	; Se EOF -> fecha o ficheiro
		mov 	ah, 02h		; Coloca o caracter no ecra
		mov 	dl, guardaCar	; Caracter a enviar para o ecra
		int 	21h			; Imprime no ecra
		jmp		LER_FICHEIRO	; Continua a ler o ficheiro 
		
FIM_FICHEIRO:
		mov 	ah, 3eh
		mov 	bx, handle
		int 	21h
		jmp 	CICLO
		
;################### ABRE LABIRINTO DO UTILIZADOR #######################
ABRE_PERSONALIZADO:
		mov 	ax, 0b800h
		mov 	es, ax
		xor 	si, si
		
		mov 	ah, 3Dh		; Abertura do ficheiro 
		mov 	cx, 0		; Ficheiro aberto para leitura e escrita
		lea 	dx, nomefconf
		int 	21h
		mov 	handle_conf, ax
		
LER_FICHEIRO_P:
		mov 	ah, 3fh		; Indica o inicio da leitura
		mov 	bx, handle_conf	; bx deve contar o handle do ficheiro ja aberto
		mov 	cx, 1		; Numero de bytes a ler
		lea 	dx, guardaCar	; Define para que local da memoria se vai ler (guardaCar)
		int 	21h			; Faz a leitura
		cmp 	ax, 0 		; EOF?
		je 		FIM_FICHEIRO_P	; Se EOF -> fecha o ficheiro
		mov 	ah, 02h		; Coloca o caracter no ecra
		mov 	dl, guardaCar	; Caracter a enviar para o ecra
		int 	21h			; Imprime no ecra
		jmp		LER_FICHEIRO_P	; Continua a ler o ficheiro

FIM_FICHEIRO_P:
		mov 	ah, 3eh
		mov 	bx, handle_conf
		int 	21h
		jmp 	CICLO
		
;################### JOGO ###############################################
CICLO:	goto_xy	POSxa,POSya	; Vai para a posição anterior do cursor
		mov		ah, 02h
		mov		dl, Car		; Repoe Caracter guardado 
		int		21H		
		
		goto_xy	POSx,POSy	; Vai para nova posição
		mov 	ah, 08h
		mov		bh,0		; numero da página
		int		10h		
		mov		Car, al		; Guarda o Caracter que está na posição do Cursor
		mov		Cor, ah		; Guarda a cor que está na posição do Cursor
		
		goto_xy	78,0		; Mostra o caractr que estava na posição do AVATAR
		mov		ah, 02h		; IMPRIME caracter da posição no canto
		mov		dl, Car	
		int		21H			
	
		goto_xy	POSx,POSy	; Vai para posição do cursor
IMPRIME:	
		mov		ah, 02h
		mov		dl, 190	; Coloca AVATAR
		int		21H	
		goto_xy	POSx,POSy	; Vai para posição do cursor
		
		mov		al, POSx	; Guarda a posição do cursor
		mov		POSxa, al
		mov		al, POSy	; Guarda a posição do cursor
		mov 	POSya, al
		
		mov 	al, POSx
		mov 	PROXx, al
		mov 	al, POSy
		mov 	PROXy, al
		
LER_SETA:	
		call	LE_TECLA
		cmp		ah, 1 
		je		CIMA
		CMP 	AL, 27		; Escape
		JE		INICIO		; volta ao menu
		jmp		LER_SETA
		
CIMA:	
		cmp		al,48h
		jne		BAIXO
		dec     PROXy
		prox_xy PROXx, PROXy
		cmp		al, 70		; Caracter final
		je		CIMA_FIM
		cmp 	al, 73		; Caracter inicial
		je		CIMA_INICIO
		cmp     al, 20h    	; Espaço
		jne     CICLO 
		dec		POSy		;Cima
		jmp		CICLO
CIMA_INICIO:
		dec		POSy
		jmp 	CICLO
CIMA_FIM:
		mov 	ah, 09h
		lea 	dx, fimlabirinto
		int 	21h
		jmp 	FIM
			
BAIXO:	
		cmp		al,50h
		jne		ESQUERDA
		inc     PROXy
		prox_xy PROXx, PROXy
		cmp		al, 70		; Caracter final
		je		BAIXO_FIM
		cmp		al, 73		; Caracter inicial
		je 		BAIXO_INICIO
		cmp     car, 20h	; Espaço
		jne     CICLO 
		inc 	POSy		; Baixo
		jmp		CICLO
BAIXO_INICIO:
		inc 	POSy
		jmp 	CICLO
BAIXO_FIM:
		mov 	ah, 09h
		lea 	dx, fimlabirinto
		int 	21h
		jmp 	FIM

ESQUERDA:
		cmp		al,4Bh
		jne		DIREITA
		dec     PROXx
		prox_xy PROXx, PROXy
		cmp		al, 70		; Caracter final
		je		ESQUERDA_FIM
		cmp 	al, 73		; Caracter inicial
		je 		ESQUERDA_INICIO
		cmp     al, 20h		; Espaço
		jne     CICLO 
		dec		POSx		;Esquerda
		jmp		CICLO
ESQUERDA_INICIO:
		dec 	POSx
		jmp 	CICLO
ESQUERDA_FIM:
		mov 	ah, 09h
		lea 	dx, fimlabirinto
		int 	21h
		jmp 	FIM

DIREITA:
		cmp		al,4Dh
		jne		LER_SETA
		inc     PROXx
		prox_xy PROXx, PROXy
		cmp		al, 70		; Caracter final
		je		DIREITA_FIM
		cmp 	al,73		; Caracter inicial
		je 		DIREITA_INICIO
		cmp     al, 20h		; Espaço
		jne     CICLO
		inc		POSx		;Direita
		jmp		CICLO
DIREITA_INICIO:
		inc		POSx
		jmp 	CICLO
DIREITA_FIM:
		mov 	ah, 09h
		lea 	dx, fimlabirinto
		int 	21h
		jmp 	FIM
		
;########### CRIAÇAO DO LABIRINTO ########################################		
CONF_INICIO:
		call	apaga_ecran
	
		;Obtem a posicao
		dec 	POSy
		dec 	POSx
	
		mov 	ah, 3Ch		; Criaçao do ficheiro
		mov 	cx, 0		; Ficheiro criado para leitura e escrita
		lea 	dx, nomefconf
		int 	21h
		mov 	handle_conf, ax
		
		; Coloca a legenda no topo do ecra
		mov 	POSx, 1
		mov 	POSy, 1
		goto_xy POSx, POSy
		mov 	ah, 09h
		lea 	dx, legendaconf
		int 	21h
		
		; Coloca o cursor mais abaixo para se fazer o labirinto
		mov 	POSx, 1
		mov 	POSy, 3
		goto_xy POSx, POSy

CONF_CICLO:	
		goto_xy	POSx, POSy

CONF_IMPRIME:	
		mov		ah, 02h
		mov		dl, car_conf
		int		21H			
		goto_xy	POSx, POSy
		
		call 	LE_TECLA
		cmp		ah, 1
		je		CONF_CIMA
		CMP 	AL, 27		; ESCAPE
		JE		PAUSA			
		
UM:		CMP 	AL, 49		; Tecla 1
		JNE		DOIS
		mov		car_conf, 219		;Caracter CHEIO
		jmp		CONF_CICLO		
	
DOIS:	CMP 	AL, 50		; Tecla 2
		JNE		NOVE
		mov		car_conf, 32		;Espaço
		jmp		CONF_CICLO			

		
NOVE:	jmp		CONF_CICLO
	
CONF_CIMA:	
		cmp 	al,48h
		jne		CONF_BAIXO
		dec		POSy			; Cima
		jmp		CONF_CICLO

CONF_BAIXO:	
		cmp		al,50h
		jne		CONF_ESQUERDA
		inc 	POSy			; Baixo
		jmp		CONF_CICLO

CONF_ESQUERDA:
		cmp		al,4Bh
		jne		CONF_DIREITA
		dec		POSx			; Esquerda
		jmp		CONF_CICLO

CONF_DIREITA:
		cmp		al,4Dh
		jne		CICLO 
		inc		POSx			;Direita
		jmp		CONF_CICLO
		
PAUSA:
		mov 	ax, 0b800h
		mov 	es, ax
		xor 	si, si
		
CONF_GUARDAR:
		mov 	al, es:[si]
		mov		ah, es:[si+1]
		mov 	guardaCarConf, ax
		mov 	ah, 40h
		mov 	cx, 2
		lea		dx, guardaCarConf
		mov 	bx, handle_conf
		int 	21h
		add		si, 2
		cmp		si, 3520  		; numero de linhas e colunas a guardar
		jne		CONF_GUARDAR
		mov		ah, 3Eh     	; fecho do ficheiro
		mov 	bx, handle_conf
		int 	21h
		jmp 	INICIO
		
FIM:	
		mov		ah,4CH
		int		21H
		
Main	endp
Cseg	ends
end	Main


		
