%NEulerM  M�todo de Euler Melhorado para ED/PVI.
%
%INPUT:
%   f - fun��o do 2.� membro da Equa��o Diferencial a resolver
%   [a, b] - extremos do intervalo da vari�vel independente t
%   n - n�mero de subintervalos ou itera��es do m�todo
%   y0 - condi��o inicial t=a -> y=y0
%OUTPUT: 
%   y - vector das solu��es aproxima��es
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