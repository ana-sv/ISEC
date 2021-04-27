; Faça um programa que construa um novo vector, a partir de um vector já
; existente, cujos valores dos elementos sejam o dobro dos valores originais. O
; número de elementos do vector é dado pela constante NumElem. O endereço do
; vector já existente é OldVector, e o do vector a criar é NewVector.

;????????????????????????????????????????????????????

.8086
.model small
.stack 2048

dseg segment para public 'data'
     OldVector byte 20,40,60,80,100
	 NumElem byte 5
	 NewVector word 5 dup(?)
dseg ends

cseg segment para public 'code'
     assume cs:cseg, ds:dseg
main proc
     mov ax, dseg
     mov ds, ax
	 
	 mov si, 0
	 mov di,0
	
ciclo:
	 mov al, OldVector[si]
	 mov bl,3
	 mul bl
	 mov NewVector[di], ax
	 inc si
	 add di,2
	 loop ciclo

     mov al, 0
     mov ah, 4ch
     int 21h
main endp
cseg ends

end main