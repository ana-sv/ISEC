function a=geraPAv2(a_1,r,n)
%gera vetor a constituido por PA 1� elemento a_1, raz�o r e n


a=zeros(1,n);
a(1)=a_1;
i=1;

while i<n
    a(i)=a(1)+(i-1)*r;
end 