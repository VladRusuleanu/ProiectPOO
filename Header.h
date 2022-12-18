#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Bilete_Teatru
{
private:
	int pret;
	char* spectator;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int nr_total_locuri;
	const string oras = "Bucuresti";
	int locuri_ocupate;
	int rand;
	int loc;
	string denumire;
	string data;
	string durata_spectacol;
	friend Bilete_Teatru operator+(int valoare, Bilete_Teatru BT);
	friend Bilete_Teatru operator-(int valoare, Bilete_Teatru BT);
	friend ostream& operator<<(ostream& out, Bilete_Teatru BT);
	friend istream& operator>>(istream& in, Bilete_Teatru& BT);
public:
	Bilete_Teatru() : oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "O noapte furtunoasa";
		tip_bilet = "Categoria 1";
		data = "23.01.2003";
		durata_spectacol = "20:30 - 22:30";
		nr_total_locuri = 300;
		rand = 15;
		loc = 10;
		pret = 60;
	}

	Bilete_Teatru(const char* spectator, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int rand, int loc, string denumire, string data, string durata_spectacol, string oras) : oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->loc = loc;
		this->rand = rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_spectacol = durata_spectacol;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(spectator) + 1];
			strcpy_s(this->spectator, strlen(spectator) + 1, spectator);
		}
	}

	Bilete_Teatru(const Bilete_Teatru& s) : oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->rand = s.rand;
		this->loc = s.loc;
		this->data = s.data;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(s.spectator) + 1];
			strcpy_s(this->spectator, strlen(s.spectator) + 1, s.spectator);
		}
		else
			this->spectator = nullptr;
	}

	Bilete_Teatru& operator=(const Bilete_Teatru i)
	{
		if (this != &i)
		{
			if (spectator != nullptr)
			{
				this->spectator = new char[strlen(i.spectator) + 1];
				strcpy_s(this->spectator, strlen(i.spectator) + 1, i.spectator);
			}
			else
				this->spectator = nullptr;
		}
		return *this;
	}

	string getOras()
	{
		return oras;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return loc;
	}

	int getRand()
	{
		return rand;
	}

	void setRand(int n)
	{
		rand = n;
	}

	void setLoc(int n)
	{
		loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_spectacol;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr) 
		{
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++)
				copy[i] = spectator[i];
			return copy;
		}
		else return nullptr;
	}

	bool consoane(char ch) 
	{
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}

	void set_NR_consoane(string Nume) 
	{
		for (int i = 0; i < Nume.length(); i++)
			if (consoane(Nume[i])) 
				++nr_consoane;
	}

	void set_NR_telefon(long numar)
	{
		nr_telefon = numar;
	}

	int get_NR_consoane()
	{
		return nr_consoane;
	}

	void set_ID_bilet()
	{
		id_bilet = get_NR_telefon();
		id_bilet = id_bilet * 10 + get_NR_consoane();
	}

	long get_ID_bilet()
	{
		return id_bilet;
	}

	static void setNr_Locuri(int Nr_Total_Locuri)
	{
		Bilete_Teatru::nr_total_locuri = Nr_Total_Locuri;
	}

	static int getNr_Locuri()
	{
		return nr_total_locuri;
	}

	~Bilete_Teatru()
	{
		if (spectator != nullptr)
			delete[] this->spectator;
	}
};
int Bilete_Teatru::nr_total_locuri = 300;
Bilete_Teatru operator+(int valoare, Bilete_Teatru BT)
{
	BT.pret += valoare;
	return BT;
}
Bilete_Teatru operator-(int valoare, Bilete_Teatru BT)
{
	BT.nr_total_locuri -= valoare;
	return BT;
}
ostream& operator<<(ostream& out, Bilete_Teatru BT)
{
	out << "Numele de pe bilet este: " << BT.spectator << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BT.id_bilet;
	out << endl;
	out << "Denumirea spectacol: " << BT.denumire << endl;
	out << "Tipul biletului: " << BT.tip_bilet << endl;
	out << "Intervalul orar: " << BT.durata_spectacol << endl;
	return out;
}
istream& operator>>(istream& in, Bilete_Teatru& BT)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BT.spectator;
	return in;
}

