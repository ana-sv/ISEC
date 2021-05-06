% NDerivacaoDFR Derivação Numérica - fórmula das diferenças centradas
% 06/6/2020 - Ana Videira

function [x,y,dydx]=NDerivacaoDFC(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end
dydx=zeros(1,n);
for i=2:n-1
    dydx(i)=(y(i+1)-y(i-1))/2*h;
end
dydx(1)=(y(3)-y(2))/2*h;