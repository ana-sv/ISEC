% Interface (vers�o 2) para os PVI
% Aplica��o dos M�todos Num�ricos de Euler e de Runge-Kutta
% 
% Modificado por: Arm�nio Correia
% Data: 10/10/2013

clear;
primeira = 1;
opcao = 1;
while opcao ~= 7 
    clc;
    disp('M�TODOS NUM�RICOS PARA PVI');
    disp(' ');
    if(~primeira)
        fprintf ('1. INTRODUZIR PAR�METROS DO PVI\n');     
        fprintf ('2. M�TODO DE EULER\n');
        fprintf ('3. M�TODO DE EULER MELHORADO\n'); 
        fprintf ('4. M�TODO DE RK2\n');
        fprintf ('5. M�TODO DE RK4\n');
        fprintf ('6. APLICAR OS 3 M�TODOS EM SIMULT�NEO\n')
        fprintf ('7. TERMINAR\n\n');
        opcao = input('Op��o: ');
    else
        opcao    = 1;
        primeira = 0;
    end
    
    y = [];
    switch opcao
        case 1
            while (1)
                strF = input('f(t,y) = ','s');
                f    = @(t,y) eval(vectorize(strF));
                try
                    fTeste = f(sym('t'),sym('y'));
                    break;
                catch
                    errordlg('Introduza uma fun��o em t e y','ERRO','modal');
                end
            end
            
            while (1)
                a = str2num(input('a = ','s'));
                if (isscalar(a) && isreal(a)) break; end
            end
            b = str2num(input('b = ','s'));
            n = str2num(input('n = ','s'));
            y0 = str2num(input('y0 = ','s'));

        case 2 
              y = NEuler(f,a,b,n,y0);
                        
        case 3  
              y = NEulerM(f,a,b,n,y0);
                         
        case 4
              y = NRK2(f,a,b,n,y0);
              
        case 5
              y = NRK4(f,a,b,n,y0);
              
        case 6
              y = ODE45_1ORD(f,a,b,n,y0);          
    end
    
    if ~isempty(y)
        disp(' ');
        disp('AS APROXIMA��ES OBTIDAS S�O:');
        disp(' ');
        disp(y); 
    end
    if opcao ~= 7
        tecla = input('\nPrima uma tecla para continuar ...');
    end
end
    