class Bilete_Film
{
private:
	int pret;
	char* spectator1;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int nr_total_locuri1;
	const string oras = "Bucuresti";
	int locuri_ocupate;
	int rand;
	int loc;
	string denumire;
	string data;
	string durata_film;
	static char char_invalid;
	friend ostream& operator<<(ostream& out, Bilete_Film BT);
	friend istream& operator>>(istream& in, Bilete_Film& BT);
public:
	Bilete_Film() : oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "Mission: Impossible 3";
		tip_bilet = "Categoria 2";
		data = "17.08.2009";
		durata_film = "22:30 - 00:30";
		nr_total_locuri1 = 300;
		rand = 15;
		loc = 10;
		pret = 25;
	}

	Bilete_Film(const char* spectator1, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int rand, int loc, string denumire, string data, string durata_film, string oras) : oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->loc = loc;
		this->rand = rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_film = durata_film;
		if (spectator1 != nullptr)
		{
			this->spectator1 = new char[strlen(spectator1) + 1];
			strcpy_s(this->spectator1, strlen(spectator1) + 1, spectator1);
		}
	}

	Bilete_Film(const Bilete_Film& s) : oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->rand = s.rand;
		this->loc = s.loc;
		this->data = s.data;
		this->durata_film = s.durata_film;
		if (spectator1 != nullptr)
		{
			this->spectator1 = new char[strlen(s.spectator1) + 1];
			strcpy_s(this->spectator1, strlen(s.spectator1) + 1, s.spectator1);
		}
		else
			this->spectator1 = nullptr;
	}

	Bilete_Film& operator=(const Bilete_Film i)
	{
		if (this != &i)
		{
			if (spectator1 != nullptr)
			{
				this->spectator1 = new char[strlen(i.spectator1) + 1];
				strcpy_s(this->spectator1, strlen(i.spectator1) + 1, i.spectator1);
			}
			else
				this->spectator1 = nullptr;
		}
		return *this;
	}

	string getOras()
	{
		return oras;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return loc;
	}

	int getRand()
	{
		return rand;
	}

	void setRand(int n)
	{
		rand = n;
	}

	void setLoc(int n)
	{
		loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_film;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr)
		{
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++)
				copy[i] = spectator[i];
			return copy;
		}
		else return nullptr;
	}

	bool consoane(char ch)
	{
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}

	void set_NR_consoane(string Nume)
	{
		for (int i = 0; i < Nume.length(); i++)
			if (consoane(Nume[i]))
				++nr_consoane;
	}

	void set_NR_telefon(long numar)
	{
		nr_telefon = numar;
	}

	int get_NR_consoane()
	{
		return nr_consoane;
	}

	void set_ID_bilet()
	{
		id_bilet = get_NR_telefon();
		id_bilet = id_bilet * 10 + get_NR_consoane();
	}

	long get_ID_bilet()
	{
		return id_bilet;
	}

	static void setNr_Locuri(int Nr_Total_Locuri)
	{
		Bilete_Film::nr_total_locuri1 = Nr_Total_Locuri;
	}

	static int getNr_Locuri()
	{
		return nr_total_locuri1;
	}

	~Bilete_Film()
	{
		if (spectator1 != nullptr)
			delete[] this->spectator1;
	}

	bool operator!()
	{
		return pret != 0;
	}

	char& operator[](int index)
	{
		if (spectator1 != nullptr && index >= 0 && index < strlen(spectator1))
			return spectator1[index];
		else
			return char_invalid;
	}
};
int Bilete_Film::nr_total_locuri1 = 300;
char Bilete_Film::char_invalid = -1;

ostream& operator<<(ostream& out, Bilete_Film BF)
{
	out << "Numele de pe bilet este: " << BF.spectator1 << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BF.id_bilet;
	out << endl;
	out << "Denumirea spectacol: " << BF.denumire << endl;
	out << "Tipul biletului: " << BF.tip_bilet << endl;
	out << "Intervalul orar: " << BF.durata_film << endl;
	return out;
}

istream& operator>>(istream& in, Bilete_Film& BF)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BF.spectator1;
	return in;
}

