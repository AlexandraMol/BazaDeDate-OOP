#include "TABELA_INPUT.h"
#include "TABELA.h"
using namespace std;

class Menu
{
	string comanda;
	int alegere = 0;
	string options;
public:
	void menu()
	{	
		TABELA* A = new TABELA[10];

		TABELA_INPUT* B = new TABELA_INPUT[30];

		TABELA C[10];
		cout << "Pentru a parasi baza de date tastati de 2 ori EXIT"<<endl;
		int nr_de_col;
		string valoare;
		string nume_tabela2;
		string nume_tabela;
		string tabela;
		string comanda;
		int ok;
		int x=0;
		string nume_coloana[30];
		string tip_coloana[30];
		int dimensiune[30];
		do
		{

			/*A[0].nume_tabela = "x";
			A[0].numar_coloane = 3;
			string vectori_test[3] = { "NUME","PRENUME","VARSTA" };
			A[0].numar_tip_coloana = 3;
			string vectori_test2[3] = { "VARCHAR","VARCHAR","INTEGER" };
			int dim[3] = { 1,2,3 };
			A[0].CREATE_TABLE(A + 0,"x", vectori_test, 3, vectori_test2, 3, dim);*/

		
			//cout << endl;
			string vectori_valori[3] = { "ANA","MARIA","21"};


			comanda = "";
			tabela = "";
			cin >> comanda;
			cin >> ws;
			cin >> tabela;
			if (comanda=="CREATE"&&tabela=="TABLE")
			{
				nume_tabela = "";
				cin >> nume_tabela;
				
			
			
				for (int i = x; i < 10; i++)
				{
					if (A[i].nume_tabela == nume_tabela)
					{
						cout << "Aceasta tabela este deja creata";
						break; /// sa se iasa din for
					}

					else if (A[i].nume_tabela == "")
					{
						///aici se creaza noua tabela;
						
						cout << "Cate coloane doriti sa aiba tabela? ";
						cin >> nr_de_col;
						
						for (int j = 0; j < nr_de_col; j++)
						{	
							cin >> nume_coloana[j];
							cin >> tip_coloana[j];
							cin >> dimensiune[j];
						}

						A[i].CREATE_TABLE(A + i, A[i].nume_tabela, nume_coloana, nr_de_col, tip_coloana, nr_de_col, dimensiune);
						x++;
						break;
					}

				}
					
			}
			

	
			//A[0].DISPLAY(A + 0, "STUD");

			//A[0].DROP_TABLE(A + 0);

			if (comanda == "DISPLAY" && tabela == "TABLE")
			{
				
				cin >> nume_tabela2;
				ok = 0;
				for (int i = 0; i < 10; i++)
				{	
					
					if (A[i].nume_tabela == nume_tabela2)
					{
						A[i].DISPLAY(A + i, nume_tabela2);	
						ok = 1; 
					}
					
					
				}
				if (ok == 0)
					cout << "Nu s-a gasit tabela ceruta";
			}
			

			if (comanda == "DROP" && tabela == "TABLE")
			{
				nume_tabela = "";
				cin >> nume_tabela;
				int ok = 0;
				for (int i = 0; i < 10; i++)
				{
					if (A[i].nume_tabela == nume_tabela)
					{
						A[i].DROP_TABLE(A + i);
						ok = 1; i = 10;
					}


				}
				if (ok == 0)
					cout << "Nu s-a gasit tabela ceruta";
			}



		} while (comanda!="EXIT");

		for (int i = 0; i < 10; i++)
			cout << A[i];
	}
};



int main()
{
	Menu x;
	x.menu();

	////TABELA* A = new TABELA[2];

	////A[1].setNume_Tabela("x");
	////A[1].DISPLAY(A + 1, "x");

	//
	////string D[3] = { "NUME","PRENUME","VARSTA" };

	//////cout << T1.nume_coloana[1] << endl;
	//////cout << T1;
	//TABELA* A = new TABELA[10];
	//
	//string vectori_test[3] = { "NUME","PRENUME","VARSTA" };
	//
	//string vectori_test2[3] = { "VARCHAR","VARCHAR","INTEGER" };
	//int dim[3] = { 1,2,3 };
	//A[3].CREATE_TABLE(A + 3, "x", vectori_test, 3, vectori_test2, 3, dim);
	//cout <<A[3];

	//
	//	string **array = new string*[2];

	//	for (int i = 1; i <= 2; ++i)
	//		array[i] = new string[3];
	//

	//	
	//		
	//	TABELA_INPUT X(array, 3, 2, A + 3);
	//	cout << X;

	//string B[3] = { "VARCHAR","VARCHAR","INTEGER" };

	//int vector[3] = { 3,3,3 };

	//TABELA* A = new TABELA[3];


	//A[1] = TABELA(D, 3, B, 3, vector);

	//A[1].DISPLAY(A + 1,"student");

	//cout << endl;

	//A[2].CREATE_TABLE(A + 2,"elev", D, 3, B, 3, vector);

	//cout << A[2];
	//cout << endl;

	/////A[1].DROP_TABLE(A + 1);



	//cout << endl;
	//cout << "Verificari pentru tabela_input" << endl;

	//string valori[3] = { "M","A","20" };

	//TABELA_INPUT* tabela_input = new TABELA_INPUT[3];

	//

	//tabela_input[1] = TABELA_INPUT(valori, 3, A + 1);
	//cout << tabela_input[1]<<endl;

	/////TESTARE SELECT
	//string up[1] = { "NUME" };
	//tabela_input[1].SELECT_COLOANA(tabela_input + 1, up, 1);
	//cout << endl;
	//string select[3] = { "VARSTA","NUME","PRENUME" };
	//tabela_input[1].SELECT_COLOANA(tabela_input + 1, select, 3);


	/////TESTARE UPDATE;

	//tabela_input[1].UPDATE(tabela_input + 1, A + 1, "ANI", "VARSTA");
	//cout << tabela_input[1];
	//cout << endl;


	/////TESTARE DELETE
	//tabela_input[1].DELETE_COLOANA(tabela_input + 1, "NUME");
	//cout << tabela_input[1];
	//cout << endl;
	//
	/////TESTARE INSERT
	//
	//string valori2[3] = { "M","A","20" };
	//tabela_input[1].INSERT_COLOANA(tabela_input + 1, valori2, 3);



}
