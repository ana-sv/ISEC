% Nome: Ana Rita Santos Videira
% Nºaluno: 21250074
% P8_data: 12 de Abril de 2018

% Function: RTrapezios
% Input parameters: f, a, b e n
% Output parameter: T

function T = RTrapezios(f,a,b,n)
h = (b-a)/n;
x = a;
s = 0;
for i=1:1:n-1
    x = x + h;
    s = s + f(x);
end
T = h/2*f(a)+ 2*s + f(b);