class Bilete_Fotbal
{
private:
	int pret;
	char* spectator2;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int nr_total_locuri2;
	const string oras = "Bucuresti";
	int locuri_ocupate;
	int rand;
	int loc;
	string denumire;
	string data;
	string durata_meci;
	friend Bilete_Fotbal operator++(Bilete_Fotbal BM);
	friend ostream& operator<<(ostream& out, Bilete_Fotbal BM);
	friend istream& operator>>(istream& in, Bilete_Fotbal& BM);
public:
	Bilete_Fotbal() : oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "Steaua - CFR Cluj";
		tip_bilet = "Tribuna 1";
		data = "15.12.2022";
		durata_meci = "18:30 - 20:00";
		nr_total_locuri2 = 300;
		rand = 15;
		loc = 10;
		pret = 70;
	}

	Bilete_Fotbal(const char* spectator2, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int rand, int loc, string denumire, string data, string durata_meci, string oras) : oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->loc = loc;
		this->rand = rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_meci = durata_meci;
		if (spectator2 != nullptr)
		{
			this->spectator2 = new char[strlen(spectator2) + 1];
			strcpy_s(this->spectator2, strlen(spectator2) + 1, spectator2);
		}
	}

	Bilete_Fotbal(const Bilete_Fotbal& s) : oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->rand = s.rand;
		this->loc = s.loc;
		this->data = s.data;
		this->durata_meci = s.durata_meci;
		if (spectator2 != nullptr)
		{
			this->spectator2 = new char[strlen(s.spectator2) + 1];
			strcpy_s(this->spectator2, strlen(s.spectator2) + 1, s.spectator2);
		}
		else
			this->spectator2 = nullptr;
	}

	Bilete_Fotbal& operator=(const Bilete_Fotbal i)
	{
		if (this != &i)
		{
			if (spectator2 != nullptr)
			{
				this->spectator2 = new char[strlen(i.spectator2) + 1];
				strcpy_s(this->spectator2, strlen(i.spectator2) + 1, i.spectator2);
			}
			else
				this->spectator2 = nullptr;
		}
		return *this;
	}

	string getOras()
	{
		return oras;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return loc;
	}

	int getRand()
	{
		return rand;
	}

	void setRand(int n)
	{
		rand = n;
	}

	void setLoc(int n)
	{
		loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_meci;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr)
		{
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++) {
				copy[i] = spectator[i];
			}
			return copy;
		}
		else return nullptr;
	}

	bool consoane(char ch)
	{
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}

	void set_NR_consoane(string Nume)
	{
		for (int i = 0; i < Nume.length(); i++)
			if (consoane(Nume[i]))
				++nr_consoane;
	}

	void set_NR_telefon(long numar)
	{
		nr_telefon = numar;
	}

	int get_NR_consoane()
	{
		return nr_consoane;
	}

	void set_ID_bilet()
	{
		id_bilet = get_NR_telefon();
		id_bilet = id_bilet * 10 + get_NR_consoane();
	}

	long get_ID_bilet()
	{
		return id_bilet;
	}

	static void setNr_Locuri(int Nr_Total_Locuri)
	{
		Bilete_Fotbal::nr_total_locuri2 = Nr_Total_Locuri;
	}

	static int getNr_Locuri()
	{
		return nr_total_locuri2;
	}

	~Bilete_Fotbal()
	{
		if (spectator2 != nullptr)
			delete[] this->spectator2;
	}

	explicit operator int()
	{
		return pret;
	}

	Bilete_Fotbal operator--(int z)
	{
		Bilete_Fotbal copie2 = *this;
		pret--;
		return copie2;
	}

};
int Bilete_Fotbal::nr_total_locuri2 = 300;

Bilete_Fotbal operator++(Bilete_Fotbal BM)
{
	BM.pret++;
	return BM;
}

ostream& operator<<(ostream& out, Bilete_Fotbal BF)
{
	out << "Numele de pe bilet este: " << BF.spectator2 << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BF.id_bilet;
	out << endl;
	out << "Denumirea spectacol: " << BF.denumire << endl;
	out << "Tipul biletului: " << BF.tip_bilet << endl;
	out << "Intervalul orar: " << BF.durata_meci << endl;
	return out;
}

istream& operator>>(istream& in, Bilete_Fotbal& BM)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BM.spectator2;
	return in;
}