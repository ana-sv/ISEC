%  Aula 4 - 22 de Março

% Pesudo-código para o método de Horner:
%
% Ler a,x               sendo a:vetor/polinomio , x:valor a calcular
% P <- a(n)
% Para i = n-1:-1:1
%   P=P*x+a(i)
% Fi
%
%
% Representação Vectorial de um Polinómio:
%
% P(x)=x^3+2x^2+x+5 -> P[1 2 1 5]
%                      tamanho de P-1= grau
% P(x)=x^3-1 -> P=[1 0 0 -1]
%
%
% Método de Horner ou Parâmetros Encaixados:
%
% P2(x)=2x^2+5x+1 -->adições=2
%                 -->multiplicações=3
%
% P3(x)=3x^3+2x^2+5x+1 -->adições=3
%                      -->multiplicações=6
%
% Alternativa:
% P2(x)=2x^2+5x+1=(2x+5)x+1 -->adiçõe=2
%                           -->multiplicações=2
%
% P3(x)=3x^3+2x^2+5x+1=(3x^2+2x+5)x+1=((3x+2)x+5)x+1 -->adições=3
%                                                    -->multiplicações=3