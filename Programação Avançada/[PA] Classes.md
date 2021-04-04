# [  PA.T1 - 04/03/2021 ]

 #teorica

## Principais características Java:

* um programa em java não tem nada de global, um programa em java é um grupo de classes. 
* a função main é dentro da classe principal 
*  Em java só há objetos em memória dinâmica  
* grande portabilidade, por possuir um  compilador universal



## Primeiro programa exemplo:

``` java
public class Ola{
     public static void main(String []args ){
          System.out.println("\nBom trabalho! ");          
     }
}
```



## Classes Wrapper 

* classes que encapsulam os tipos primitivos 

* estão definidas em biblioteca 

  ``` java
  parseInt() 
       
     
       
  ```







## Sendo que 

````java
Integer é a classe
int é o tipo primitivo 
````

## Boxing

```java
Integer x = 25 ;   // é a forma abreviada de 
Integer x = new Integer(35);
```

## Unboxing 

````java
int y = x * 2 ; // é a forma abreviada de 
int u = x.intValue() * 2; 
````





# [  PA.P2 - 04/03/2021 ]

#pratica #linhadecomandos #f1ex1



## Correr um programa em java pela linha de comandos: 

1) 



#### Correr programa .java simples, sem packages , com a linha de comando 

![image-20210304160808544](image-20210304160808544.png)



![image-20210304160919740](image-20210304160919740.png)

executando o ficheiro .bat  resulta o ficheiro de compilação Hello.class 

![image-20210304162249416](image-20210304162249416.png)

para executar 

![image-20210304161151430](image-20210304161151430.png)







![image-20210304165847994](image-20210304165847994.png)

![image-20210304171434269](image-20210304171434269.png)

![image-20210304171924339](image-20210304171924339.png)

# [  PA.P1 - 10/03/2021 ]

#exercico6

* definir a classe matriz 



# [  PA.T1 - 11/03/2021 ]

#teorica 

Em java os elementos de um array podem conter apenas :

* valores de tipos primitivos ( ex inteiros )

* referencias para objetops 

  

int [ ] diasMes ou int diasMes [ ]  -> apenas declaração 

diasMes = new int[12]  -> criação de array de inteiros,  reserva de memória 

int diasMes[] = {31,28,31,30} -> declaração e criação 

Em Java os arrays são sempre dinâmicos;

Em java é impossível escrever fora dos limites da memória reservada, ou o programa lança uma exceção ou termina;

Interger , uma classe de biblioteca, faz usar inteiros como objetos  (ppt pg 32 )

função equals() 

![image-20210311153226647](image-20210311153226647.png)

