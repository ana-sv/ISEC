%RK2  Método de Runge-Kutta de ordem 2
% Método Numérico para a resolução
% de um problema de valor inicial:
%               y = N_RK2(f,a,b,n,y0) 

%INPUT:
%   f - função do 2º membro da equação diferencial
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de iterações do método
%   y0 - condição inicial t=a -> y=y0

%OUTPUT: 
%   y - vector das aproximações discretas da solução exacta
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
