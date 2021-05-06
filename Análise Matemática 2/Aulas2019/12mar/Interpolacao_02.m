% Interpolação cúbica

clc
clear
t = 1950:10:1990
popul = [150.697 179.323 203.212 226.505 249.633]
popul2010 = spline(t,popul,2010)

