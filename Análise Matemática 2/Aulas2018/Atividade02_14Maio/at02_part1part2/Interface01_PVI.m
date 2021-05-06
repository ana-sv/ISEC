%Interface01 para o método de Euler
%
%CHAMADA DE FUNÇÕES:
% » N_euler
% » dsolve
%
%   18/03/13 - ArménioCorreia .: armenioc@isec.pt 

clc
clear

disp('----- Método de Euler para EDO ------ ');
disp(' ');
% 
% sExata = dsolve('Dy = y + exp(3*t)')
% sExataP = dsolve('Dy = y + exp(3*t)', 'y(1)=2')

strF = input('f(t,y) = ','s');
f = @(t,y) eval(vectorize(strF));

a  = str2num(input('a = ','s'));
b  = str2num(input('b = ','s'));
n  = str2num(input('n = ','s'));
y0 = str2num(input('y0 = ','s'));

yEuler = N_Euler(f,a,b,n,y0);

sExata = dsolve(['Dy=', strF],...
                ['y(',num2str(a),')=',num2str(y0)]);
t = a:(b-a)/n:b;
yExata = eval(char(sExata));
erroEuler = abs(yExata - yEuler);
tabela = [t.', yEuler.', yExata.', erroEuler.'];
disp(tabela)

plot(t,yEuler,'-r')
hold on
plot(t,yExata, 'b')
hold off
grid on
legend('Euler','Exacta')
shg;