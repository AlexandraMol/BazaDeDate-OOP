#include "TABELA.h"
#include "TABELA_INPUT.h"
#include <iostream>
#include <string>
using namespace std;


string* TABELA::getNume_Coloana()
{
	if (nume_coloana != NULL)
	{
		string* copie = new string[numar_coloane];
		for (int i = 0; i < numar_coloane; i++)
		{
			copie[i] = nume_coloana[i];
		}
		return copie;
	}
	else
	{
		return NULL;
	}
}

string* TABELA::getTip_coloana()
{
	if (tip_coloana != NULL)
	{
		string* copie = new string[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			copie[i] = tip_coloana[i];
		}
		return copie;
	}
	else
	{
		return NULL;
	}
}

int* TABELA::getDimensiune()
{
	if (dimensiune != NULL)
	{
		int* copie = new int[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			copie[i] = dimensiune[i];
		}
		return copie;
	}
	else
	{
		return NULL;
	}
}

void TABELA::setNume_Coloana(string* nume_coloana, int numar_coloane, string* tip_coloana, int numar_tip_coloana, int* dimensiune)
{
	if (nume_coloana != NULL && numar_coloane != 0)
	{
		this->numar_coloane = numar_coloane;
		if (this->nume_coloana != NULL)
		{
			delete[] this->nume_coloana;
		}
		this->nume_coloana = new string[numar_coloane];
		for (int i = 0; i < numar_coloane; i++)
		{
			this->nume_coloana[i] = nume_coloana[i];
		}
	}

	if (tip_coloana != NULL && numar_tip_coloana != 0)
	{
		this->numar_tip_coloana = numar_tip_coloana;
		if (this->tip_coloana != NULL)
		{
			delete[] this->tip_coloana;
		}
		this->tip_coloana = new string[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			this->tip_coloana[i] = tip_coloana[i];
		}
	}
	if (dimensiune != NULL && numar_tip_coloana != 0)
	{
		this->numar_tip_coloana = numar_tip_coloana;
		if (this->dimensiune != NULL)
		{
			delete[] this->dimensiune;
		}
		this->dimensiune = new int[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			this->dimensiune[i] = dimensiune[i];
		}
	}
}

TABELA::TABELA()
{
	nume_coloana = nullptr;
	numar_coloane = 0;
	tip_coloana = nullptr;
	numar_tip_coloana = 0;
	dimensiune = nullptr;
	nume_tabela = "";
}

TABELA::~TABELA()
{
	if (nume_coloana != nullptr)
		delete[] nume_coloana;
	if (tip_coloana != nullptr)
		delete[] tip_coloana;
	if (dimensiune != nullptr)
		delete[] dimensiune;
}

TABELA::TABELA(const TABELA& tab)
{	
	this->nume_tabela = tab.nume_tabela;
	if (tab.dimensiune != nullptr && tab.numar_coloane != 0)
	{
		this->numar_coloane = tab.numar_coloane;
		this->dimensiune = new int[tab.numar_tip_coloana];
		for (int i = 0; i < tab.numar_tip_coloana; i++)
		{
			this->dimensiune[i] = tab.dimensiune[i];
		}
	}
	else
	{
		this->dimensiune = nullptr;
		this->numar_tip_coloana = 0;
	}

	if (tab.nume_coloana != NULL && tab.numar_coloane > 0)
	{
		this->numar_coloane = tab.numar_coloane;
		this->nume_coloana = new string[tab.numar_coloane];

		for (int i = 0; i < tab.numar_coloane; i++)
		{
			this->nume_coloana[i] = tab.nume_coloana[i];
		}
	}
	else
	{
		this->nume_coloana = nullptr;
		this->numar_coloane = 0;
	}

	if (tab.tip_coloana != NULL && tab.numar_tip_coloana > 0)
	{
		this->numar_tip_coloana = tab.numar_tip_coloana;
		this->tip_coloana = new string[tab.numar_tip_coloana];

		for (int i = 0; i < tab.numar_tip_coloana; i++)
		{
			this->tip_coloana[i] = tab.tip_coloana[i];
		}
	}

}

TABELA::TABELA(string* nume_coloana, int numar_coloane, string* tip_coloana, int numar_tip_coloana, int* dimensiune)
{
	
	if (nume_coloana != NULL && numar_coloane > 0)
	{
		this->numar_coloane = numar_coloane;
		this->nume_coloana = new string[numar_coloane];
		for (int i = 0; i < numar_coloane; i++)
		{
			this->nume_coloana[i] = nume_coloana[i];
		}
	}

	if (dimensiune != nullptr && numar_coloane != 0)
	{
		this->numar_coloane = numar_coloane;
		this->dimensiune = new int[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			this->dimensiune[i] = dimensiune[i];
		}
	}

	if (tip_coloana != nullptr && numar_tip_coloana > 0)
	{
		this->numar_tip_coloana = numar_tip_coloana;
		this->tip_coloana = new string[numar_tip_coloana];
		for (int i = 0; i < numar_tip_coloana; i++)
		{
			this->tip_coloana[i] = tip_coloana[i];
		}
	}
}

