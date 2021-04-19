//Iterador
//begin()
//end()
//it++
//*it
class empresa{
	string nome;
	vector<pessoa*>p
public:
	void eliminar(pessoa *a){
		auto it=p.begin();
		//ou vector<pessoa*>::iterator it=p.begin();
		while(it!=p.end()){
			if(a == it*)
				it=p.erase(it); // alem de apagar reajusta a posicao do it
			it++;
		}
	}
}


//Construtor por Copia

class empresa{
	string nome;
	vector<pessoa *>p;
public:
	empresa(emresa & b){
		for(unsigned int i=0;i<b.p.size();i++)
			this->p.push_back(b.p[i]);
		this->nome=b.nome;
	}
};



// EX 7 fichas..
#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

class coordenada {
	int x, y;
public:
	coordenada(int px, int py) {
		x = px;
		y = py;
	}
	int getX() { return x; }
	int getY() { return y; }
	coordenada & operator+(coordenada aux) {
		this->x = this->x + aux.x;
		this->y = this->y + aux.y;
		return *this;
	}
	coordenada operator++(int) {
		this->x=this->x+1;
		this->y=this->y+1;
		return *this;
	}
};


int main() {
	coordenada a(1, 2), b(3, 4), c(5, 6);
	a = b = c;

	cout << "A = " << a.getX() << "/" << a.getY() << endl;
	cout << "B = " << b.getX() << "/" << b.getY() << endl;
	cout << "C = " << c.getX() << "/" << c.getY() << endl;

	a++;

	cout << "A = " << a.getX() << "/" << a.getY() << endl;

	a + b + c;

	cout << "A = " << a.getX() << "/" << a.getY() << endl;

}


//EXAME 21/01/2014 EX4

#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

class amigos {
	vector<string>nomes;
	int num;
public:
	amigos(){}
	void maisumamigo(string nome) { nomes.push_back(nome); }
	string get_amigo(int i) { return (string)nomes.at(i); }
	unsigned int getnumamigos() const { return nomes.size(); }
	~amigos() { nomes.clear(); }
};

void mostraAmigos(amigos a) {
	for (unsigned int i = 0; i < a.getnumamigos(); i++)
		cout << a.get_amigo(i);
}

//EXAME 21/01/2014 EX3

#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

class somador {
	int n;
public:
	somador(int i) { n = i; }
	somador & operator+(somador b) {
		n += b.n;
		return *this;
	}
	int getN() { return n; }
};

void main() {
	somador a(10), b(5), c(2);
	somador res(0);

	res = a + b + c;

	cout << res.getN();
}



//EXAME 21/01/2014 EX2

#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

class soldado {
	string equipa;
public:
	soldado(string e) { equipa = e; }
	virtual string especialidade() = 0;
	void atingido() { cout << "ai"; }
};

class arqueiro : public soldado {
	string equipa;
public:
	arqueiro(string n = 0) :soldado(n) {
		equipa = "azul";
	}
	string get_equipa() { return equipa; }
	string especialidade() { return "arco e flecha"; }
	void atingido() { cout << "isso doeu"; }
};

void main() {
	soldado *a;
	a = new arqueiro("lol");
	cout << a->especialidade() << endl;
	a->atingido();
	cout << endl << ((arqueiro*)a)->get_equipa() << endl;
}


//EXAME 15/01/2013 PRATICA
#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

class componente {
protected:
	string nome;
	float peso;
	unsigned int potencia;
	string funcao;
public:
	//componente(string n, float p, unsigned int x, string f) {
	//	nome = n;
	//	peso = p;
	//	potencia = x;
	//	funcao = f;
	//}
	componente(){}
	string get_nome() { return nome; }
	string get_funcao() { return funcao; }
	float get_peso() { return peso; }
	unsigned int get_pot() { return potencia; }
	virtual bool ligac(int x, string n) = 0;
	virtual bool desligac(int x, string n) = 0;
};

class componenteEsquisito : public componente {

public:
	componenteEsquisito(string n, float p, unsigned int x, string f):componente() {
		nome = n;
		peso = p;
		potencia = x;
		funcao = f;
	}
};

