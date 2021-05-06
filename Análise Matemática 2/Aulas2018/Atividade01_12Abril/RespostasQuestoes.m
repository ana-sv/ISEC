% 12/04/2018 - Ana Videira .: anarita.svideira@gmail.com
%P8

(a) Usando a regra dos trapézios composta com n=2.
RTrapezios(@FTeste,-1,0,2)

ans =

    2.4583

(b) Usando a regra de Simpson simples, isto é, para n=2.
RSimpson(@FTeste,-1,0,2)

ans =

    0.5833

(c) Usando a regra dos trapézios composta com n=10.
RTrapezios(@FTeste,-1,0,10)

ans =

   13.4004

(d) Usando a regra de Simpson composta com n=10.
RSimpson(@FTeste,-1,0,10)

ans =

    0.6500


(e) Usando a função quad do Matlab.
quad(@FTeste,-1,0)

ans =

    0.6931
    
(f) Das regras (Trapézios ou Simpson) que usou nas alíneas anteriores,
qual delas lhe permite obter maior precisão? Justifique.

A Regra mais precisa é a Regra de Simpson. Com utilização desta regra
conseguimos um menor erro. 


