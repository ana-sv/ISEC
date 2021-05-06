% NDerivacaoDFP_3pontos Derivação Numérica - fórmula das diferenças progressivas com 3 pontos
% 06/6/2020 - Ana Videira

function [x,y,dydx]=NDerivacaoDFP3pontos(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end
dydx=zeros(1,n);
for i=1:n-2
    dydx(i)=(-3*y(i)+4*y(i+1)-y(i+2))/(2*h);
end
dydx(n-1)=(-3*y(n-2)+4*y(n-1)-y(n))/(2*h);
dydx(n)=(-3*y(n-2)+4*y(n-1)-y(n))/(2*h);
