; Construa um programa em Assembly que obtenha as letras que surgem um n+umero par de vezes, tendo em 

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