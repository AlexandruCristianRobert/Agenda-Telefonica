#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;
class Inregistrare
{
private:
	string Nume;
	string Prenume;
	string Numar;
public:
	Inregistrare() {};
	Inregistrare(int i)
	{
		SetNume();
		SetPrenume();
		SetNumar();
	}
	void SetNume()
	{
		cout << endl;
		cin.ignore();
		cout << "Introdu numele:";
		getline(cin, Nume);
	}

	void SetPrenume()
	{
		cout << endl;
		cout << "Introdu prenumele:";
		getline(cin, Prenume);
	}

	bool VerificaContinut(const string& string)
	{
		return string.find_first_not_of("0123456789") == std::string::npos;
	}
	void SetNumar()
	{
		cout << endl;
		cout << "Introdu numarul de telefon:";
		cin.ignore();
		getline(cin, Numar);
		Numar.insert(0, "0");
		while (Numar.length() != 10 || !VerificaContinut(Numar))
		{
			cout << endl;
			cout << "Nu ati introdus un numar corect, incercati din nou:" << endl;
			cin.ignore();
			getline(cin, Numar);
		}
	}

	void Afisare()
	{
		cout << "--------------------";
		cout << endl << "Nume: " << Nume;
		cout << endl << "Prenume: " << Prenume;
		cout << endl << "Numar de telefon: "<< Numar;
		cout << endl;
	}
	string getNume()
	{
		return Nume;
	}

	string GetNumar()
	{
		return Numar;
	}
	~Inregistrare()
	{
		
	}
};


class Agenda
{
	friend Inregistrare;
private:
	Inregistrare Inreg[100];
	int NrInreg = 0;
	void StergereInregistrare(int pozitie)
	{
		Inreg[pozitie].~Inregistrare();
		for (int i = pozitie;i < NrInreg - 1;i++)
			Inreg[i] = Inreg[i + 1];
		NrInreg--;
	}
public:
	void AdaugaInregistrare()
	{
		Inregistrare x(1);
		Inreg[NrInreg++] = x;
	}
	void GasireDupaNume()
	{
		cout << "Introduceti nume sau o parte din nume:" << endl;
		string subNume;
		cin.ignore();
		getline(cin, subNume);
		bool gasit = false;
		while (true)
		{
			for (int i = 0;i < NrInreg;i++)
			{
				if (Inreg[i].getNume().find(subNume) != string::npos)
				{
					StergereInregistrare(i);
					gasit = true;
					break;
				}

			}
			if (!gasit)
			{
				cin.ignore();
				cout << "Nu ati introdus numele corect, incercati din nou." << endl;
				getline(cin, subNume);
			}
			else
				break;
		}
	}
	bool VerificaContinut(const string& string)
	{
		return string.find_first_not_of("0123456789") == std::string::npos;
	}
	void Afisare()
	{
		for (int i = 0;i < NrInreg;i++)
			 Inreg[i].Afisare();
		cout << endl;
	}
	void GasireDupaNumar()
	{
		string SubNumar;
		bool gasit = false;
		cout << "Introduceti numarul de telefon sau o parte din el:" << endl;
		cin.ignore();
		getline(cin, SubNumar);
		while (true)
		{
			while (!VerificaContinut(SubNumar))
			{
				cout << endl;
				cout << "Nu ati introdus un numar corect, incercati din nou:" << endl;
				cin.ignore();
				getline(cin, SubNumar);
			}
			for (int i = 0;i < NrInreg;i++)
			{
				if(Inreg[i].GetNumar().find(SubNumar) != string::npos)
				{
					StergereInregistrare(i);
					gasit = true;
					break;

				}
			}
			if (!gasit)
			{
				cout << endl;
				cout << "Nu ati introdus un numar corect, incercati din nou:" << endl;
				cin >> SubNumar;
			}
			else
				break;
		}
	}
	int GetNrInreg()
	{
		return NrInreg;
	}
};
int main()
{
	// Agenda poate contine maxim 100 de inregistrari
	bool oprire = false;
	Agenda a;
	int optiune;
	while (true)
	{
		system("CLS");
		cout << "------------------------Meniu------------------------" << endl;
		cout << "1)Adauga inregistrare" << endl;
		cout << "2)Sterge Inregistrare dupa nume" << endl;
		cout << "3)Sterge Inregistrare dupa numar" << endl;
		cout << "4)Afisare inregistrari" << endl;
		cout << "5)Iesire" << endl;
		cin >> optiune;
		cout << endl;
		switch (optiune)
		{
		case 1:
		{
			system("CLS");
			a.AdaugaInregistrare();
			system("pause");
		}
		break;
		case 2:
		{
			system("CLS");
			if (a.GetNrInreg() == 0)
			{
				cout << "Nu sunt inregistrari" << endl;
			}
			else
			a.GasireDupaNume();
			system("pause");
		}
		break;
		case 3:
		{
			system("CLS");
			if (a.GetNrInreg() == 0)
			{
				cout << "Nu sunt inregistrari"<<endl;
			}
			else
			a.GasireDupaNumar();
			system("pause");
		}
		break;
		case 4:
		{
			system("CLS");
			if (a.GetNrInreg() == 0)
			{
				cout << "Nu sunt inregistrari" << endl;
			}
			else
			a.Afisare();
			system("pause");
		}
		break;
		case 5:
		{
			oprire = true;
		}
		break;
		default:
			break;
		}
		if (oprire)
			break;
	}
	return  0;
}
