% NDerivacaoDFP_3pontos Derivação Numérica - fórmula das diferenças regressivas com 3 pontos
% 06/6/2020 - Ana Videira

function [x,y,dydx]=NDerivacaoDFR3pontos(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end;
dydx=zeros(1,n);
for i=3:n
    dydx(i)=(y(i-2)-4*y(i-1)+3*y(i))/2*h;
end;
dydx(1)=(y(1)-4*y(2)+3*y(3))/2*h;
dydx(2)=(y(2)-4*y(3)+3*y(4))/2*h;