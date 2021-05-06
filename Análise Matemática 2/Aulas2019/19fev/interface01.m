clc
clear
a_1=1;
r=1;
n=100;

disp('-----Versão 01 da Progressão Aritmética-----')
a=gerarPAritmetica_v1(a_1,r,n);
disp(a)

disp('-----Versão 02 da Progressão Aritmética-----')
b=gerarPAritmetica_v2(a_1,r,n);
disp(b)

disp('-----Versão 03 da Progressão Aritmética-----')
c=gerarPAritmetica_v3(a_1,r,n)
disp(c)

disp('-----Versão 04 da Progressão Aritmética-----')
d=gerarPAritmetica_v4(a_1,r,n)
disp(d)

S=SomaPA(a;
fprintf(''\nA Soma da PA   )