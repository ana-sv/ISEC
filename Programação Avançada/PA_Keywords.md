
# [2020-2021] [Keywords] Apontamentos Programação Avançada 

# public




# static 

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




