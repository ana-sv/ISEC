// RECURSO.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <vector>
#include <string>
#include <iostream>


using namespace std;



class Excursao
{
	string data;
	const string destino;
	int lotacao;
	vector<int> inscritos;
	int passaporte;

public:

	// Criar objetos
	Excursao(string d, string dest, int l) : data(d), destino(dest), lotacao(l) {};


	string getData() const { return data; }
	void setData(string data) { this->data = data; }

	const string getDestino() const { return destino; }

	int getLotacao() const { return lotacao; }
	void setLotacao(int lotacao) { this->lotacao = lotacao; }

	vector<int> getInscritos() const { return inscritos; }
	void setInscritos(vector<int> inscritos) { this->inscritos = inscritos; }

	int getPassaporte() const { return passaporte; }
	void setPassaporte(int passaporte) { this->passaporte = passaporte; }

	// Inscrever viajantes
	Excursao& operator<< (int p)
	{
		int i = PessoasInscritas(p);

		if (i == -1)// encontrou
			return *this;
		else
			this->inscritos.push_back(i);

		return *this;


	}

	int PessoasInscritas(int pi)
	{
		for (int i : this->getInscritos())
		{
			if (pi == i)
				return -1; // encontrou
		}

		return pi;
	}

	// Transferir Passageiros
	Excursao& operator>> (Excursao &nome)
	{
		if (&nome == this)
		{
			return *this;
		}

		for (auto it = inscritos.begin(); it != inscritos.end(); )
		{
			if (nome.inscritos.size() < nome.getLotacao())
			{
				nome.inscritos.push_back(*it);
				it = inscritos.erase(it);

			}
			else
			{
				it++;
			}

		}

		return *this;
	}

	//Excursao& operator= (Excursao& nome)
	//{
	//	if (&nome == this) { return *this; }

	//	this->data = nome.data;
	//	this->lotacao = nome.lotacao;

	//	for (auto it = inscritos.begin(); it != inscritos.end();)
	//	{

	//		it = inscritos.erase(it);

	//	}

	//	this->inscritos = nome.inscritos;

	//	return *this;


	//}

	Excursao& operator= (Excursao& nome)
	{
		if (&nome == this) { return *this; }

		this->data = nome.data;
		this->lotacao = nome.lotacao;
		// como o destino é const não pode ser atribuido, muito bem

		//for (auto it = inscritos.begin(); it != inscritos.end();)
		//{

		//	it = inscritos.erase(it);

		//}
		// podia ser:
		inscritos.clear();

		//this->inscritos = nome.inscritos;  podem não caber, a lotação da exursão nome pode ser maior

		// como se transferem
		nome >> *this; // transferem-se da excrursao nome (segundo membro da atribuicao) para o primeiro membro
		// repeitando as lotacoes

		return *this;


	}

	// Este exercicios não percebi e pedi ao meu irmão para me dar uma ajuda mas não tenho a certeza disto

	int& operator[](int p) {

		static int lixo = 0;

		if (p < 0 || p >= inscritos.size()) {
			return lixo;
		}
		else
			return inscritos[p];
	}

	operator int() {

		return this->getInscritos().size();

	}
	// está bem, estão exemplos assim nos slides no capitulo dos operadores
};

ostream& operator<<(ostream& os, const Excursao& e) {

	os << "\nData: " << e.getData() << "\nDestino: " << e.getDestino()
		<< "\nLotacao: " << e.getLotacao() << "\nInscritos: " << endl;

	for (auto i : e.getInscritos()) {

		os << "\t- " << i << endl;
	}

	return os;
}



//int main() {
//
//	cout << "------------------ INICIO CRIACAO DE OBJECTOS ------------------\n\n";
//
//	Excursao e1 = Excursao("20/04/20", "Lisboa", 10);
//	Excursao e2 = Excursao("27/04/20", "Coimbra", 10);
//
//	cout << "Excursao 1: " << e1 << endl;
//	cout << "Excursao 2: " << e2 << endl;
//
//	cout << "------------------OPERADOR ATRIBUICAO DE PASSAGEIROS (OPERATOR <<) ------------------\n\n";
//
//	//Teste da atribuição dos passageiros (<<)
//	e1 << 123 << 456 << 123;
//	e2 << 789 << 987 << 789;
//
//	cout << "Excursao 1: " << e1 << endl;
//	cout << "Excursao 2: " << e2 << endl;
//
//	cout << "------------------OPERADOR PASSAGEM DE PASSAGEIROS (OPERATOR >>) ------------------\n\n";
//
//	e1 >> e2;
//	cout << "Excursao 1: " << e1 << endl;
//	cout << "Excursao 2: " << e2 << endl;
//
//	cout << "------------------OPERADOR ATRIBUICAO DE EXCURSOES (OPERATOR 😊 ------------------\n\n";
//
//	e1 = e2;
//	cout << "Excursao 1: " << e1 << endl;
//	cout << "Excursao 2: " << e2 << endl;
//
//	cout << "------------------OPERADOR SUBSTITUICAO DE PASSAGEIROS (OPERATOR []) ------------------\n\n";
//
//	e1[1] = 555;
//	cout << "Excursao 1: " << e1 << endl;
//
//	cout << "------------------OPERADOR PESQUISA DE PASSAGEIROS (OPERATOR int() ) ------------------\n\n";
//
//	int a = e1;
//
//	cout << "Numero de inscritos na e1:  " << a << endl;
//
//	getchar();
//}
//
