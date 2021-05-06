->%aula 1- into mathlab
->clc %limpa o comand window
->clear %Limpa todas as vars em memória 

a=1;
texto= 'o valor de a é:';
disp(texto);
disp(a);

->para editar texto num doc ja guardado à parte usar >>edit aula1
->guardar os ficheiros em .m

->%vetores
v=[4.5 7.8.2]:
v1=v(1) %1a entrada de v
v3=v(3)
v_end=v(end) %ultima entrada de v
v(end-1) %penultima entrada de v1
v(end-2) %antepenultima entrada de v1
v_trans=v'

dimensão=size(v_trans) %nº de linhas e colunas
size(v_trans,1) %so o numero de linhas

length(v) %nº de entradas

%operador dois pontos
%inicio:passo:fim
%passo=1 , não é preciso declarar
%o passo é o incrementador desde o inicio ate ao fim

>>>exemplo:

		1:1:3     resultado>>> 1 2 3 
		
%vetor de incio em 4
%passo 0.7
%majorante 16
t=4:0.7:16

%passo 1
tt=4:16

%graficos 2D
x=-pi:2:piy=sin(x)---> Quanto mais pequeno, mais perfeita fica a curva

plot(x,y)
