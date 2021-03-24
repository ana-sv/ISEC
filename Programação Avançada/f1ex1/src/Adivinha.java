

//  Escreva uma aplicação que gere um inteiro aleatório entre 0 e 100 e que permita
//  ao utilizador adivinhar o número gerado.

import java.util.*;

public class Adivinha {

    public final static int MIN = 0;
    public final static int MAX = 100;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); // para input
        int palpite = -1, tentativas = 0;

        int range = MAX - MIN + 1;
        int n = (int) (Math.random() * range) + MIN;

        while (palpite != n) {
            System.out.print("Digite o palpite: ");
            palpite = sc.nextInt();

            if (palpite > n) {
                System.out.print("O numero e menor! ");
            } else if (palpite < n) {
                System.out.print("O numero e maior! ");
            }
            tentativas++;
        }

        System.out.println("Parabéns! Acertou com " + tentativas + "  tentativas!");
        System.exit(0);


    }


}