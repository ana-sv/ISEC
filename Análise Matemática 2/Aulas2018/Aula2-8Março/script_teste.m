%script teste da PA
clear
clc

a_1=input('Introduza o 1ª elemento da PA: ');
r=input('Introduza a razão da PA: ');
n=input('Introduza o nº de elementos  da PA: ');

disp('versão 1');
tic    %tic toc - tempo de computação
a=geraPAv1(a_1,r,n);
toc

disp('versão 1 melhorada');
tic    
b=geraPAv1melhorada(a_1,r,n);
toc


disp('versão 2');
tic    
a=geraPAv1(a_1,r,n);
toc

disp('versão 3');
tic    
a=geraPAv1(a_1,r,n);
toc
