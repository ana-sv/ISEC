%FRvr Declarar/definir uma fun��o de x
%   f = FRvr()
%   y = f(x) defini��o atrav�s de function_handle
%INPUT:
%  
%OUTPUT: 
%   f - fun��o real de vari�vel real x
%
%   07/03/2016 - Arm�nioCorreia .: armenioc@isec.pt

function f=FRvr()
while(1)
    strF=input('f(x)= ','s');
    f=@(x) eval(vectorize(strF));
    try
        Fteste=f(sym('x'));
        break;
    catch Me
        errordlg('Introduza uma fun��o de x','ERRO','modal');
    end
end