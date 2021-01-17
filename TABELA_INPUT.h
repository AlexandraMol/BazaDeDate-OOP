#include <iostream>
#include <string>
#include "TABELA.h"
using namespace std;

class TABELA_INPUT : public TABELA
{
	friend class Menu;

public:

	TABELA tabela;
	TABELA_INPUT();
	~TABELA_INPUT();
	TABELA_INPUT(const TABELA_INPUT&);
	TABELA_INPUT& operator=(const TABELA_INPUT&);
	TABELA_INPUT(string*, int, TABELA*);
	void SELECT_COLOANA(TABELA_INPUT*, string*, int);
	void DELETE_COLOANA(TABELA_INPUT*, string);
	string* getValori_rand();
	void setValori_rand(string*, int);
	void UPDATE(TABELA_INPUT*, TABELA*, string, string, string);
	void INSERT_COLOANA(TABELA_INPUT*, string*, int);
	void serializare(string, ofstream&);
	void deserializare();
	virtual void DISPLAY_INPUT(TABELA_INPUT*, string);
	friend ostream& operator<<(ostream&, TABELA_INPUT);
	friend istream& operator>>(istream&, TABELA_INPUT&);
	friend ofstream& operator<<(ofstream&, TABELA_INPUT);
	friend ifstream& operator>>(ifstream&, TABELA_INPUT&);



private:
	string* valori_rand = nullptr;
	int dim = 0;
	
};
