%Interface02PVI para o m�todo de Euler
%
%CHAMADA DE FUN��ES:
% � NEuler
% � dsolve
%
%   03/03/2020 - Arm�nioCorreia .: armenioc@isec.pt 
%%
clc
clear

disp('----- M�todos Num�ricos para EDO/PVI ------ ');
disp(' ');
disp('----- Dados do PVI ------------------------ ');

while 1
    strF=input('f(t,y) = ', 's');
    f=@(t,y) eval(vectorize(strF));
    try
        syms t y;
        fTeste=f(t,y);
        break;
    catch me
        disp('ERRO! Introduza uma fun��o em t e y');
    end
end

a=str2num(input('a = ','s'));
while 1
    b=str2num(input('b = ', 's'));
    if (isscalar(b) && isreal(b) && b > a)
        break;
    else
        errordlg('Introduza um n�mero real b, com b > a',...
                 'ERRO','modal');
    end
end

n=str2num(input('n = ','s'));
y0=str2num(input('y0 = ','s'));
%%

yEuler=NEuler_v2(f,a,b,n,y0);
yRK2 =NRK2(f,a,b,n,y0);

sExata=dsolve(['Dy=', strF],...
              ['y(',num2str(a),')=',num2str(y0)]);
g=@(t) eval(vectorize(char(sExata)));
h=(b-a)/n;
t=a:h:b;
yExata=g(t);

erroEuler=abs(yExata-yEuler);
erroRK2=abs(yExata-yRK2);

tabela=[t.',yExata.', yEuler.',yRK2.', erroEuler.',erroRK2.'];
disp('----- Solu��o do PVI em modo tabela de valores ----')
disp(tabela)

input('Prima numa tecla para continuar')
disp('-----Solu��o em modo gr�fico----')
plot(t,yExata,'-bo')
hold on
plot(t,yEuler,'-r*')
plot(t,yRK2,'-g+')
hold off
grid on
legend('Exata','Euler','RK2')
shg;