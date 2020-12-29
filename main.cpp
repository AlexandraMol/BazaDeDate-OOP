#include "TABELA_INPUT.h"
#include "TABELA.h"
using namespace std;

class Menu {
	string comanda;
	int alegere = 0;
	string options;
public:
	void menu()
	{
		
		TABELA* A = new TABELA[3];
		TABELA_INPUT* B = new TABELA_INPUT[3];
		cout << "Bun venit in baza noastra de date" << endl;
		do
		{

			cout << "Pentru comenzi legate de gestionarea structurii bazei de date apasati 1" << endl;
			cout << "Pentru comenzi legate de gestionarea datelor apasati 2" << endl;
			cout << "Pentru a parasi baza de date apasati 3" << endl;
			cout << "Alege un tip de comanda" << endl;
			cin >> alegere;

			switch (alegere)
			{
			case 1:
			{
				
				int alegere_tabela;

				do
				{
					cout << "Pentru CREATE TABLE tastati tasta 1" << endl;
					cout << "Pentru DISPLAY TABLE tastati tasta 2" << endl;
					cout << "Pentru DROP TABLE tastati tasta 3" << endl;
					cout << "Pentru a reveni in meniul principal tastati tasta 4" << endl;
					
					cin >> alegere_tabela;

					switch (alegere_tabela)
					{
					case 1:
					{	
					int numar;
					string table_name;
					string nume_coloana[3];
					string tip_coloana[3];
					int dimensiune[3];

					
					cout << "CREATE TABLE table_name: ";
					cin >> table_name; 
					A[1].nume_tabela=table_name;
					

					cout << "Cate coloane vreti sa aiba tabela (minim 1): ";
						cin >> numar;

						if (numar < 1)

							cout << "Numarul nu respecta conditia "<<endl;

						else
						{


							cout << "(";
							for (int i = 0; i < numar; i++)
							{
								cout << "(";
								cin >> nume_coloana[i];
								cout << ",";
								cin >> tip_coloana[i];
								cout << ",";
								cin >> dimensiune[i];
								cout << ")";
							}
							cout << ")";
							
							
							A[1].CREATE_TABLE(A + 1, A[1].nume_tabela, nume_coloana, numar, tip_coloana, numar, dimensiune);

						}
					}
					break;

					case 2:
					{
						A[1].DISPLAY(A + 1,A[1].nume_tabela);
					}
					break;

					case 3:
					{
						A[1].DROP_TABLE(A + 1);
						cout << endl;
					}
					break;

					case 4:
					{

					}
					break;

					default: cout << "Cifra pe care ati tastat-o este incorecta. Incercati din nou " << endl;
						break;
					}

				} while (alegere_tabela != 4);
			}
			break;

			case 2:
			{	int table_name;
				int alegere_date;
				do
				{	

					cout << "Pentru INSERT INTO tastati 1" << endl;
					cout << "Pentru DELETE FROM tastati 2" << endl;
					cout << "Pentru SELECT tastati 3" << endl;
					cout << "Pentru UPDATE tastati 4" << endl;
					cout << "Pentru a reveni in meniul principal tastati tasta 5" << endl;
					cin >> alegere_date;

					switch (alegere_date)
					{
					case 1:
					{	int x;
						

					}
					break;

					case 2:
					{

					}
					break;

					case 3:
					{

					}
					break;

					case 4:
					{

					}
					break;

					case 5: 
					{

					}
					break;

					break;
					default: cout << "Cifra pe care ati tastat-o este incorecta. Incercati din nou " << endl;
						break;
					}

				} while (alegere_date != 5);
			}
			break;

			case 3: {cout << "Va dorim o zi frumoasa in continuare si va multumim ca ati accesat baza noastra de date!"; }

				  break;


			default: cout << "Cifra pe care ati tastat-o este incorecta. Incercati din nou " << endl;
				break;
			}




		} while (alegere != 3);
	}
};



int main()
{
	//Menu x;
	//x.menu();

	string D[3] = { "NUME","PRENUME","VARSTA" };

	//cout << T1.nume_coloana[1] << endl;
	//cout << T1;



	string B[3] = { "VARCHAR","VARCHAR","INTEGER" };

	int vector[3] = { 3,3,3 };

	TABELA* A = new TABELA[3];


	A[1] = TABELA(D, 3, B, 3, vector);

	A[1].DISPLAY(A + 1,"student");

	cout << endl;

	A[2].CREATE_TABLE(A + 2,"elev", D, 3, B, 3, vector);

	cout << A[2];
	cout << endl;

	///A[1].DROP_TABLE(A + 1);



	cout << endl;
	cout << "Verificari pentru tabela_input" << endl;

	string valori[3] = { "M","A","20" };

	TABELA_INPUT* tabela_input = new TABELA_INPUT[3];

	

	tabela_input[1] = TABELA_INPUT(valori, 3, A + 1);
	cout << tabela_input[1]<<endl;

	///TESTARE SELECT
	string up[1] = { "NUME" };
	tabela_input[1].SELECT_COLOANA(tabela_input + 1, up, 1);
	cout << endl;
	string select[3] = { "VARSTA","NUME","PRENUME" };
	tabela_input[1].SELECT_COLOANA(tabela_input + 1, select, 3);


	///TESTARE UPDATE;

	tabela_input[1].UPDATE(tabela_input + 1, A + 1, "ANI", "VARSTA");
	cout << tabela_input[1];
	cout << endl;


	///TESTARE DELETE
	tabela_input[1].DELETE_COLOANA(tabela_input + 1, "NUME");
	cout << tabela_input[1];
	cout << endl;
	
	///TESTARE INSERT
	
	string valori2[3] = { "M","A","20" };
	tabela_input[1].INSERT_COLOANA(tabela_input + 1, valori2, 3);



}