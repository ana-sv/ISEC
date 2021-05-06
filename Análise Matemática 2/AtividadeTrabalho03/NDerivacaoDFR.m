% NDerivacaoDFR Derivação Numérica - fórmula das diferenças regressivas
% 06/6/2020 - Ana Videira

function [x,y,dydx]=NDerivacaoDFR(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end;
dydx=zeros(1,n);
for i=2:n
    dydx(i)=(y(i)-y(i-1))/h;
end;
dydx(1)=(y(2)-y(1))/h;