TABELA& TABELA::operator=(const TABELA& tab)
{
	this->nume_tabela = tab.nume_tabela;
	if (dimensiune != nullptr)
	{
		delete[] dimensiune;
	}
	this->dimensiune = new int[tab.numar_tip_coloana];
	if (this->nume_coloana != nullptr)
	{
		delete[] this->nume_coloana;
	}
	this->nume_coloana = new string[tab.numar_coloane];
	if (this->tip_coloana != nullptr)
	{
		delete[] this->tip_coloana;
	}
	this->tip_coloana = new string[tab.numar_tip_coloana];

	if (tab.dimensiune != nullptr && tab.numar_tip_coloana != 0)
	{
		this->numar_coloane = tab.numar_coloane;
		this->dimensiune = new int[tab.numar_tip_coloana];
		for (int i = 0; i < tab.numar_tip_coloana; i++)
		{
			this->dimensiune[i] = tab.dimensiune[i];
		}
	}
	else
	{
		this->dimensiune = nullptr;
		this->numar_tip_coloana = 0;
	}

	if (tab.nume_coloana != nullptr && tab.numar_coloane > 0)
	{
		this->numar_coloane = tab.numar_coloane;

		this->nume_coloana = new string[tab.numar_coloane];
		for (int i = 0; i < tab.numar_coloane; i++)
		{
			this->nume_coloana[i] = tab.nume_coloana[i];
		}
	}
	else
	{
		this->nume_coloana = nullptr;
		this->numar_coloane = 0;
	}

	if (tab.tip_coloana != nullptr && tab.numar_tip_coloana > 0)
	{
		this->numar_tip_coloana = tab.numar_tip_coloana;

		this->tip_coloana = new string[tab.numar_tip_coloana];
		for (int i = 0; i < tab.numar_tip_coloana; i++)
		{
			this->tip_coloana[i] = tab.tip_coloana[i];
		}
	}
	else
	{
		this->tip_coloana = nullptr;
		this->numar_tip_coloana = 0;
	}
	return *this;
}



void TABELA::CREATE_TABLE(TABELA* obj,string nume_tabela, string* nume_coloana, int numar_coloane, string* tip_coloana, int numar_tip_coloana, int* dimensiune)
{
	if (numar_coloane < 1 || numar_tip_coloana < 1)
	{
		cout << "Tabela nu poate fi creata deoarece nu sunt suficiente coloane";
	}
	else
	{
		obj->nume_tabela = nume_tabela;
		if (nume_coloana != NULL && numar_coloane > 0)
		{
			obj->numar_coloane = numar_coloane;
			obj->nume_coloana = new string[numar_coloane];
			for (int i = 0; i < numar_coloane; i++)
			{
				obj->nume_coloana[i] = nume_coloana[i];
			}
		}

		if (dimensiune != nullptr && numar_coloane != 0)
		{
			obj->numar_coloane = numar_coloane;
			obj->dimensiune = new int[numar_tip_coloana];
			for (int i = 0; i < numar_tip_coloana; i++)
			{
				obj->dimensiune[i] = dimensiune[i];
			}
		}

		if (tip_coloana != nullptr && numar_tip_coloana > 0)
		{
			obj->numar_tip_coloana = numar_tip_coloana;
			obj->tip_coloana = new string[numar_tip_coloana];
			for (int i = 0; i < numar_tip_coloana; i++)
			{
				obj->tip_coloana[i] = tip_coloana[i];
			}
		}
		cout << "TABLE CREATED";
	}
}
string TABELA::getNume_Tabela()
{
	return nume_tabela;
}
void TABELA::setNume_Tabela(string nume_tabela)
{
	this->nume_tabela = nume_tabela;
}
void TABELA::DROP_TABLE(TABELA* obj)
{

	delete[] obj->nume_coloana;
	delete[] obj->tip_coloana;
	delete[] obj->dimensiune;

	obj->nume_tabela = "";
	obj->numar_coloane = 0;
	obj->numar_tip_coloana = 0;

	cout << "TABLE DROPPED";
}

void TABELA::DISPLAY(TABELA* tabela,string nume_tabela)
{
	for (int i = 0; i < tabela->numar_coloane; i++)
		cout << tabela->nume_coloana[i] << " " << tabela->tip_coloana[i] << " " << tabela->dimensiune[i] << endl;
}

