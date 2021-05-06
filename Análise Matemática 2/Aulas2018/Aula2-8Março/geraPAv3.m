function a=geraPAv3(a_1,r,n)
%gera vetor a constituido por PA 1º elemento a_1, razão r e n

a=zeros(1,n);
a(1)=a_1;
i=1;

while(1)
    a(i)=a(1)+(i-1)*r;
    i=i+1;
    if i>n
        break;
    end 
end 
