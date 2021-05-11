package ex7;


public class Ex7 {

    public static void main(String[] args){
        Matrix a = new Matrix();

        a.preencheMatrizAuto();
        a.mostraMatriz();

        a.alteraElemento(0,0,-1);
        a.mostraMatriz();

        a.somaLinhas();



    }

}
