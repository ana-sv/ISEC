%RK2  M�todo de Runge-Kutta de ordem 2
% M�todo Num�rico para a resolu��o
% de um problema de valor inicial:
%               y = N_RK2(f,a,b,n,y0) 

%INPUT:
%   f - fun��o do 2� membro da equa��o diferencial
%   [a, b] - extremos do intervalo da vari�vel independente t
%   n - n�mero de itera��es do m�todo
%   y0 - condi��o inicial t=a -> y=y0

%OUTPUT: 
%   y - vector das aproxima��es discretas da solu��o exacta
%   y(i+1) = y(i)+(1/2)*(k1 + k2), i =0,1,...,n-1

% 27/04/18 - Ana Videira .: a21250074@isec.pt


function y = N_RK2(f,a,b,n,y0)

h = (b-a)/n;
t = a:h:b;
y(1) = y0;

for i=1:n
    
    k1 = h*f(t(i),y(i));
    k2 = h*f(t(i+1),y(i)+k1);
    y(i+1) = y(i)+0.5*(k1+k2);

end
