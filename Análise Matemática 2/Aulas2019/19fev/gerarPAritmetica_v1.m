
function a=gerarPAritmetica_v1(a_1,r,n)
a(1)=a_1;
for i=2:n
    a(i)=a(1)+(i-1)*r;
end
