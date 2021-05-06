%NEulerM  Método de Euler Melhorado para ED/PVI.
%
%INPUT:
%   f - função do 2.º membro da Equação Diferencial a resolver
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de subintervalos ou iterações do método
%   y0 - condição inicial t=a -> y=y0
%OUTPUT: 
%   y - vector das soluções aproximações
%   y0 - condicao inicial -> y=y0
%
%   13/04/2020 | Ana Videira | a21250074@isec.pt


function y = NEulerM(f,a,b,n,y0)
    h =( b - a )/n;
    t=a:h:b;
    y=zeros(1,n+1);
    y(1)=y0;
for i=1:n
    y(i+1)=y(i)+h*f(t(i),y(i));
end