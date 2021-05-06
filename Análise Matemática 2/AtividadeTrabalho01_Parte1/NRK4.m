%RK4  M�todo de Runge-Kutta de ordem 4
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


function y = NRK4(f,a,b,n,y0)

h = (b-a)/n;
t = a:h:b;
y(1) = y0;

for i=1:n
    
    k1 = h*f(t(i),y(i));
    k2 = h*f(t(i) + (0.5*h),y(i)+(0.5*k1));
    k3 = h*f(t(i) + (0.5*h),y(i)+(0.5*k2));
    k4 = h*f(t(i) + h,y(i)+k3);
    y(i+1) = y(i)+((k1+(2*k2)+(2*k3)+k4)/6);

end