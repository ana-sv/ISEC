% Ajustamento de Curvas

clc
clear
x=0:1:10
y=[1.3 1.4 1.9 2.6 3.7 4.9 5.6 6.2 6.6 7.0 7.2]

coef = polyfit(x,y,1)

yr = coef(1).*x + coef(2)

plot(x,y,'ob',x,yr,'-r')
grid on