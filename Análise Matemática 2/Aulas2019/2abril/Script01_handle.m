clc
clear

x=0:0.1:2*pi;
y=sin(x);
h=plot(x,y);

ishandle(h)
get(h)   %manda aceder ás propriedades de um objecto
tipoH=get(h,'Type')

inspect(h)   %abre tabela de propriedades

set(h,'Color',[1,1,0],'Linewidth',20)

h2=get(h,'Parent')
tipoH2=get(h2,'Type')
set(h2,'Color','k')
