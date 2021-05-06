% Interpolação linear

clc
clear
x = 0:10:100
y = [0.0 0.9 2.4 3.1 4.2 4.8 5.6 5.9 6.2 6.4 6.5]
xi= 25:10:45
yi= interp1(x,y,xi)

