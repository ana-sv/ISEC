; Pergunta 12 - Exame TAC Época Recurso 2020

; Construa um programa em Aseembly que armazene no array TAM o tamanho,
; em letras, de cada uma das palavras da string TEXTO. O array termina 
; com o valor (zero) e tera , no maximo, 10 elementos. Deve tambem
; calcular e armazenar na variavel MEDIA, o numeor medio de letras das
; palatras da string (veja o exemplo apresentado). Assuma que a string
; comeca com uma palavra, que existe apenas um espaco entre as palatrase
; que termina com o valor 0 (zero). Deve declarar todas as variaveis 
; utilizadas.

; Exemplo: 
; TEXTO = 'Instituto Superiror Engenharia de Coimbra'
; TAM = 9,8,10,2,7,8
; MEDIA = 7 

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