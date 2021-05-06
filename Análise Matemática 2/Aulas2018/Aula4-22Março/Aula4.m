%  Aula 4 - 22 de Mar�o

% Pesudo-c�digo para o m�todo de Horner:
%
% Ler a,x               sendo a:vetor/polinomio , x:valor a calcular
% P <- a(n)
% Para i = n-1:-1:1
%   P=P*x+a(i)
% Fi
%
%
% Representa��o Vectorial de um Polin�mio:
%
% P(x)=x^3+2x^2+x+5 -> P[1 2 1 5]
%                      tamanho de P-1= grau
% P(x)=x^3-1 -> P=[1 0 0 -1]
%
%
% M�todo de Horner ou Par�metros Encaixados:
%
% P2(x)=2x^2+5x+1 -->adi��es=2
%                 -->multiplica��es=3
%
% P3(x)=3x^3+2x^2+5x+1 -->adi��es=3
%                      -->multiplica��es=6
%
% Alternativa:
% P2(x)=2x^2+5x+1=(2x+5)x+1 -->adi��e=2
%                           -->multiplica��es=2
%
% P3(x)=3x^3+2x^2+5x+1=(3x^2+2x+5)x+1=((3x+2)x+5)x+1 -->adi��es=3
%                                                    -->multiplica��es=3