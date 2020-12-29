
#include <iostream>
#include <string>
#include "TABELA.h"
using namespace std;

class TABELA_INPUT : public TABELA
{
	friend class Menu;
public:
	string* valori_rand = nullptr; 
	int dim = 0;
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
	void UPDATE(TABELA_INPUT*, TABELA*, string, string);
	void INSERT_COLOANA(TABELA_INPUT*, string*, int);
	friend ostream& operator<<(ostream&, TABELA_INPUT);
	friend istream& operator>>(istream&, TABELA_INPUT&);


private:

};
