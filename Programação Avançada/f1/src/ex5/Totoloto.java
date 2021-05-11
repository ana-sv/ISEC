package ex5;


import java.util.Arrays;

public class Totoloto {

    public final static int MIN_VALOR = 1;
    public final static int MAX_VALOR = 49;
    public final static int TAM_APOSTA = 6;

    protected int[] aposta;
    protected int numPreenchidos;

    public Totoloto(){
        numPreenchidos = 0;
        aposta = new int[TAM_APOSTA];
    }

    // Preenche um número de casa vez com vista à construção da aposta
    protected boolean preencheNumero(int numero){
        if(numPreenchidos >= TAM_APOSTA || numeroJaPreenchido(numero) ){
            return false;
        }

        aposta[numPreenchidos++] = numero;
        return true;
    }

    protected boolean numeroJaPreenchido(int numero){
        for(int i=0; i<numPreenchidos; i++){
            if(numero == aposta[i])
                return true;
        }
        return false;
    }

    // Verificar se a aposta está completa
    public boolean apostaCompleta(){
        return numPreenchidos >= TAM_APOSTA;
    }

    // Preencher automaticamente uma aposta completa
    public void geraAposta(){
        boolean a = true;
        for( int i =0; i<TAM_APOSTA; i++){

            while(a){
                a = preencheNumero((int) (Math.random()*MAX_VALOR)+1 );
            }
        }
    }

    // Comparar a aposta corrente com uma aposta ganhadora
    public int comparaApostas( Totoloto outraAposta ){
        int iguais = 0;
        for(int i=0; i<TAM_APOSTA; i++){
            for(int j=0; j<TAM_APOSTA; j++) {
                if (aposta[i] == outraAposta.aposta[j])
                    iguais++;
            }
        }
        return iguais;
    }

    // Mostrar Aposta
    public void mostraAposta(){
        int i;
        System.out.format("[%3s", aposta[0]); //a string in a column of at least 3 characters

        for(i=1; i<TAM_APOSTA; i++)
            System.out.format("%3s", aposta[i]);

        System.out.format(" ]\n");
    }

    public void mostraApostaOrdenada(){
        int i;
        int[] aux;
        aux = Arrays.copyOf(aposta, TAM_APOSTA);
        Arrays.sort(aux);

        System.out.format("[%3s", aux[0]); //a string in a column of at least 3 characters

        for(i=1; i<TAM_APOSTA; i++)
            System.out.format("%3s", aux[i]);

        System.out.format(" ]\n");
    }


    public static void main( String[] args ){
        Totoloto apostaMaria = new Totoloto();
        Totoloto apostaManuel = new Totoloto();

        apostaMaria.geraAposta();
        System.out.println("Aposta Maria");
        apostaMaria.mostraAposta();
        apostaMaria.mostraApostaOrdenada();


        while( apostaManuel.preencheNumero( (int) (Math.random()*MAX_VALOR)+1) );
        System.out.println("Aposta Manuel");
        apostaManuel.mostraAposta();
        apostaManuel.mostraApostaOrdenada();

        System.out.println("As apostas têm " + apostaMaria.comparaApostas(apostaManuel) + " numeros em comum ");


    }

}