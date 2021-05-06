%=================================================================
%   horner
%   Metodo de Horner ou dos parentesis encaixados
%	
%   Entradas: Vector que armazena por ordem decrescente os coef
%             do polinomio e pto onde se pretende calcular o
%             polinomio
%   Saidas  : Valor do polinomio em x
%
%   Realizaçao: Armenio Correia & Joao Alves	
%   Data      : maio2003
%=================================================================


function p=horner(a,x)
    n=length(a);
    p=a(n);

    for i=n-1:-1:1,
        p=p.*x+a(i);
    end


