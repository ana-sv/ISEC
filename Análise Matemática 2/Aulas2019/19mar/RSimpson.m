
%REGRA DE SIMPSON
%   
%FUNCTION: 
%   RSimpson
%
%INPUT:
%   f - função integrante 
%   a - limite inferior 
%   b - limite superior 
%   n - numero de iteracoes 
%   
%OUTPUT: 
%   T - Resultado da Regra de Simpson
%
%   19/02/2019 - AnaVideira .: anarita.svideira@gmail.com



function out_S=RSimpson(f,a,b,n)
h = (b-a)/n;
x = a;
s = 0;
for i=1:1:n-1
    x = x + h; 
    if mode(i,2) == 0  %% se i e' par
        s = s + 2*f(x);
    else 
        s = s + 4*f(x);
    end
end
out_S = h/3*(f(a)+s+f(b));
