#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int troca( int *a, int *b){
    int c;
    
    c= *a;
    *a = *b;
    *b = c;

}


int main(int argc, char** argv) {
    

   int a=5, b=10;
   troca(&a,&b);
   cout<<"\na = "<<a<<"\nb = "<<b<<endl;
   //aparece a=10 e b=5 
    
	
	return 0; 
	
	}