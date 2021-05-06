
function a=gerarPAritmetica_v3(a_1,r,n)
a(1)=a_1;
i=2;
while (1)
    a(i)=a(1)+(i-1)*r;
    i=i+1;
    if i>n
        break
    end 
end
