#include <iostream>
#include <string>
#include "TABELA_INPUT.h"
#include<fstream>

using namespace std;

TABELA_INPUT::TABELA_INPUT()
{
	valori_rand = nullptr;
	dim = 0;
}


TABELA_INPUT::~TABELA_INPUT()
{
	if (valori_rand != nullptr)
		delete[] valori_rand;
}

TABELA_INPUT::TABELA_INPUT(const TABELA_INPUT& tab) :TABELA(tab)
{

	if (tab.valori_rand != nullptr && tab.dim > 0)
	{
		this->dim = tab.dim;
		this->valori_rand = new string[tab.dim];

		for (int i = 0; i < tab.dim; i++)
		{
			this->valori_rand[i] = tab.valori_rand[i];
		}

	}
	else
	{
		this->valori_rand = nullptr;
		this->numar_coloane = 0;
	}
}

TABELA_INPUT& TABELA_INPUT::operator=(const TABELA_INPUT& tab)
{
	TABELA::operator=(tab);

	if (this->valori_rand != nullptr)
	{
		delete[] this->valori_rand;
	}

	this->valori_rand = new string[tab.dim];

	if (tab.valori_rand != nullptr && tab.dim > 0)
	{
		this->dim = tab.dim;

		for (int i = 0; i < tab.dim; i++)
		{
			this->valori_rand[i] = tab.valori_rand[i];
		}
	}

	else
	{
		this->valori_rand = nullptr;
		this->dim = 0;
	}

	return *this;
}
string* TABELA_INPUT::getValori_rand()
{
	if (valori_rand != NULL)
	{
		string* copie = new string[dim];
		for (int i = 0; i < dim; i++)
		{
			copie[i] = valori_rand[i];
		}
		return copie;
	}
	else
	{
		return NULL;
	}
}

void TABELA_INPUT::setValori_rand(string* valori_rand, int dim)
{
	if (valori_rand != NULL && dim != 0)
	{
		this->dim = dim;
		if (this->valori_rand != NULL)
		{
			delete[] this->valori_rand;
		}
		this->valori_rand = new string[dim];
		for (int i = 0; i < dim; i++)
		{
			this->valori_rand[i] = valori_rand[i];
		}
	}
}
TABELA_INPUT::TABELA_INPUT(string* valori_rand, int dim, TABELA* x)

{

	if (x->nume_coloana != NULL && x->numar_coloane > 0)
	{
		this->numar_coloane = x->numar_coloane;
		this->nume_coloana = new string[x->numar_coloane];
		for (int i = 0; i < x->numar_coloane; i++)
		{
			this->nume_coloana[i] = x->nume_coloana[i];
		}
	}

	this->dimensiune = x->dimensiune;
	if (x->tip_coloana != nullptr && x->numar_tip_coloana > 0)
	{
		this->numar_tip_coloana = x->numar_tip_coloana;
		this->tip_coloana = new string[x->numar_tip_coloana];
		for (int i = 0; i < x->numar_tip_coloana; i++)
		{
			this->tip_coloana[i] = x->tip_coloana[i];
		}
	}

	if (valori_rand != NULL && dim > 0)
	{
		this->dim = dim;
		this->valori_rand = new string[dim];
		for (int i = 0; i < dim; i++)
		{
			this->valori_rand[i] = valori_rand[i];
		}
	}

}

void TABELA_INPUT::DISPLAY_INPUT(TABELA_INPUT* D, string nume_tabela)
{
	//for (int i = 0; i < D->numar_coloane; i++)
	//	cout << D->nume_coloana[i] << " ";
	//cout << endl;
	for (int i = 0; i < dim; i++)
	{
		cout << D->valori_rand[i] << " ";
	}
	cout << endl;
}


void TABELA_INPUT::UPDATE(TABELA_INPUT* x, TABELA* tab, string nume, string coloanaDeSchimbat, string valoare)
{
	for (int i = 0; i < x->numar_coloane; i++)
	{
		if (x->nume_coloana[i] == coloanaDeSchimbat)
		{

			if (x->valori_rand[i] == valoare)
			{
				x->valori_rand[i] = nume;
			}


		}
	}

	cout << "TABLE UPDATED" << endl;
}

