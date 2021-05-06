% Interpolação a duas dimensões
% Exemplo da Entalpia=f(pressão,temperatura)
% z=interp2(x,y,z,xi,yi)
% 20/03/2015 Arménio Correia | armenioc@isec.pt

clc
clear
p=xlsread('Dados_Entalpia_interp2.xlsx','D6:G6');
t=xlsread('Dados_Entalpia_interp2.xlsx','C7:C11');
h=xlsread('Dados_Entalpia_interp2.xlsx','D7:G11');
pi=str2num(input('Pressão » 1.0 a 1.6 [MPa] =','s'));
ti=str2num(input('Temperatura » 250 a 500 [C] =','s'));
hi=interp2(p,t,h,pi,ti);
fprintf('\nPara uma Pressão de %.2f e Temperatura de %.2f o valor da Entalpia é %.2f\n',pi,ti,hi);

% alterações aulas 12 março
filename='Dados_Entalpia_interp2.xlsx';
sheet='Folha1';

xlswrite(filename,hi,sheet,'B14')
winopen(filename)

