disp('----------------------')
disp('Metodo das tangentes')
disp('----------------------')
disp('')

syms x
symf=f(x);
(...)


while(1)
    kmax=input('nº max de iterações =', 's');
    kmax=str2num(kmax);
    if (~isempty(kmax)&& kmax>0 && ~mod(kmax,1));
        break;
    end
end

while(1)
    kmax=input('dif min entre (...)  =', 's');
    kmax=str2num(tol);
    if (~isempty(toll)&& kmax>0);
        break;
    end
end


while(1)
    x0=input('aprox inicial =', 's');
    x0=str2num(x0);
    if (~isempty(x0)&& f(x0)*df2_dx(x0)>0)
        break;
    end
    disp('')
end



