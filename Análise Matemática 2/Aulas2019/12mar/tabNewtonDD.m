function d = tabNewtonDD(x,y)
%Função que cria a tabela das diferenças divididas.
%Chamada da função D = tabNewtonDD(x,y)
%
%Argumento de entrada: x - vector dos pontos de interpolação.
%Argumento de entrada: y - vector das imagens dos pontos de interpolação.
%
%Saida - Matriz triangular superior, onde os coeficientes a0,a1,...,an 
%do polinómio interpolador de Newton coincidem com os elementos da 1ª linha.

        %--------------------------------
        %instrução que determina o número de pontos de interpolação 
        nPtos = length(x);
    
        %--------------------------------
        %d - variável onde se armazena a matriz (tabela) 
        %das diferênças divididas
        d = y.';
        %--------------------------------    
        
        for j=1:nPtos-1, %varrimento da matriz por colunas
                for i=1:nPtos-j,%varrimento da matriz por linhas
                        d(i,j+1) = (d(i+1,j) - d(i,j))/(x(i+j) - x(i)); %cálculo das diferênças divididas
                end
        end
