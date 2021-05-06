%MHorner M�todo de Horner dos par�ntesis encaixados 
%   P = MHorner(a,x)
%   Pn(x)=((((a_{n}*x+a_{n-1})*x+a_{n-2})*x+...a_{1})*x+a_{0}
%INPUT:
%   a - vector com os coeficientes do polin�mio [a0,a1,...,an]
%   x - valor(es) onde se pretende calcular o polin�mio
%OUTPUT: 
%   P - valor do polin�mio em x
%
%   12/03/15 - Arm�nioCorreia .: armenioc@isec.pt 
function P=MHorner(a,x)
n=length(a);
P=a(n);
for i=n-1:-1:1
    P=P.*x+a(i);
end