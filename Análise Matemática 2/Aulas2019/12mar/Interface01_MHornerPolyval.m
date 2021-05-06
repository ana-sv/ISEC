%Interface01 para testar o MHorner e o polyval do Matlab
%   12/03/15 - ArménioCorreia .: armenioc@isec.pt 

clc
clear

disp('-------------------------POLINÓMIOS-------------------------------');
disp('----Método de Horner para a fórmula dos parênteis encaixados------');
disp('----Polyval do Matlab---------------------------------------------');
disp('                                                                  ');
a=[0,0,1];
x=-1:0.1:1;
y=MHorner(a,x);

a=a(end:-1:1);
yy=polyval(a,x);

disp('Tabela com resultados');
tabela=[x.',y.',yy.'];
fprintf('\n\t x\t\t y_Horner\t y_polyval\n')
disp(tabela)

plot(x,y,'ob')
hold on
plot(x,yy,'r')
hold off
grid on
legend('MHorner','PolyVal')
shg


