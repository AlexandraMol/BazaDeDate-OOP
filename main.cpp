#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
#include <iostream>
#include "TABELA_INPUT.h"
#include "TABELA.h"
#include <vector>
#include <list>
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


		cout << "Pentru a parasi baza de date tastati EXIT" << endl;

		list <TABELA> lista;

		string var_delete2;
		string var_delete;
		int ok_delete;
		int ok2;
		int num;
		string from;
		stringstream a;
		string filename[10];
		string filename_b[10];
		ofstream files_b[10];
		ofstream files[10];
		ofstream rs[20];
		int contor = 0;
		string nume_nou;
		string filename_rs[20];
		string nume;
		string nume_tab;
		int nr_de_col;
		string valoare;
		string nume_tabela2;
		string nume_tabela;
		string tabela;
		string comanda;
		string vector_select[10];
		string valori_implicite[10];
		string numar;
		int verificare;
		string var;
		int ok;
		int x = 0;
		string nume_coloana[30];
		string tip_coloana[30];
		int dimensiune[30];
		do
		{
			comanda = "";
			tabela = "";
			cout << "Tastati o comanda" << endl;
			cin >> comanda;
			cin >> ws;
			cin >> tabela;
			if (comanda == "CREATE" && tabela == "TABLE")
			{


				verificare = 0;
				nume_tabela = "";
				cin >> nume_tabela;


				for (int i = 0; i < 10; i++)
				{
					if (A[i].nume_tabela == nume_tabela)
					{
						cout << "Aceasta tabela este deja creata" << endl;
						i = 11;
						verificare = 1;
					}
				}
				if (verificare == 0)
				{
					for (int i = x; i < 10; i++)
					{


						if (A[i].nume_tabela == "")
						{
						

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


							}



							nume_tab = to_string(i);

							filename[i] = "tabela_" + nume_tab;

							filename[i] += ".txt";

							cout << "Tabela " << nume_tabela << " a fost creata" << endl;
							cout << "Fisierul " << filename[i] << " a fost creat" << endl;


							filename_b[i] = "fisier_binar_tabela" + nume_tab;
							filename_b[i] += ".bin";

							cout << "Fisierul " << filename_b[i] << " a fost creat" << endl;

							A[i].serializare(filename_b[i], files_b[i]);
							files[i].open(filename[i].c_str(), ios::out );

							files[i] << A[i];

							files[i].close();

							x++;



							break;
						}

					}

				}


			}
			else
				if (comanda == "CREATE" && tabela != "TABLE")
					cout << "Eroare: Comanda scrisa gresit. Lipsa cuvantului TABLE" << endl;


			if (comanda == "DISPLAY" && tabela == "TABLE")
			{

				cin >> nume_tabela2;
				ok = 0; ok2 = 0;
				for (int i = 0; i < 10; i++)
				{

					if (A[i].nume_tabela == nume_tabela2)
					{
						A[i].DISPLAY(A + i, nume_tabela2);
						for (int j = i; j < 100; j = j + 10)
						{
							if (B[j].valori_rand[0] == "0")
							{
								ok2 = 1;
							}
							else
							{
								
								B[j].DISPLAY_INPUT(B + j, nume_tabela2);

							}

							if (ok2 == 1)
							{
								j = 100;
							}

						}
						ok = 1;
					}


				}
				if (ok == 0)
					cout << "Nu s-a gasit tabela ceruta" << endl;

				cout << endl;

			}
			else
				if (comanda == "DISPLAY" && tabela != "TABLE")
					cout << "Eroare: Comanda scrisa gresit. Lipsa cuvantului TABLE" << endl;
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
						cout << "Fisierul " << filename[i] << " a fost sters." << endl;
						cout << "Fisierul " << filename_b[i] << " a fost sters." << endl;
						remove(filename[i].c_str());
						remove(filename_b[i].c_str());
						ok = 1; i = 10;

					}


				}
				if (ok == 0)
					cout << "Nu s-a gasit tabela ceruta";
				cout << endl;

			}
			else if (comanda == "DROP" && tabela != "TABLE")
				cout << "Eroare: Comanda scrisa gresit. Lipsa cuvantului TABLE" << endl;


			if (comanda == "SELECT" && tabela == "FROM")
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
							

							for (int j = i; j < 100; j = j + 10)
							{
								if (B[j].valori_rand[0] == "0")
								{
									j = 100;
								}
								else
								{
									B[j].SELECT_COLOANA(B + j, vector_select, A[i].numar_coloane);
									cout << endl;

								}
							}


						}
						else
						{

							cout << "Ce coloane afisati: " << endl;
							for (int j = 0; j < stoi(numar); j++)
							{
								cin >> vector_select[j];
							}

							for (int j = i; j < 100; j = j + 10)
							{
								if (B[j].valori_rand[0] == "0")
								{
									j = 100;
								}
								else
								{
									B[j].SELECT_COLOANA(B + j, vector_select, A[i].numar_coloane);
									cout << endl;
								}

							}

						}

					}
				}


			}

			else if (comanda == "SELECT" && tabela != "FROM")
			{
				cout << "Eroare: Comanda scrisa gresit. Lipsa cuvantului FROM" << endl;
			}
			if (comanda == "DELETE" && tabela == "FROM")
			{
				ok_delete = 0;
				nume_tabela = "";

				cin >> nume_tabela;

				cin >> var_delete;

				cin >> var_delete2;

				cin >> numar;

				if (var_delete != "WHERE")
					cout << "Comanda DELETE a fost scrisa gresit. Eroare la cuvantul " << var_delete << endl;
				else if (var_delete2 != "COLOANA=")
					cout << "Comanda DELETE a fost scrisa gresit. Eroare la cuvantul " << var_delete2 << endl;
				else
				{



					for (int i = 0; i < 10; i++)
					{
						if (nume_tabela == A[i].nume_tabela)
						{



							files[i].open(filename[i].c_str(), ios::out | ios::trunc);
							files[i].open(filename_b[i].c_str(), ios::out | ios::trunc);
							files[i].close();




							for (int j = i; j < 100; j = j + 10)
							{


								B[j].DELETE_COLOANA(B + j, numar);

								if (B[j].valori_rand[0] != "0")
								{
									files[i].open(filename[i].c_str(), ios::out | ios::app);
									B[j].serializare(filename_b[i], files_b[i]);
									
									files[i] << B[j];
									files[i].close();
								}


							}


							A[i].REDIMENSIONARE(A + i, numar);
							cout << "Comanda DELETE s-a efectuat cu succes." << endl;

							i = 11;
						}
						if (nume_tabela != A[i].nume_tabela && i == 9)
							cout << "Nu s-a gasit tabela cautata" << endl;
					}
				}
			}

			else if (comanda == "DELETE" && tabela != "FROM")
			{
				cout << "Eroare: Comanda scrisa gresit. Lipsa cuvantului FROM" << endl;
			}

			if (comanda == "UPDATE" && tabela == "SET")
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

						
						cout << "Cu ce valoare schimbati?" << endl;
						cin >> nume;
						files[i].open(filename[i].c_str(), ios::out | ios::trunc);
						files[i].open(filename_b[i].c_str(), ios::out | ios::app);
						files[i].close();
						for (int j = i; j < 100 && B[j].valori_rand[0] != "0"; j = j + 10)
						{
							B[j].UPDATE(B + j, A + i, nume, nume_tabela2, numar);
							files[i].open(filename[i].c_str(), ios::out | ios::app);

							B[j].serializare(filename_b[i], files_b[i]);
							files[i] << A[i] << endl;
							files[i] << B[j] << endl;
							files[i].close();

							i = 12;
						}
					}
					if (A[i].nume_tabela != nume_tabela && i == 9)
						cout << "Tabela cautata nu exista" << endl;
				}
			}

			if (comanda == "INSERT" && tabela == "INTO")
			{

				ok = 0;
				nume_tabela = "";
				cin >> nume_tabela;
				cin >> var;
				for (int i = 0; i < 10; i++)
				{


					if (nume_tabela == A[i].nume_tabela && var == "VALUES")
					{
						for (int j = 0; j < A[i].numar_coloane; j++)
						{
							cin >> valori_implicite[j];

						}



						for (int j = i; j < 100; j = j + 10)
						{
							if (B[j].valori_rand[0] == "0")
							{


								B[j].INSERT_COLOANA(B + j, valori_implicite, A[i].numar_coloane);
								if (B[j].valori_rand[0] != "0")
								{
									files[i].open(filename[i].c_str(), ios::out | ios::app);
									B[j].serializare(filename_b[i], files_b[i]);
									files[i] << endl;
									files[i] << B[j] << endl;

									files[i].close();
									ok = 1;
									i = 100;
									cout << "Functia INSERT s-a efectuat cu succes." << endl;
								}
								else {
									j = 100;
								}
							}
							if (ok == 1)
							{
								break; j = 100;
							}
						}

					}

				}
			}

			if (comanda == "RENAME" && tabela == "TABLE")
			{
				nume_tabela = "";

				cin >> nume_tabela;
				for (int i = 0; i < 10; i++)
				{
					if (nume_tabela == A[i].nume_tabela)
					{

						cin >> ws;
						cin >> nume_nou;
						A[i].RENAME(A + i, nume_nou);
						cout << A[i] << endl;
						i = 10;
					}

					if (i == 9 && nume_tabela != A[i].nume_tabela)
					{
						cout << "Tabela pe care o cautati nu exista";
					}
				}

			}
			else if (comanda == "RENAME" && tabela != "TABLE")
			{

				cout << "Eroare: lipsa cuvantului TABLE" << endl;
			}







		} while (comanda != "EXIT");



	}


};

