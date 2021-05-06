%Aula 2 - 8 de Março

% - declarar funções 
% - ciclos: for, while 
% - if , break
% - ivocar funçoes na command window em em scripts


function a=geraPAv1(a_1,r,n)
%gera vetor a constituido por PA 1º elemento a_1, razão r e n

%inputs: 
% a_1 - 1º elmento da PA;
% r - razão/passo da PA;
% n - nº de elmentos pretendidos 

%output:
% a- vetor com os n elementos da PA.
% data: 8 de Março de
% autores: Ana Videira 


a(1)=a_1;

for i=2:n
    a(i)=a(1)+(i-1)*r;
end 


