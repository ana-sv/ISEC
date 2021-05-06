clc
clear 


t = 1900:10:1990;
p = [ 75.995  91.972  105.711  123.203  131.669 ...
     150.697 179.323  203.212  226.505  249.633 ];
 
ano=input('indica o nao que pretende calcular: ');
pop_ano=interp1(t,p,ano);

fprintf('\n A população estimada no ano %4.0f é %8.3f \n', ano, pop_ano);

tabela=[t' p']
%fprintf('\n Ano Pop.(M)\n' , '%4.0f %8.3f',tabela); Explorar em casa LOL
%disp(tabela)

anos=1900:5:1990
pop_anos=interp1(t,p,anos);

plot(ano,pop_ano)
hold on
plot(anos, pop_anos,'or')
hold off
 