class aparelho {
	int estado;
	string utilizacao;
	vector<string>componentes;
	vector<componente*>composicao;
public:
	aparelho(string n1, string n2, string n3, string n4,string n5) {
		estado = 0; //desligado
		utilizacao = n1;
		componentes.push_back(n2);
		componentes.push_back(n3);
		componentes.push_back(n4);
		componentes.push_back(n5);
	}
	void verifica(string n, componente *a) {		
		int comp_list=0,comp_mont=0;
		for (unsigned int i = 0; i < componentes.size();i++)
			if (n == componentes[i]) {
				comp_list++;
			}
		
		for (unsigned int j = 0; j < composicao.size(); j++)
			if (n == composicao[j]->get_nome())
				comp_mont++;
		
		if(comp_mont<comp_list)
			composicao.push_back(a);
	}
	aparelho & operator+=(componente & aux) {
		this->set_componente(&aux);
	}
	void set_componente(componente *aux) {
		composicao.push_back(aux);
	}
	unsigned int get_list_num() { return componentes.size(); }
	unsigned int get_mont_num() { return composicao.size(); }
	bool liga(int x) {
		
		float pot_precisa=0;
		float pot_adquirida=0;

		if (this->estado == 0) {
			if (get_list_num() == get_mont_num()) {
				for (unsigned int j = 0; j < composicao.size(); j++)
					pot_precisa += composicao[j]->get_pot();

				if (pot_adquirida > (pot_precisa*0.8)) {
					estado = 1;
					return true;
				}
				else
					return false;
			}
		}
		else
			return false;
	}
	bool desliga() {
		if (estado == 1) {
			estado = 0;
			return true;
		}
		else
			return false;		
	}
};

ostream & operator<<(ostream & saida, componente & aux) {
	return saida << aux.get_nome() << aux.get_funcao() << aux.get_peso() << aux.get_pot();
}

void main() {
	componente *a;
	a=new componenteEsquisito(" Transformador ", 4.2, 4, " computador ");
	//componente componente2(" Fusivel ", 0.2, 2, " automovel ");

	/*cout << componente1 << endl << componente2 << endl;*/
	
	aparelho computador("Computador", "Transformador", "Fusivel", "Fonte", "Pilha");

}




//EXAME 15/01/2013 EX5 TEORICO

#include <iostream>

using namespace std;

class A{
	int n;
	string nome;
public:
	A() { n = 0; }
	A & operator=(string n);
	A & operator+=(A aux);
	bool operator==(A aux);
};

A &A::operator=(string n) {
	nome = n;
	return *this;
}

A &A::operator+=(A aux) {
	A brandnew;
	brandnew.n = this->n + aux.n;
	return brandnew;
}

bool A::operator==(A aux) {
	if(this->n==aux.n)
		if (this->nome==aux.nome)
		{
			return true;
		}
	return false;
}
void main() {
	A x, y, z;

	x = "texto";
	x += (y += z);

}


//TESTE 2 POO 2012/2013

#include <iostream>

using namespace std;

class coordenada {
	int x, y;
public:
	coordenada() { x = 0; y = 0; }
	coordenada(int px, int py) { x = px; y = py; }
	int inline get_x() const { return x; }
	int inline get_y() const { return y; }
	void inline set_x(int px) { x = px; }
	void inline set_y(int py) { y = py; }

};


class rectangulo {
coordenada supesq, infdir;
public:
rectangulo(int a, int b, int c, int d) {
		supesq.set_x(a);
		supesq.set_y(b);
		infdir.set_x(c);
		infdir.set_y(d);
	}
};


int main() {
	//coordenada pos[10];

	coordenada a(1, 2);
	coordenada b(3, 4);
	coordenada c(5, 6);

	rectangulo rec(2, 3, 4, 1);

	a = b = c;

	cout << "x= " << a.get_x() << "./" << a.get_y() << "." << endl
		 << "x= " << b.get_x() << "./" << b.get_y() << "." << endl
		 << "x= " << c.get_x() << "./" << c.get_y() << "." << endl;

	return 0;
}




// TESTE 1 POO 2012/2013
#include <string>
#include <iostream>

using namespace std;

class animalestimacao {
	string nome;
	int numpatas;
	int vacinas;
	
public:
	animalestimacao() { vacinas = 0; }
	animalestimacao(string n, int np) { nome = n; numpatas = np; vacinas = 0; }
	string get_nome() inline const{return this->nome;}
	int get_npatas() inline const{return this->numpatas;}
	int get_vacinas() inline const{return this->vacinas;}
	void inline set_vacinas(int x) {vacinas = vacinas + x;}
};

void vacinaanimal(animalestimacao *a) {
	a->set_vacinas(1);
}

void main() {
	animalestimacao cao("tejo", 4);
	vacinaanimal(&cao);
	cout << cao.get_nome() << " / " << cao.get_npatas() << " / " << cao.get_vacinas() << endl;

}

