# [2020-2021] Apontamentos Programação Avançada  
# Compilar  & executar pela linha de comandos 

#falta

# Leitura  a partir do teclado 

```java
import java.utils.Scanner; 
// ou 
import.java.utils.*;


Scanner sc = new Scanner(System.in);   // criação de um objeto da classe Scanner 

int n = sc.nextInt();	// lê um inteiro
double x = sc.nextDouble(); // lê um double

sc.useDelimiter("-"); //definição de um delimitador 

if( sc. hasNextDouble() ){   // verifica se o proximo valor é um double 
     x = sc.nextDouble();
}

```



# Tipos Primitivos

| Inteiros        | Caracteres     | Ponto Flutuante  | Logicos         |
| --------------- | -------------- | ---------------- | --------------- |
| byte - 8 bits   | char - 16 bits | float - 32 bits  | boolean - 1 bit |
| short - 16 bits |                | double - 64 bits |                 |
| int - 32 bits   |                |                  |                 |
| long - 64 bits  |                |                  |                 |

# Arrays de tipos primitivos

``` java
int [] a = new int[10]; // array unidimensional 

for( int i =0 ; i < a.length; i++ ){  // percorrer o array bidimensional 
     
}
```

``` java
double [][] b = new double [3][4];  // array bidimensional 

int [][] b = new double [3][];  // array bidimensional nao tendo sempre o mesmo numero de linhas 
b[0] = new int[3];
b[1] = new int[4];
b[2] = new int[2];


b[i].length // numero de linhas do array 
 
for ( int i=0 ; i < b.length ; i++){      // percorrer um array bidimensional 
	for ( int j=0 ; j< b[i].length ; j++){
	// b[i][j] ...
	}
}
     
```



# Classes Wrapper

Classes que encapsulam os tipos primitivos. Estão definidas em biblioteca e contêm métodos estáticos relacionados com os tipos primitivos correspondentes como:

```java
parseInt() transforma um argumento do tipo String no valor inteiro correspondente 
     
int n = Integer.parseInt("456"); // o valor inicial de n é 456
```

| Tipo primitivo | Classe Wrapper |
| -------------- | -------------- |
| byte           | Byte           |
| short          | Short          |
| int            | Integer        |
| long           | Long           |
| char           | Character      |
| float          | Float          |
| double         | Double         |
| boolean        | Boolean        |
| void           | Void           |



# Boxing 

```java
Integer x = 25; 
// é igual a 
Integer x = new integer(25);
```

# Unboxing 

```java
int y = x * 2;
// é igual a 
int y = x.intValue() * 2;
```



# Números aleatórios 

``` java
import java.lang; // para ter acesso à classe Math 

Math.random() // retorna um double aleatorio ente 0,0 e 1,0 
   
(int)(Math.random()*49) + 1 // gera um número aleatório inteiro entre 1 e 49 

```



```java
// Java program to demonstrate working 
// of java.lang.Math.random() method 
import java.lang.Math; 

class Gfg2 { 

	// driver code 
	public static void main(String args[]) 
	{ 
		// define the range 
		int max = 10; 
		int min = 1; 
		int range = max - min + 1; 

		// generate random numbers within 1 to 10 
		for (int i = 0; i < 10; i++) { 
			int rand = (int)(Math.random() * range) + min; 

			// Output is different everytime this code is executed 
			System.out.println(rand); 
		} 
	} 
} 

```

https://www.geeksforgeeks.org/generating-random-numbers-in-java/

https://www.geeksforgeeks.org/java-math-random-method-examples/






# Operadores Relacionais & equals()

```java
public class Equivalencia{
	public static void main( String [] args ){
		Integer n1 = new Integer( 47);
		Integer n2 = new Integer( 47);
		System.out.println( n1 == n2 );
		System.out.println( n1 != n2 );
	}
}

//Imprime
// true
// false
```


```java
public class MetodoEqualsUm{
	public static void main( String [] args ){
		Integer n1 = new Integer( 47);
		Integer n2 = new Integer( 47);
		System.out.println( n1.equals( n2));
	}
}

// Imprime :
// true
```


# Conversões & Operador Cast

```java 
// conversão implicita 
int i=1;
float f;
```

## Converções explicitas do tipo cast
```java
int i;
float f=2;
// i = f; //ERRO
i = (int) f;
f = i;
```

```java
byte a=1, b=2, c;
//c = a+b; //ERRO
c = (byte)(a + b);
```

#Upcasting 
Conversão de tipo de uma classe derivadas para uma classe base, converte um tipo mais restrito num tipo mais alargado.

