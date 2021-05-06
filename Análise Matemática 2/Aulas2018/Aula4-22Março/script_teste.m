clc
clear

disp('Comparação com o Polyval')
a=[-1 0 0 1]; % coeficientes do polinomio por ordem crescente
x=2:0.325:4; %vetor dos valore a calcular no polinomio

y=mHorner(a,x);
aa=a(end:-1:1);
yy=polyval(aa,x);


tabela=[x' y' yy'];
fprintf('\n\t x\t\t yHorner\t\t yPolyval\n')
disp(tabela)