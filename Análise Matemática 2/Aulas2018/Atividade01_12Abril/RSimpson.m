% Nome: Ana Rita Santos Videira
% Nºaluno: 21250074
% P8_data: 12 de Abril de 2018

% Function: RSimpson
% Input parameters: f, a, b e n
% Output parameter: out_S

function out_S = RSimpson(f,a,b,n)
h = (b-a)/n;
x = a;
s = 0;
for i=1:1:n-1
    if mode(i,2) == 0
        s = s + 2*f(x);
    else 
        s = s + 4*f(x);
    end
end
out_S = h/3*(f(a)+s+f(b));
    
        

    