```java
public class Exemplo {

	static void verifica( VeiculoRodoviario x){
	x.aviso();
	// x.maisUmPassageiro(); //ERRO: não conhece este método
	}

	public static void main( String[]args){
		VeiculoDePassageiros autocarro = new VeiculoDePassageiros(140, 130, 40, 39);
		autocarro.aviso();
		autocarro.maisUmPassageiro();
		autocarro.maisUmPassageiro();
		verifica(autocarro);
	}
}
```

# Polimorfismo 
Redefinição de métodos e afins, como C++

# Classes Abstratas
- Possuem metodos abstractos que são apenas "protótipos" de métodos comuns a outras classes derivadas. 
- Uma classe que tenha pelo menos um método abstracto é uma classe abstracta e tem que ser declarada como tal.
- É possivel definir uma classe como abstracta , mesmo que não tenha nenhum método abstracto , usando ```abstracr ```
- Não é possivel criar objectos de classes abstractas 
- Pode haver referências para classes abstractas ( referindo objectos de classes derivadas não abstractas)

- Numa classe derivada de uma classe abstracta -> a classe derivada não será abastracta e tem que ter todos os métodos definidos 

# Interfaces
- Um interface pode especificar as funcionalidades que as classes que o implementam devem proporcionar 
- Para definir que uma classe implementa um ou vários interfaces 
```java 
class Cliente implements Chamada {...}
```
- Quando uma classe implemneta um interface, os métodos do inerface que são definidos na classe devem ser declarados ```public ```
- Várias classes podem implementar um interface 



# Classe Object 
- Todas as classes dervivam direct ou indirectamente de Object 

Alguns métodos da classe
```java public String toString() ``` retorna uma string que descreve o objeto
```java public boolean equals(Object obj) ``` testa a igualdade entre este objecto e o objecto referido por obj
```java public int hashCode() ```retorn o valor do hash code deste objeto
```java protected Object clone() ``` cria e retorna uma copia deste objeto
```java public final Class <?> getClass() ``` retorna o objeto Class que representa o tipo deste objeto

## hashCode & equals 
- Se ```java x.equals(y)```` então ```java x.hashCode() == y.hashCode()```
- hashCode() retorna um inteiro que resulta da conversão do endereço interno do objecto
- quanso se redifine equals() deve redefinir-se hashCode() de maneira compativel





# instanceof 
Operador que permite testar o tipo de objecto, devolve true/false
```java
 ref instanceof Produto 
```

# break e continue
```java
System.out.println("Teste:");
exterior:for ( int i=0 ; i<4 ; i++){
	System.out.println("i="+i);
	for (int j=0 ; j<3 ; j++){
		if (j==1) {
			System.out.println(“\tbreak exterior em j="+j);
			break exterior;
		}
	System.out.println(“\tj="+j);
	}
}

// imprime: 
// Teste:
// i=0
// 	j=0
// break exterior em j=1
```

# this 
Usado para fazer chamadas implicitas 
```java
class Rectangulo {
	double comprimento;
	double largura;
	
	Rectangulo(){ this(0,0); }
	
	Rectangulo(double c, double l){
		comprimento = c; largura = l;
	}
	
	double area(){ 
		return comprimento*largura;}
	}
```

# finalize()
Garbage collector , liberta memória dos objectos não referenciados , memória que foi reservadas com new
Pode não libertar a memória correspondente a todos os objectos e , deste modo, a execução do método finalize)= pode não aconetecer para todos os objetos 

#Packages
https://www.geeksforgeeks.org/packages-in-java/



# final

* uma variável declarada com a final keyword não pode ser modificada, torna-a numa constante ; deve ser inicializada.
* é boa prática serem representadas em maiúsculas


```
Final Variable --> To create constant variables
Final Methods --> Prevent Method Overriding
Final Classes --> Prevent Inheritance
```


```java
// Java program to demonstrate  
// reference final variable 

class Gfg 
{ 
    public static void main(String[] args)  
    { 
        // a final reference variable sb 
        final StringBuilder sb = new StringBuilder("Geeks"); 
          
        System.out.println(sb); 
          
        // changing internal state of object 
        // reference by final reference variable sb 
        sb.append("ForGeeks"); 
          
        System.out.println(sb); 
    }     
} 
```

### blank finals 
Devem ser inicializados em todos os construtores 

```java
class Valor{
        int i=1;
}

public class BlankFinal{
        final int i=0; //final inicializado na declaração
        final int j; // blank final
        final Valor p; // referência blank final

        BlankFinal(){
                j=1;
                p=new Valor();
        }
        BlankFinal( int x){
                j=x;
                p=new Valor();
        }
        
	public static void main( String [] args){
    	    BlankFinal bf=new BlankFinal();        
	}
}

```





