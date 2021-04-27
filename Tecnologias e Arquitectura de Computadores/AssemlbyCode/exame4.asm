; Pergunta 7 - Exame TAC Época Normal 2020

; Construa um programa em Assembly que calcule e armazene na variavel NUM,
; o numero medio de letras das duas primeiras palavras de uma string. 
; Assuma que a string comeca com uma palavra, que existe apenas um espaco
; entre palavras e que termina com o valor 0 (zero).
; Deve apresentar o resultado sob a forma de um valor inteiro,
; descartando a parte fracionaria. 

; Exemplo: 
; TEXTO = 'Instituto Superior de Engenharia de Coimbra"
; NUM = 8 

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

     ; CODIGO...

     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main