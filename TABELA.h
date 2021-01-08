#pragma once
#include <iostream>
#include <string>
#include "TABELA.h"

using namespace std;
class TABELA
{
	friend class TABELA_INPUT;
	friend class Menu;
public:

	void CREATE_TABLE(TABELA*,string, string*, int, string*, int, int*);
	string* getNume_Coloana();
	string* getTip_coloana();
	int* getDimensiune();
	string getNume_Tabela();
	void setNume_Coloana(string*, int, string*, int, int*);
	void setNume_Tabela(string);
	TABELA();
	~TABELA();
	TABELA(const TABELA&);
	TABELA(string*, int, string*, int, int*);
	TABELA& operator=(const TABELA&);
	void DROP_TABLE(TABELA*);
	void DISPLAY(TABELA*,string);
	void serializare();
	void deserializare();
	friend ostream& operator<<(ostream&, TABELA);
	friend istream& operator>>(istream&, TABELA&);
	friend ofstream& operator<<(ofstream&, TABELA);
	friend ifstream& operator>>(ifstream&, TABELA&);
	
private:
	string nume_tabela;
	int numar_coloane = 0;
	string* nume_coloana = nullptr;
	int numar_tip_coloana = 0;
	string* tip_coloana = nullptr;
	int* dimensiune = nullptr;
};

