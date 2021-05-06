% N_EulerM - Método de Euler Melhorado

%   y = N_EulerM(f,a,b,n,y0) Método numérico para a resolução de um PVI
%   y'= f(t,y) com t=[a, b] e y(a)=y0 condição inicial  

%INPUT:
%   f - função do 2.º membro da Equação Diferencial
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de subintervalos ou iterações do método
%   y0 - condição inicial t=a -> y=y0

%OUTPUT: 
%   y - vector das aproximações discretas da solução exacta
%   y(i+1) = y(i)+h*f(t(i),y(i)) , i =0,1,...,n-2

% 27/04/18 - Ana Videira .: a21250074@isec.pt




function y = N_EulerM(f,a,b,n,y0)
h    = (b-a)/n;
t(1) = a;
y(1) = y0;

for i=y0:h:10.1
    y(i+1)=y(i)+(y(i)+y(i+1))*(h/2);
    t(i+1)=t(i)+(h);
end



