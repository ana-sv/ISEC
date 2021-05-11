package ex3;

//Escreva uma aplicação de consola que crie um array de inteiros (perguntando ao utilizador a
//dimensão do array e quais os valores dos seus elementos), imprima o array lido e calcule e
//imprima o maior elemento desse array.

import java.util.*;

public class ConfigArray {

    public static void main(String[] args) {

        Scanner sc =  new Scanner(System.in);
        int tam;

        System.out.println("Insira o tamanho do Array : ");
        tam = sc.nextInt();

        int []array = new int[tam];

        for(int i=0; i< array.length; i++ ){
            System.out.println("Insira o elemento " + i + " do array : ");
            array[i] = sc.nextInt();
        }

        for(int i=0; i<array.length; i++) {
            System.out.print(array[i]);
            System.out.print(" ");
        }




    }


}
