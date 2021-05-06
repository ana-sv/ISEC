% ODE45_1ORDEM - Funcao do Matlab 
%
%INPUT:
%   f - função do 2º membro da equação diferencial
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de iterações do método
%   y0 - condição inicial t=a -> y=y0
%
%OUTPUT: 
%   y - vector das aproximações discretas da solução exacta
%
%   13/04/2020 | Ana Videira | a21250074@isec.pt

function y = ODE45_1ORD(f,a,b,n,y0)
    h = (b-a)/n;
    t = a:h:b;
    [t,y]= ode45(f,t,y0);
    y=y';
end