void TABELA::serializare()
{
	ofstream f("tabela.bin",ios::binary);
	int lenght = nume_tabela.length();
	f.write((char*)&lenght, sizeof(lenght));
	f.write(nume_tabela.c_str(), lenght + 1);
	f.write((char*)&numar_coloane, sizeof(numar_coloane));
	for (int i = 0; i < numar_coloane; i++)
	{
		f.write((char*)&nume_coloana[i], sizeof(nume_coloana[i]));
	}
	f.write((char*)&numar_tip_coloana, sizeof(numar_tip_coloana));
	for (int i = 0; i < numar_tip_coloana; i++)
	{
		f.write((char*)&tip_coloana[i], sizeof(tip_coloana[i]));
	}
	for (int i = 0; i < numar_tip_coloana; i++)
	{
		f.write((char*)&dimensiune[i], sizeof(dimensiune[i]));
	}
	f.close();
}

void TABELA::deserializare()
{
	ifstream f("tabela.bin", ios::binary);
	int length = 0;
	f.read((char*)&length, sizeof(length));
	char* aux = new char[length + 1];
	f.read(aux, length + 1);
	nume_tabela = aux;
	delete[] aux;
	f.read((char*)&numar_coloane, sizeof(numar_coloane));
	delete[] nume_coloana;
	nume_coloana = new string[numar_coloane];
	for (int i = 0; i < numar_coloane; i++)
	{
		f.read((char*)&nume_coloana[i], sizeof(nume_coloana[i]));
	}
	f.read((char*)&numar_tip_coloana, sizeof(numar_tip_coloana));
	delete[] tip_coloana;
	tip_coloana = new string[numar_tip_coloana];
	for (int i = 0; i < numar_tip_coloana; i++)
	{
		f.read((char*)&tip_coloana[i], sizeof(tip_coloana[i]));
	}
	delete[] dimensiune;
	dimensiune = new int[numar_tip_coloana];
	for (int i = 0; i < numar_tip_coloana; i++)
	{
		f.read((char*)&dimensiune[i], sizeof(dimensiune[i]));
	}
	
}


ostream& operator<<(ostream& o, TABELA tab)
{
	o << "Nume tabela ";
	o<< tab.nume_tabela << endl;
	o << "Numar de coloane: ";
	o << tab.numar_coloane << endl;

	if (tab.nume_coloana != nullptr)
	{
		for (int i = 0; i < tab.numar_coloane; i++)
			o << tab.nume_coloana[i] << " ";
	}


	o << "Numar tip coloane: ";
	o << tab.numar_tip_coloana << endl;


	if (tab.tip_coloana != nullptr)
	{
		for (int i = 0; i < tab.numar_tip_coloana; i++)
			o << tab.tip_coloana[i] << " ";

	}

	if (tab.dimensiune != nullptr)
	{
		for (int i = 0; i < tab.numar_coloane; i++)
		{
			o << tab.dimensiune[i] << " ";
		}
	}

	return o;
}



istream& operator>>(istream& in, TABELA& tab)
{
	cout << "Nume tabela ";
	in >> tab.nume_tabela;
	cout << "Numar coloane: ";
	in >> tab.numar_coloane;

	if (tab.nume_coloana != nullptr)
	{
		delete[] tab.nume_coloana;
	}
	if (tab.numar_coloane > 0)
	{
		tab.nume_coloana = new string[tab.numar_coloane];
		for (int i = 0; i < tab.numar_coloane; i++)
		{
			cout << "Nume coloana[" << i << "]= ";
			in >> tab.nume_coloana[i];
		}
	}
	else
	{
		tab.numar_coloane = 0;
		tab.nume_coloana = nullptr;
	}

	if (tab.tip_coloana != nullptr)
	{
		delete[] tab.tip_coloana;
	}
	if (tab.numar_tip_coloana > 0)
	{
		tab.tip_coloana = new string[tab.numar_tip_coloana];
		for (int i = 0; i < tab.numar_tip_coloana; i++)
		{
			cout << "Tip coloana[" << i << "]= ";
			in >> tab.tip_coloana[i];
		}
	}
	else
	{
		tab.numar_tip_coloana = 0;
		tab.tip_coloana = nullptr;
	}
	if (tab.dimensiune != nullptr)
	{
		delete[] tab.dimensiune;
	}
	if (tab.dimensiune > 0)
	{
		tab.dimensiune = new int[tab.numar_tip_coloana];
		for (int i = 0; i < tab.numar_coloane; i++)
		{
			cout << "Dimensiune[" << i << "]= ";
			in >> tab.dimensiune[i];
		}
	}
	else
	{
		tab.numar_coloane = 0;
		tab.dimensiune = NULL;
	}

	return in;
}

