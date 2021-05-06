% Interpola��o a duas dimens�es
% Exemplo da Entalpia=f(press�o,temperatura)
% z=interp2(x,y,z,xi,yi)
% 20/03/2015 Arm�nio Correia | armenioc@isec.pt

clc
clear
p=xlsread('Dados_Entalpia_interp2.xlsx','D6:G6');
t=xlsread('Dados_Entalpia_interp2.xlsx','C7:C11');
h=xlsread('Dados_Entalpia_interp2.xlsx','D7:G11');
pi=str2num(input('Press�o � 1.0 a 1.6 [MPa] =','s'));
ti=str2num(input('Temperatura � 250 a 500 [C] =','s'));
hi=interp2(p,t,h,pi,ti);
fprintf('\nPara uma Press�o de %.2f e Temperatura de %.2f o valor da Entalpia � %.2f\n',pi,ti,hi);

% altera��es aulas 12 mar�o
filename='Dados_Entalpia_interp2.xlsx';
sheet='Folha1';

xlswrite(filename,hi,sheet,'B14')
winopen(filename)