class Raport
{
public:
	virtual void afis()
	{
		cout << "Raport" << endl;
	}
	virtual void afiseaza() = 0;
	virtual void nume_af() = 0;

};

class Display : public Raport
{
private:
	int numar_coloane = 0;
	vector<string> nume_coloana = {};
	int numar_tip_coloana = 0;
	vector<string> tip_coloana = {};
	int* dimensiune = nullptr;
	string nume = "";

public:

	Display()
	{
		nume_coloana = {};
		numar_coloane = 0;
		tip_coloana = {};
		numar_tip_coloana = 0;
		dimensiune = nullptr;
		nume = "";
	}

	Display(vector<string> nume_coloana, int numar_coloane, vector<string> tip_coloana, int numar_tip_coloana, int* dimensiune, string nume)
	{
		if (!nume_coloana.empty() && numar_coloane > 0)
		{
			this->numar_coloane = numar_coloane;
			//this->nume_coloana = new string[numar_coloane];
			for (unsigned i = 0; i < numar_coloane; i++)
			{
				this->nume_coloana[i] = nume_coloana[i];
			}
		}

		if (!tip_coloana.empty() && numar_tip_coloana > 0)
		{
			this->numar_tip_coloana = numar_tip_coloana;
			//this->tip_coloana = new string[numar_tip_coloana];
			for (unsigned i = 0; i < numar_tip_coloana; i++)
			{
				this->tip_coloana[i] = tip_coloana[i];
			}
		}

		this->tip_coloana = tip_coloana;
		this->numar_tip_coloana = numar_tip_coloana;
		this->dimensiune = dimensiune;
		this->nume = nume;
	}

