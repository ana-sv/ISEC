% ODE45_1ORDEM - Funcao do Matlab 
%
%INPUT:
%   f - fun��o do 2� membro da equa��o diferencial
%   [a, b] - extremos do intervalo da vari�vel independente t
%   n - n�mero de itera��es do m�todo
%   y0 - condi��o inicial t=a -> y=y0
%
%OUTPUT: 
%   y - vector das aproxima��es discretas da solu��o exacta
%
%   13/04/2020 | Ana Videira | a21250074@isec.pt

function y = ODE45_1ORD(f,a,b,n,y0)
    h = (b-a)/n;
    t = a:h:b;
    [t,y]= ode45(f,t,y0);
    y=y';
end