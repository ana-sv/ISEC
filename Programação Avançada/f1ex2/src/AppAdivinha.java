
//Escreva uma aplicação que solicite ao utilizador para pensar num número entre 1 e 100.
// Através de várias perguntas ao utilizador, a aplicação deve adivinhar esse número

import java.util.*;

public class AppAdivinha {

    public final static int MIN = 0;
    public final static int MAX = 100;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int sup = MAX, inf = MIN, palpite, opcao;

        System.out.println();
        System.out.println("Pense num numero inteiro entre " + MIN + " e " + MAX + ".");

        do {
            // Apresente um palpite com base nos valores de inf e sup
            palpite = inf + (int) (Math.random() * (sup - inf));
            System.out.println();
            System.out.println("Palpite: " + palpite);

            System.out.println();
            System.out.println("1 - Palpite certo");
            System.out.println("2 - Palpite demasiado baixo");
            System.out.println("3 - Palpite demasiado alto");
            System.out.println();

            System.out.print("> ");
            // Obtenha a resposta do utilizador
            opcao = sc.nextInt();

            if( opcao == 2 )
                inf = palpite;
            else if (opcao == 3)
                sup = palpite;


        } while (opcao != 1 && inf < sup);

        System.out.println();
        System.out.print("Resposta: " + (inf == sup ? inf : palpite) + "\n");


    }
}
