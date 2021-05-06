%MHorner Método de Horner dos parêntesis encaixados 
%   P = MHorner(a,x)
%   Pn(x)=((((a_{n}*x+a_{n-1})*x+a_{n-2})*x+...a_{1})*x+a_{0}
%INPUT:
%   a - vector com os coeficientes do polinómio [a0,a1,...,an]
%   x - valor(es) onde se pretende calcular o polinómio
%OUTPUT: 
%   P - valor do polinómio em x
%
%   12/03/15 - ArménioCorreia .: armenioc@isec.pt 
function P=MHorner(a,x)
n=length(a);
P=a(n);
for i=n-1:-1:1
    P=P.*x+a(i);
end