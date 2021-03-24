
import java.util.*;


public class Array {
    public final static int TAM_ARRAY = 20;
    public final static int MAX_VALOR = 100;

    protected int[] a ;
    protected int qtValoresDup;
    protected int posicao;

    public Array(){
        a = new int[TAM_ARRAY];
        qtValoresDup = 0;
        posicao = 0;
    }

    public void preencheArray(){
        int x;
        for( int i=0 ; i < TAM_ARRAY; i++){

            x = (int)(Math.random() * MAX_VALOR);
            while( valorExistente(x) ){
                System.out.println("Valor Duplicado : " + x);
                x = (int)(Math.random() * MAX_VALOR);
                qtValoresDup++;
            }

            a[posicao] = x;
            posicao++;

        }
    }

    public boolean valorExistente(int valor){
        for(int i=0; i< a.length; i++) {
            if (valor == a[i])
                return true;
        }
        return false;
    }

    public void listaConteudoArray() {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
            System.out.print(" ");
        }
        System.out.println();
    }

    public int getValoresDuplicados() {
        return qtValoresDup;
    }



    public static void main(String[] args) {
        Array ar = new Array();

        ar.preencheArray();
        System.out.println();
        System.out.println("Valores gerados duplicados: " + ar.getValoresDuplicados() );

        System.out.println("Array: ");
        ar.listaConteudoArray();




    }


}