void TABELA_INPUT::INSERT_COLOANA(TABELA_INPUT* x, string* valori_adaugate, int dimensiune)
{
	int k = 0;
	if (dimensiune != x->numar_coloane)
	{
		cout << "Numarul de valori nu indeplineste numarul de coloane ale tabelei" << endl;
		k++;

	}
	else
	{
		for (int i = 0; i < dimensiune; i++)
		{
			if (x->tip_coloana[i] == "VARCHAR" && valori_adaugate[i].length() <= x->dimensiune[i])
			{
				x->valori_rand[i] = valori_adaugate[i];

			}
			else if (x->tip_coloana[i] == "VARCHAR" && valori_adaugate[i].length() > x->dimensiune[i])
			{
				cout << "Valorea adauga nu indeplineste dimensiunea prestabilita de tip VARCHAR" << endl;
				k++;

			}

			if (x->tip_coloana[i] == "NUMBER")
			{
				int var;
				var = stoi(valori_adaugate[i].c_str());
				int number = 0;
				while (var != 0)
				{
					var = var / 10;
					number++;
				}

				if (x->tip_coloana[i] == "NUMBER" && number > x->dimensiune[i])
				{
					cout << "Valorea adauga nu indeplineste dimensiunea prestabilita de NUMBER" << endl;
					k++;

				}
				else
				{
					x->valori_rand[i] = valori_adaugate[i];
				}

			}


		}
	}

}
void TABELA_INPUT::SELECT_COLOANA(TABELA_INPUT* x, string* coloane, int numar)
{
	for (int i = 0; i < numar; i++)
	{
		for (int j = 0; j < x->numar_coloane; j++)
		{
			if (coloane[i] == x->nume_coloana[j])
			{
				cout << coloane[i] << " " << endl;
				cout << x->valori_rand[j] << endl;
			}
		}
	}
	cout << endl;
}
void TABELA_INPUT::DELETE_COLOANA(TABELA_INPUT* x, string nume)
{
	for (int i = 0; i < x->numar_coloane; i++)
	{

		if (x->nume_coloana[i] == nume)
		{
			for (int p = i; p < x->numar_coloane - 1; p++)
			{
				x->nume_coloana[p] = x->nume_coloana[p + 1];
				x->tip_coloana[p] = x->tip_coloana[p + 1];
				x->valori_rand[p] = x->valori_rand[p + 1];

			}
			x->numar_coloane--;
			x->numar_tip_coloana--;
			x->dim--;
		}
	}
	
}

void TABELA_INPUT::serializare(string file, ofstream& g)
{
	g.open(file, ios::binary | ios::app);
	g.write((char*)&dim, sizeof(dim));
	for (int i = 0; i < dim; i++)
	{
		g.write((char*)&valori_rand[i], sizeof(valori_rand[i]));
	}
	g << endl;
	g.close();
}


void TABELA_INPUT::deserializare()
{
	ifstream g("tabela.bin", ios::binary);
	g.read((char*)&dim, sizeof(dim));
	delete[] valori_rand;
	valori_rand = new string[dim];
	for (int i = 0; i < dim; i++)
	{
		g.read((char*)&valori_rand[i], sizeof(valori_rand[i]));
	}
}

ostream& operator<<(ostream& o, TABELA_INPUT tab)
{
	if (tab.valori_rand != nullptr)
	{
		for (int i = 0; i < tab.dim; i++)
			o << tab.valori_rand[i] << " ";
	}

	return o;
}

istream& operator>>(istream& i, TABELA_INPUT& tab)
{

	i >> (TABELA&)tab;

	cout << "Numar de coloane: ";
	i >> tab.dim;

	if (tab.valori_rand != nullptr)
	{
		delete[] tab.valori_rand;
	}
	cout << "Valorile de pe rand: ";

	if (tab.dim > 0)
	{
		tab.valori_rand = new string[tab.dim];
		for (int j = 0; j < tab.dim; j++)
		{
			i >> tab.valori_rand[j];
		}

	}
	else
	{
		tab.dim = 0;
		tab.valori_rand = nullptr;
	}


	return i;
}

ofstream& operator<<(ofstream& o, TABELA_INPUT tab)
{

	if (tab.valori_rand != nullptr)
	{
		for (int i = 0; i < tab.dim; i++)
			o << tab.valori_rand[i] << " ";
	}
	else
	{
		o << "N/A";
	}

	return o;
}

ifstream& operator>>(ifstream& i, TABELA_INPUT& tab)
{

	i >> (TABELA&)tab;

	cout << "Numar de coloane: ";
	i >> tab.dim;

	if (tab.valori_rand != nullptr)
	{
		delete[] tab.valori_rand;
	}
	cout << "Valorile de pe rand: ";

	if (tab.dim > 0)
	{
		tab.valori_rand = new string[tab.dim];
		for (int j = 0; j < tab.dim; j++)
		{
			i >> tab.valori_rand[j];
		}

	}
	else
	{
		tab.dim = 0;
		tab.valori_rand = nullptr;
	}


	return i;
}
