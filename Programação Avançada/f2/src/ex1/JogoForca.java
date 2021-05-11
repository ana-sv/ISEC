package ex1;

import java.util.*;

public class JogoForca {

    public static final int MAX_TENTATIVAS = 7;

    protected String palavra;
    protected StringBuffer resultado;
    protected char[] caracteresJogados;
    protected int tentativas;
    protected boolean concluido;

    public JogoForca(){
        inicia();
    }

    public void inicia(){
        tentativas = 0;
        concluido = false;

        // escolhe de forma aleatoria uma das palavras da lista

        int n = (int)(Math.random()*ListaPalavras.getTamanho());
        palavra = ListaPalavras.getPalavra(0).toUpperCase(); //MODIFICAR

        resultado = new StringBuffer();

        // acrescenta numero de astericos igual ao numero de letras da palavra a adivinhar
        for(int i=0; i<palavra.length(); i++){
            resultado.append("*");
        }
        caracteresJogados = new char[MAX_TENTATIVAS];

    }



    public boolean jogoConcluido(){
        if ( getResultado().equals(palavra) || tentativas >= MAX_TENTATIVAS)
            return true;
        return false;
    }

    public String getResultado(){
        return resultado.toString();
    }


    // tenta adivinhar letra
    public void setOpcao( char c) {
        int i;

        if (tentativas >= MAX_TENTATIVAS)
            return;

        // Se o c já foi jogado, ignora-o
        c = Character.toUpperCase(c);
        for (int j = 0; j < tentativas; j++) {
            if (caracteresJogados[j] == c)
                return;
        }

        caracteresJogados[tentativas++] = c;

        // se c estiver na palavra, susbstitui-se o asterisco pela letra no sitio devido
        for (i = 0; i < resultado.length(); i++) {
            if (palavra.charAt(i) == c) {
                resultado.setCharAt(i, c);
            }
        }

        // Se a palavra em resultado já coincidir com a palavra a encontrar OU se terminaram as tentativas
        // o jogo está concluido;
       concluido =  jogoConcluido();
    }


    // tenta adivinhar palavra
    public void setOpcao(String p)
    {
        if(tentativas >= MAX_TENTATIVAS)
            return;

        if(p.length()==1){
            //E' apenas um caractere
            setOpcao(p.charAt(0));
            return;

        }else if(p.length() != palavra.length()){
            //Se a palavra a tentar não tem o mesmo tamanho que a adivinha, ignora-a
            return;
        }

        tentativas++;

        resultado = new StringBuffer(p.toUpperCase());

        //Jogo terminado
        concluido = true;
    }


    public boolean getAcertou(){
        return resultado.toString().equals(palavra);
    }

    public int getTentativas(){
        return tentativas;
    }

    public String getPalavra(){
        return palavra;
    }

    public String getCaracteresJogados(){
        return new String( caracteresJogados );
    }


}
