%RSimpson Aproxima��o gr�fica ao gr�fico de uma fun��o atrav�s do gr�fico de uma par�bola
% 06/6/2020 - Ana Videira

function out_S=RSimpson(f,a,b,n)
h=(b-a)/n;
x=a;
s=0;

for i=1:n-1
    x=x+h;
    if(mod(i,2)==0)
        s=s+2*f(x);
    else
        s=s+4*f(x);
    end
end

out_S=h/3*(f(a)+s+f(b));

