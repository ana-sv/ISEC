function x=MTangentes(f,df_dx,x0,kmax,tol)
k=1;
x(k)=x0;
while k<=kmax
    x(k+1)=x(k)-f(x(k))/df_dx(x(k));
    if abs(x(k+1)-x(k))<tol break;end
    k=k+1;
end