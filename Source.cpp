#include <iostream>
#include <cstring>
#define NULL 0 
using namespace std;


/// pentru clasa CREATE TABLE

class TABELA
{ ///nume_coloană_1, tip, dimensiune, valoare_implicită
/// NUME VARCHAR, DIMENSIUNE(20) 'POPESCU'
	public:


		string nume_coloana;
		string tip_coloana;
		int dimensiune;
		///valoare implicita?

		TABELA() ///Setare valoare implicita
		{
			nume_coloana = "";
			tip_coloana = "";
			dimensiune = 0;
		}

		///constructor copiere
		TABELA(const TABELA& tab)
		{
			nume_coloana = tab.nume_coloana;
			tip_coloana = tab.tip_coloana;
			dimensiune = tab.dimensiune;
		}

		///operator=
		TABELA& operator=(const TABELA& tab)
		{
			nume_coloana = tab.nume_coloana;
			tip_coloana = tab.tip_coloana;
			dimensiune = tab.dimensiune;
		}
		
		///de completat
		///DISPLAY? e operator << scrisa ca o metoda care sa afiseze campurile. ///Alexandra
		

		///operator << ///Luiza
		///operator >> ///Luiza
	


};

class INDEX:public TABELA
{
public:
TABELA:nume_coloana;
		INDEX() ///Setare valoare implicita
		{
			nume_coloana = "";
			
		}

		///constructor copiere
		INDEX(const INDEX& ind)
		{
			nume_coloana = ind.nume_coloana;
		}

		///operator=
		INDEX& operator=(const INDEX& ind)
		{
			nume_coloana = ind.nume_coloana;
		}
};


///CLASELE CHILD CA FIIND CREATE , DROP DISPLAY.

///CLASA DERIVATA TABELA-INDEXATA.


int main()
{
	TABELA X;
	
	X.dimensiune = 10;
	X.nume_coloana = "NUME";
	X.tip_coloana = "VARCHAR";
	
	cout << X.dimensiune;
	
	
	///CREATE TABLE:
	/// scrii create table enter numele tabelei enter cate coloane vrei(sau daca vrei sa continui sau renunti) enter dupa fiecare
	
	///sa afiseze ca s-a creat TABELA

	return 0;
}
