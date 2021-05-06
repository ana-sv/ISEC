function d = tabNewtonDD(x,y)
%Fun��o que cria a tabela das diferen�as divididas.
%Chamada da fun��o D = tabNewtonDD(x,y)
%
%Argumento de entrada: x - vector dos pontos de interpola��o.
%Argumento de entrada: y - vector das imagens dos pontos de interpola��o.
%
%Saida - Matriz triangular superior, onde os coeficientes a0,a1,...,an 
%do polin�mio interpolador de Newton coincidem com os elementos da 1� linha.

        %--------------------------------
        %instru��o que determina o n�mero de pontos de interpola��o 
        nPtos = length(x);
    
        %--------------------------------
        %d - vari�vel onde se armazena a matriz (tabela) 
        %das difer�n�as divididas
        d = y.';
        %--------------------------------    
        
        for j=1:nPtos-1, %varrimento da matriz por colunas
                for i=1:nPtos-j,%varrimento da matriz por linhas
                        d(i,j+1) = (d(i+1,j) - d(i,j))/(x(i+j) - x(i)); %c�lculo das difer�n�as divididas
                end
        end
