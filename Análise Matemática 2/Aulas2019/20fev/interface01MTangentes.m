clc 
clear 

disp(upper('--------Métodos das Tangentes--------'))

strF=input('f(x)=','s');
f=@(x) eval(vectorize(strF));

df=diff(f(sym('x')))
df_dx=@(x) eval(vectorize(char(df)))

a=input('a=');
b=str2num(input('b=','s'));
x0=str2num(input('x0=','s'));
kmax=str2num(input('kmax=','s'));
tol=str2num(input('tol=','s'));
x=MTangentes(f,ff_dx,x0,kmas,tol);
disp(x)