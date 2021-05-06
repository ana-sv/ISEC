% Aula 1 - intro Matlab
% Escalares, vetores, matrizes, graficos
% Data da ultima actualização: 1/3/2018
% Ana Videira

clc %limpa a comand window
clear %limpa tudo o que está em memória

% Escalares
% declarar um variavel/atribuição
a=1;
b=2;
disp('--------------------------------')
disp('a soma de a com b é:')
disp(a+b)

% Vectores
t1='ola';
t2=' ';
t3='mundo';
disp([t1,t2,t3])
texto=[t1 t2 t3];
letraO=texto(1);
letrafinal=texto(end);
texto(5);
numeros=[-2 -1 0 1 2 3];
numeros(1);
v=-5:0.3:5;
texto(3:7); %carateres todos desde o 3 ate ao 7 
numeros(numeros>0);
numeros(numeros~=0);

%qtas entradas do vetor numeros sao maiores que?
sum(numeros>1)

%grafico
tic
x=-pi:0.00001:pi
y=sin(x)
plot(x,y)
length(x)
size(x)
toc  %tic no inicio e toc no fim dão o tempo de execusão







