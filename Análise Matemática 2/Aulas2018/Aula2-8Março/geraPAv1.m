%Aula 2 - 8 de Mar�o

% - declarar fun��es 
% - ciclos: for, while 
% - if , break
% - ivocar fun�oes na command window em em scripts


function a=geraPAv1(a_1,r,n)
%gera vetor a constituido por PA 1� elemento a_1, raz�o r e n

%inputs: 
% a_1 - 1� elmento da PA;
% r - raz�o/passo da PA;
% n - n� de elmentos pretendidos 

%output:
% a- vetor com os n elementos da PA.
% data: 8 de Mar�o de
% autores: Ana Videira 


a(1)=a_1;

for i=2:n
    a(i)=a(1)+(i-1)*r;
end 


