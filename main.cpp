#include <fstream>
#include <sstream>
#include <iostream>
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

		TABELA_INPUT* B = new TABELA_INPUT[100];

		
		cout << "Pentru a parasi baza de date tastati de 2 ori EXIT"<<endl;
		string filename;

		ofstream files;
		string nume;
		int nr_de_col;
		string valoare;
		string nume_tabela2;
		string nume_tabela;
		string tabela;
		string comanda;
		string vector_select[10];
		string valori_implicite[10];
		string numar;
		string var;
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
							valori_implicite[j] = "0";

						}



						A[i].nume_tabela = nume_tabela;
						A[i].CREATE_TABLE(A + i, A[i].nume_tabela, nume_coloana, nr_de_col, tip_coloana, nr_de_col, dimensiune);


						for (int j = x; j < 100; j = j + 10)
						{
							B[j] = TABELA_INPUT(valori_implicite, nr_de_col, A + i);
							//cout << B[j] << endl;
							//cout << j<<endl;
						}
						
						stringstream a;

						a << i;

						filename = "tabela_" + a.str();

						filename += ".txt";

						cout << filename << endl;


						///de implementantat pentru n files;
						A[i].serializare();
						

						files.open(filename.c_str(), ios::out);

						files << A[i];

						files.close();

						x++;

						

						break;
					}

				}
					
			}
			
		

			else if (comanda == "DISPLAY" && tabela == "TABLE")
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
			

			else if (comanda == "DROP" && tabela == "TABLE")
			{
				nume_tabela = "";
				cin >> nume_tabela;
				int ok = 0;
				for (int i = 0; i < 10; i++)
				{
					stringstream a;

					a << i;
					if (A[i].nume_tabela == nume_tabela)
					{
						A[i].DROP_TABLE(A + i);
						remove(filename.c_str());
						
						ok = 1; i = 10;
					}


				}
				if (ok == 0)
					cout << "Nu s-a gasit tabela ceruta";
				cout << endl;
			}

			else if (comanda == "SELECT"&&tabela=="FROM")
			{
				nume_tabela = "";
				cout << "Cate coloane doriti sa afisati: " << endl;
				cin >> numar;
				cout << "Numele tabelei: " << endl;
				cin >> nume_tabela;
				for (int i = 0; i < 10; i++)
				{
					if (A[i].nume_tabela == nume_tabela)
					{
						if (numar == "ALL")
						{
							for (int j = 0; j < A[i].numar_coloane; j++)
							{
								vector_select[j] = A[i].nume_coloana[j];
							}
							///sa implementez pentru fiecare rand in parte, nu uita sa comentezi in TABELA_input sa se afis doar valorile.

							for (int j = i; j < 100; j = j + 10)
							{
								B[j].SELECT_COLOANA(B + j, vector_select, A[i].numar_coloane);
								cout << endl;
								cout << B[j];
							}

							
						}
						else
						{
							cout << "Ce coloane afisati: " << endl;
							for (int j = 0; j < stoi(numar); j++)
							{
								cin >> vector_select[j];
							}
							///sa implementez pentru fiecare rand in parte, nu uita sa comentezi in TABELA_input sa se afis doar valorile.
							///de verificat daca se afiseaza bine;
							for (int j = i; j < 100; j = j + 10)
							{
								B[j].SELECT_COLOANA(B + j, vector_select, A[i].numar_coloane);
								cout << endl;
								cout << B[j];
							}

						}
						
					}
				}
				
				
			}
			
			else if (comanda == "DELETE" && tabela == "FROM")
			{
				nume_tabela = "";
				cout << "Numele tabelei: " << endl;
				cin >> nume_tabela;
				for (int i = 0; i < 10; i++)
				{
					if (nume_tabela == A[i].nume_tabela)
					{
						cout << "Ce coloana vreti sa stergeti?"<<endl;
						cin >> numar;
						for (int j = i; j < 100; j = j + 10)
						{
							files.open(filename.c_str(), ios::out | ios::app);
							B[j].DELETE_COLOANA(B + j, numar);
							
							//ne gandim; 


			/*				cout << endl;
							cout << B[j];*/
						}

					}
				}
			}

			else if (comanda == "UPDATE" && tabela == "SET")
			{
				nume_tabela = "";
				cout << "Numele tabelei: " << endl;
				cin >> nume_tabela;
				for (int i = 0; i < 10; i++)
				{
					if (nume_tabela == A[i].nume_tabela)
					{
						cout << "Ce valoare din ce coloana vrei sa schimbi?" << endl;
						cin >> numar;
						cin >> ws;
						cin >> nume_tabela2;

						///de verificat dupa insert daca merge;
						cout << "Cu ce valoare schimbati?" << endl;
						cin >> nume;
						for (int j = i; j < 100; j = j + 10)
						{
							B[j].UPDATE(B + j, A + i, nume, nume_tabela2, numar);

							cout << B[j]<<endl;
						}
					}
				}
			}

			else if (comanda == "INSERT" && tabela == "INTO")
			{
				ok = 0;
				nume_tabela = "";
				cin >> nume_tabela;
				cin >> var;
				for (int i = 0; i < 10; i++)
				{	


					if (nume_tabela == A[i].nume_tabela&&var=="VALUES")
					{
						for (int j = 0; j < A[i].numar_coloane; j++)
						{
							cin >> valori_implicite[j];
							
						}
						
						
						for (int j = i; j < 100; j = j + 10)
						{
							if (B[j].valori_rand[0] =="0")
							{	
								///de vazut cum se face pentru a modifica un file specific;
								files.open(filename.c_str(), ios::out | ios::app);
								B[j].INSERT_COLOANA(B + j, valori_implicite, A[i].numar_coloane);
								
								files << endl;
								files << B[j]<<endl;
								
								files.close();
								ok = 1;
								//cout << B[j];
								//cout << endl;
								//cout << j;
							}
							if (ok == 1)
							{
								break; j = 100;
							}
						}
						
					}
					
				}
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

}
