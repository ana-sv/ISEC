clc
clear

x=-2*pi:0.1:2*pi;
y=sin(x);

h1=plot(x,y)
ishandle(h1)
get(h1)
tipoH1=get(h1,'Type')
inspect(h1)
set(h1,'Color',[1,0,0],'LineWidth',4)
h2=get(h1,'Parent')
tipoH2=get(h2,'Type')
inspect(h2)
set(h2,'Color','y')
pause(2)
set(h2,'Visible','off')



