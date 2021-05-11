package ex7;


public class Matrix {

    public final static int M= 5;
    public final static int N = 4;

    public final static int MAX = 10;
    public final static int MIN = 1;

    protected int[][] m;

    public Matrix( ){
        m = new int [M][N];
    }


    public void preencheMatrizAuto(){
        for( int i=0; i <M ; i++){
            for(int j=0; j<N; j++ ){
                m[i][j] = generateRandom();
            }
        }

    }

    private int generateRandom(){
        return (int) (Math.random() * (MAX - MIN) ) + MIN;
    }


    public void mostraMatriz(){
        System.out.println("Matrix: " );

        for( int i=0; i <M ; i++){
            for(int j=0; j<N; j++ ){
                System.out.print( m[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public void alteraElemento( int posM, int posN , int n){
        int i, j=0;

        for( i=0; i == posM ; i++){
            for( j=0; j== posN; j++ ){

                m[i][j] = n;
                System.out.println( " antes: " + m[i][j] );
            }
        }
        System.out.println( " depois: " + m[i][j] + "\n");


    }

    public void somaLinhas(){
        int soma=0, somaTotal=0;

        for( int i=0; i <M ; i++){
            for(int j=0; j<N; j++ ){
                soma += m[i][j] ;
            }
            System.out.println( "Soma linha " + i + " : " + soma + " \n");
            soma=0;
            somaTotal += soma;
        }

        System.out.println("Total: " + somaTotal + "\n ");


    }



}
