%script teste da PA
clear
clc

a_1=input('Introduza o 1� elemento da PA: ');
r=input('Introduza a raz�o da PA: ');
n=input('Introduza o n� de elementos  da PA: ');

disp('vers�o 1');
tic    %tic toc - tempo de computa��o
a=geraPAv1(a_1,r,n);
toc

disp('vers�o 1 melhorada');
tic    
b=geraPAv1melhorada(a_1,r,n);
toc


disp('vers�o 2');
tic    
a=geraPAv1(a_1,r,n);
toc

disp('vers�o 3');
tic    
a=geraPAv1(a_1,r,n);
toc
