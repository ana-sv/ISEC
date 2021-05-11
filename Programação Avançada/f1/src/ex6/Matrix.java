package ex6;

public class Matrix {


    public static int[][] sum(int[][] m1, int[][] m2){

        int[][] aux = null;

        if(m1.length == m2.length){
            int lines = m1.length;
            aux = new int[lines][];

            for(int i = 0; i < lines; i++){
                if(m1[i].length == m2[i].length){

                    int columns = m1[i].length;

                    aux[i] = new int[columns];

                    for(int j = 0; j < columns; j++){
                        aux[i][j] = m1[i][j] + m2[i][j];
                    }
                }
                else{
                    aux = null;
                    break;
                }
            }
        }

        return aux;
    }

    public static String seeElements(int[][] matrix){

        String s = new String();

        for(int i = 0 ; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                s += matrix[i][j] + " ";
            }

            s += "\n";
        }

        return s;

    }
}
