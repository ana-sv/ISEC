% Ana Rita Santos Videira 
% 21250074
% anarita.svideira@gmail.com
% P3
% 19/3/2019


a)
T=RTrapezios(@fTeste,2,3,2)

T =

    0.7083


    
b)
out_S=RSimpson(@fTeste,2,3,2)

out_S =

    0.6944

    
    
c)
T=RTrapezios(@fTeste,2,3,10)

T =

    0.6938


    
d)

out_S=RSimpson(@fTeste,2,3,10)

out_S =

    0.8750




e)
q=quad(@fTeste,2,3)

q =

    0.6931
    

f)
Atendendo a que a solução extata:

syms x
sExata=int(1/(x-1),2,3)
 
sExata =
 
log(2)
 
log(2)

ans =

    0.6931
    
    
A Regra mais precisa é a Regra de Simpson. 
Com utilização desta regra conseguimos um menor erro. 

Erro com a Regra de Simpson com n=2:
0.6944 - 0.6931 = 0.031

(falta de tempo para completar)

