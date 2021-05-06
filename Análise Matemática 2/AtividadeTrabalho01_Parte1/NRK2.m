%RK4  M�todo de Runge-Kutta de ordem 2
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

function y = NRK2(f, a, b, n, y0)
    h = (b - a) / n;
    t = a:h:b; 
    y = zeros(1, n+1);
    y(1) = y0;
    for i = 1 : n
        k1 = h * f(t(i), y(i));
        k2 = h * f(t(i+1), y(i)+k1);
        y(i+1) = y(i)+(k1+k2)/2;
    end
end