%FRvr Declarar/definir uma função de x
%   f = FRvr()
%   y = f(x) definição através de function_handle
%INPUT:
%  
%OUTPUT: 
%   f - função real de variável real x
%
%   07/03/2016 - ArménioCorreia .: armenioc@isec.pt

function f=FRvr()
while(1)
    strF=input('f(x)= ','s');
    f=@(x) eval(vectorize(strF));
    try
        Fteste=f(sym('x'));
        break;
    catch Me
        errordlg('Introduza uma função de x','ERRO','modal');
    end
end