#include <vector>
#include <string>
#include <iostream>


using namespace std;


//As laranjas podem também cair da Arvore, assumindo - se que desaparecem
//(i.e., ao cair da árvore as laranjas morrem e desaparecem).
//
// os frutos não existem fora da arvore
// a relacao entre arvore e frutos e COMPOSICAO, posse exclusiva

// a hierarquia de frutos tem que ter as funcoes duplica()

// a arvore tem que ter 
//      construtor por copia, 
//      operador atribuicao e 
//      destrutor

class Fruto
{

	float peso;
	static int conta;
	int id;

public:

	Fruto(float p) : id(conta++), peso(p) {}

	float getPeso() const
	{
		return peso;
	}

	void setPeso(float peso)
	{
		this->peso = peso;
	}

	int getId() const
	{
		return id;
	}
	void aumentaPeso(float fator) {  // encapsulamento, esta classe tem o peso
		peso *= fator;
	}

	virtual void crescer() = 0;
	///// duplica abstrata nesta classe que tem que ser abstrata por causa de crescer ser abstrata
	// nao seria possivel fazer new Fruto, por isso duplica tem que ser abstrata

	virtual Fruto * duplica()const = 0;
};

class Limao : public Fruto
{

public:

	Limao() : Fruto(150) {};
	void crescer() override {
		//setPeso(getPeso() * 1.5);
		aumentaPeso(1.5);  // encapsulamento
	}
	Fruto * duplica() const override{
		return new Limao(*this);
	}
};

class Laranja : public Fruto
{

public:

	Laranja() : Fruto(100) {}
	void crescer() {
		//setPeso(getPeso() * 1.1);
		aumentaPeso(1.1);  // encapsulamento
	}
	Fruto * duplica() const override {
		return new Laranja(*this);
	}
};

int Fruto::conta = 1;


class Arvore {

	vector<Fruto*> fruta;

public:

	Arvore() = default;

	// destrutor
	~Arvore() {
		for (Fruto * f : fruta) {
			delete f;
		}
	}

	// operador atribuicao
	Arvore & operator=(const Arvore & ob) {
		// testar auto atribuicao
		if (this == &ob) {
			return *this;
		}
		// limpar memoria usada pelo primeiro membro
		for (Fruto * f : fruta) {
			delete f;
		}
		fruta.clear();// esvaziar o vector que aponta para memoria ja libertada

		// copiar duplicando o segundo membro
		for (Fruto * f : ob.fruta) {
			fruta.push_back(f->duplica());
		}
		return *this;
	}


	// construtor por copia
	Arvore(const Arvore & ob) {
		// nao ha ponteiros com lixo de memoria
		// que seja preciso por a null
		*this = ob;
	}

	void nascer(Fruto* x) { fruta.push_back(x->duplica()); } // a arvore cria os seus frutos, assim como os destroi

	void cair(int x) {
		for (int i = 0; i < fruta.size(); i++)
			if (fruta[i]->getId() == x) {
				delete fruta[i]; // liberta a memoria apontada por fruta[i], porque se terata de composição
				fruta.erase(fruta.begin() + i);  // retira do vector o ponteiro que aponta para memoria ja libertada
				return;
			}
	}
	void crescer() {
		for (int i = 0; i < fruta.size(); i++)
			fruta[i]->crescer();
	}
	int getTotal() const { return fruta.size(); }
	Fruto* getFruto(int i) const { return fruta[i]; }
};
// Mostra o id e peso de todos os frutos da Arvore
ostream& operator<<(ostream& out, Arvore& a) {
	for (int i = 0; i < a.getTotal(); i++)
		out << a.getFruto(i)->getId() << " " << a.getFruto(i)->getPeso() << endl;
	return out;
}
//int main() {
//	Arvore a;
//	Fruto* f = new Laranja();
//	Fruto* l = new Limao();
//
//	a.nascer(f);
//	a.nascer(l);
//
//	Arvore b = a;
//	b.nascer(f);
//	cout << "depois de const por copia" << endl;
//	cout << b << endl;
//
//	a = b;
//	cout << "depois de atrib" << endl;
//	cout << a << endl;
//	a.cair(1);
//	cout << a << endl;
//	a.crescer();
//	cout << a << endl; // Nesta altura deve estar apenas 1 fruto na Arvore com Id 2 e peso 110
//
//
//	getchar();
//}



