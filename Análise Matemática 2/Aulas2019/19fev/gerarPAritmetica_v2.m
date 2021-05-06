
function a=gerarPAritmetica_v2(a_1,r,n)
a(1)=a_1;
i=2;
while i<=n
    a(i)=a(1)+(i-1)*r;
    i=i+1;
end
