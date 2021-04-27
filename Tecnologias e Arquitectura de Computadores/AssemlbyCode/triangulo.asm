; Prog que desenha um triangulo retangulo

.8086
.model small
.stack 2048


DADOS segment para 'data'
    col     db 3
    line    db 4
    simbolo db '*'
    altura  db 6
DADOS  ENDS

cseg	segment para public 'code'
	assume  cs:cseg, ds:DADOS

Main  proc
	mov   ax,0b800h
	mov   es,ax
    mov   ax, DADOS
    mov   ds, ax
    xor si, si
    xor bh, bh

   


    ; POS initial 
    mov al, col
    mov bl, 2
    MUL bl  ; al * bl = ax (ah : al)
    mov si, ax

    ; Line
    mov bl, 160
    mov al, line 
    MUL bl  ; al * bl = ax (ah : al)
    ADD si, ax ; si + ax = si

    ; CARATER
    mov	al, 0Fh
	mov	ah, simbolo

    mov di, si

     ; LOOP VARS - TO CICLE
    mov ch, 0
ciclo:
    ; bh = 0 
    xor bh, bh
    mov si, di
    ciclo2:
        mov es:[si], ah 
        mov es:[si+1], al

        ; prox col
        ADD si, 2
        cmp bh, ch  
        inc bh 
        jbe ciclo2
       
    ADD di, 160
    inc ch
    cmp ch, altura
    jne ciclo

	mov     ah,4CH
	int     21H
main	endp

cseg    ends
end     main