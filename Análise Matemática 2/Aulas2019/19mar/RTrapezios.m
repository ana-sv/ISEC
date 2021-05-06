
%REGRA DOS TRAPEZIOS
%   
%FUNCTION:
%   RTrapezios
%
%INPUT:
%   f - função integrante 
%   a - limite inferior 
%   b - limite superior 
%   n - numero de iteracoes 
%   
%OUTPUT: 
%   T - Resultado da Regra de Trapezios
%
%   19/02/2019 - AnaVideira .: anarita.svideira@gmail.com

function T=RTrapezios(f,a,b,n)
h=(b-a)/n;
x = a;
s = 0;
for i=1:1:n-1
    x = x + h;
    s = s + f(x);
end
T = h/2* (f(a)+ 2*s + f(b));
