clc
clear
a_1=1;
r=1;
n=100;

disp('-----Vers�o 01 da Progress�o Aritm�tica-----')
a=gerarPAritmetica_v1(a_1,r,n);
disp(a)

disp('-----Vers�o 02 da Progress�o Aritm�tica-----')
b=gerarPAritmetica_v2(a_1,r,n);
disp(b)

disp('-----Vers�o 03 da Progress�o Aritm�tica-----')
c=gerarPAritmetica_v3(a_1,r,n)
disp(c)

disp('-----Vers�o 04 da Progress�o Aritm�tica-----')
d=gerarPAritmetica_v4(a_1,r,n)
disp(d)

S=SomaPA(a;
fprintf(''\nA Soma da PA   )