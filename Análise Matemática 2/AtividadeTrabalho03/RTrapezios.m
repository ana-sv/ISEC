%RTrapezios Gerar uma aproximação geométrica a um grafico de uma função
% 06/6/2020 - Ana Videira

function T=RTrapezios(f,a,b,n)

h=(b-a)/n;
x=a;
s=0;

for i=1:n-1
    x=x+h;
    s=s+f(x);
end

T= h/2*(f(a)+2*s+f(b));