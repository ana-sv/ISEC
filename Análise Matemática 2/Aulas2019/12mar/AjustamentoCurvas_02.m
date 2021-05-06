% Ajustamento de Curvas

clc
clear
x=0:1:10
y=[1.3 1.4 1.9 2.6 3.7 4.9 5.6 6.2 6.6 7.0 7.2]

coef = polyfit(x,y,4)

xx = linspace(0,10,100)
yy = polyval(coef,xx)

plot(x,y,'ob',xx,yy,'-r')
grid on