	void nume_af() override
	{
		cout << nume << " " << endl;
	}

	void afiseaza() override
	{
		for (int i = 0; i < numar_coloane; i++)
			cout << nume_coloana[i] << " " << tip_coloana[i] << " " << dimensiune[i] << endl;
	}

};



class Select : public Raport
{
private:
	string** valori_rand = nullptr;
	vector<string> coloane = {};
	int numar = 0;
	int numar_coloane = 0;
	vector<string> nume_coloana = {};
	string nume = nullptr;
	int dim = 0;
	int dim_randuri = 0;

public:

	Select()
	{
		valori_rand = nullptr;
		coloane = {};
		numar = 0;
		nume_coloana = {};
		numar_coloane = 0;
		nume = nullptr;
		dim = 0;
		dim_randuri = 0;
	}

	Select(string** valori_rand, vector<string> coloane, int numar, vector<string> nume_coloana, int numar_coloane, int dim, string nume, int dim_randuri)
	{
		if (!nume_coloana.empty() && numar_coloane > 0)
		{
			this->numar_coloane = numar_coloane;
			//this->nume_coloana = new string[numar_coloane];
			for (unsigned i = 0; i < numar_coloane; i++)
			{
				this->nume_coloana[i] = nume_coloana[i];
			}
		}

		if (dim > 0 && dim_randuri > 0)
		{
			this->dim = dim;
			this->dim_randuri = dim_randuri;
			this->valori_rand = new string * [dim];
			for (int i = 0; i < dim; i++)
			{
				this->valori_rand[i] = new string[this->dim_randuri];
			}
		}

		if (!coloane.empty() && numar > 0)
		{
			this->numar = numar;
			//this->coloane = new string[numar];
			for (unsigned i = 0; i < numar; i++)
			{
				this->coloane[i] = coloane[i];
			}
		}

		this->nume = nume;
	}

	void nume_af() override
	{
		cout << nume << " " << endl;
	}

	void afiseaza() override
	{
		for (int i = 0; i < numar; i++)
		{
			for (int j = 0; j < numar_coloane; j++)
			{
				if (coloane[i] == nume_coloana[j])
				{
					cout << coloane[i] << " " << endl;
					cout << valori_rand[j] << endl;
				}
			}
		}
	}
};



int main()
{
	Menu x;

	x.menu();

	Raport* r = new Display;
	r->afiseaza();

}
