clc
clear
a_1=1;
r=1;
n=4000;

tic
a=gerarPAritmetica_v1(a_1,r,n);
toc

tic
b=gerarPAritmetica_v2(a_1,r,n);
toc

tic
c=gerarPAritmetica_v3(a_1,r,n)
toc

tic
d=gerarPAritmetica_v4(a_1,r,n)
toc