.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	var1b           db	0ADH
	string          db	'PATA',0
	var1w           dw	173
	var1dw          dd	10101101b
	var2w           word	-28
	var3w           sword	-28
	var2b           byte	-28
	var3b           sbyte	-28
	var2dw          dword	-28
	var3dw         	sdword	-28
	CharArray	dw      3 dup (0CCh)
	Square         	byte	0, 1, 4,9,16 
	ThreeD          db      2 dup (4 dup (2 dup (052h)))
	TwoD            db      2 dup (2 dup (12h))
	IntArray        word    4 dup (0BCh)
	var1f		fword	65535
	var1q		qword   65534
	var1t		tbyte	65533
	X               REAL4	4.0
	Y               REAL8   2.75e-2
	Z               REAL10  4.875
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	mov     ax, dseg
	mov     ds, ax
	mov     al,0001h
	mov     var1b,al
	mov     al,6
	mov     var2b,al
	mov     al,7
	mov     var3b,al
	mov     ax, var3w
	mov     word ptr CharArray[si],ax
fim:	mov     ah,4ch
	int     21h
main	endp
cseg    ends
end     Main