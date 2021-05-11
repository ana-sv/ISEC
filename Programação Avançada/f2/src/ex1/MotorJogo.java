package ex1;
import java.util.Scanner;

public class MotorJogo {

    private static void apagaConsola()
    {
        //Runtime.getRuntime().exec("cls");
        for (int i = 0; i < 50; ++i)
            System.out.println();
    }


    public static void main( String []args ){

        JogoForca jogo = new JogoForca();
        Scanner sc = new Scanner(System.in);
        boolean continua = true;
        String opcao;

        while(continua){

            jogo.inicia();

            apagaConsola();

            while(!jogo.concluido){

                System.out.println(jogo.getResultado());
                System.out.println();

                System.out.println("Tentativas Realizadas: " + jogo.getTentativas());
                System.out.println("Caracteres Utilizados: " + jogo.getCaracteresJogados());
                System.out.println();

                System.out.print("Adivinhe o caracter / palavra completa com " + jogo.getResultado().length() + " : ");
                opcao = sc.next().toUpperCase();
                opcao = opcao.trim();  // trim tira os espaços e assim
                jogo.setOpcao(opcao);

                System.out.println();

            }

            if(jogo.getAcertou()){
                System.out.println("Parabens, acertou na palavra \"" + jogo.getPalavra() + "\" em " + jogo.getTentativas() + " tentativas!");
            }else{
                System.out.println("A palavara certa era: \"" + jogo.getPalavra() + "\"!");
            }

            do{
                System.out.println();
                System.out.print("Mais uma partida (s/n): ");
                opcao = sc.next().toLowerCase();
            }while(!opcao.equals("s") && !opcao.equals("n"));

            if(opcao.equals("n")){
                continua = false;
            }

        }

    }



}
