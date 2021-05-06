function P=mHorner(a,x)
%inputs:
% a - vetor  dos coeficientes do polinomio por ordem crescente
% x- valor/vetor a calcular no polinomio 
%output:
% p - valo/vetor das imagens de x segundo o polinimo;

n=length(a);
P=a(end);

for i=n-1:-1:1
    P=P.*x+a(i);
end 