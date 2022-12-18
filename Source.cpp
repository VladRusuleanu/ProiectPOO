#include<stdio.h>
#include<stdlib.h>
#include "Header.h"

string teatru1 = "Teatrul National Bucuresti";
string teatru2 = "Teatrul de Comedie";
string teatru3 = "Teatrul Odeon"; 
string teatru4 = "Teatrul Nottara";

string cinematograf1 = "Cinema Europa";
string cinematograf2 = "Happy Cinema";
string cinematograf3 = "Cinema City";
string cinematograf4 = "Hollywood Mulptiplex";

string stadion1 = "National Arena";
string stadion2 = "Steaua Stadium";
string stadion3 = "Stadionul Dinamo";
string stadion4 = "Complex Sportiv National Lia Manoliu";

void Functie_De_Scriere()
{
	FILE* F;
	int Nr_Locuri[9] = {150, 100, 50, 140, 90, 40, 150, 100, 50};
	fopen_s(&F, "Fisier.dat", "wb");
	if (F != NULL)
	{
		cout << "\nS-a deschis fisierul!\n";
		fwrite(&Nr_Locuri, sizeof(int) * 9, 1, F);
		fclose(F);
	}
	else
	{
		cout << "\nNu s-a deschis fisierul!";
	}
}

void Citire_Fisier()
{
	int Numere_Locuri[9];
	FILE* F;
	fopen_s(&F, "Fisier.dat", "rb");
	if (F != NULL)
	{
		fread(Numere_Locuri, sizeof(int) * 9, 1, F);
		cout << "\n Numerul de locuri ramase din Cateogoria 1, 2 si Loja, in ordine, sunt: ";
		for (int i = 0; i < 9; i++)
			cout << Numere_Locuri[i];
		cout << endl;
		fclose(F);
	}
	else
	{
		cout << "\nFisierul nu s-a putut deschide!\n";
	}
}

bool Verificare_Lungime_Nr_Telefon(long Numar_de_Telefon)
{
	int i = 0;
	do
	{
		Numar_de_Telefon = Numar_de_Telefon / 10;
		i++;
	}while (Numar_de_Telefon > 0);
	if (i == 8)
		return true;
	else
		return false;
}

bool Verificare_Litere(string Litera)
{
	char ch[10] = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++)
		if (Litera.find(ch[i]) != string::npos)
			return false;
}

int main()
{
	int categoria_aleasa, aproximativ, r = 0;
	int nr_locuri[9], nr_locuri_film[9], nr_locuri_fotbal[9];
	string nume, nume_teatru, nume_stadion, nume_cinematograf;
	long long nrTelefon = 0;
	bool verificare = false;

Nume:

	cout << "\nCare va fi numele de pe bilet?\n";
	getline(cin, nume);

	verificare = Verificare_Litere(nume);
	if (verificare == false)
	{
		system("CLS");
		cout << "\nVa rugam sa introduceti doar litere!\n";
		goto Nume;
	}

Telefon:

	cout << "\nCare este numarul dumneavoastra de telefon? (fara prefixul 07)\n";
	cin >> nrTelefon;
	if (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	verificare = Verificare_Lungime_Nr_Telefon(nrTelefon);
	if (verificare == false)
	{
		system("CLS");
		cout << "\nNumarul de telefon pe care introdus nu este corect!\nVa rugam introduceti din nou!\n";
		goto Telefon;
	}

Eveniment:

	cout << "\nLa ce eveniment doriti sa mergeti?\n";
	cout << "\n1. Meci de Fotbal\n";
	cout << "\n2. Film\n";
	cout << "\n3. Piesa de teatru\n";
	fflush(stdin);
	cin >> categoria_aleasa;
	if (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (categoria_aleasa == 1)
	{
	Nume_Stadion:

		cout << "\nLa ce stadion doriti sa mergeti? (National Arena, Steaua Stadium, Stadionul Dinamo, Complex Sportiv National Lia Manoliu)\n";
		getline(cin, nume_stadion);
		verificare = Verificare_Litere(nume_stadion);
		if (verificare == false)
		{
			system("CLS");
			cout << "\nVa rugam sa introduceti doar litere.\n";
			goto Nume_Stadion;
		}
		if (nume_stadion == stadion1 || nume_stadion == stadion2 || nume_stadion == stadion3 || nume_stadion == stadion4)
		{
		}
		else
		{
			cout << "\nStadionul introdus nu face parte din lista de stadioane disponibile\n";
			goto Nume_Stadion;
		}
	Operatie2:
		cout << "\nDoriti sa mergeti la un meci de fotbal? (Tastati 1 pentru da sau 0 pentru nu)\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (categoria_aleasa == 1)
		{
			FILE* F3;
			int Nr_Locuri_Fotbal[9] = {150, 100, 50, 140, 90, 40, 150, 100, 50};
			fopen_s(&F3, "Fisier3.dat", "wb");
			if (F3 != NULL)
			{
				cout << "\nS-a deschis fisierul!\n";
				fwrite(&Nr_Locuri_Fotbal, sizeof(int) * 9, 1, F3);
				fclose(F3);
			}
			else
				cout << "\nNu s-a deschis fisierul!";
		}
		else if (categoria_aleasa != 1 && categoria_aleasa != 0)
		{
			system("CLS");
			cout << "\nNumarul dat nu face parte din operatiile date\n";
			goto Operatie2;
		}
		FILE* F3;
		fopen_s(&F3, "Fisier3.dat", "rb");
		if (F3 != NULL)
		{
			fread(nr_locuri_fotbal, sizeof(int) * 9, 1, F3);
			cout << "\n Numerul de locuri ramase din Tribuna 1, Tribuna 2 si Peluza, in ordine, sunt: ";
			for (int i = 6; i < 9; i++)
				cout << nr_locuri_fotbal[i] << endl;
			fclose(F3);
		}
		else
			cout << "\nFisierul nu s-a putut deschide!\n";
	main3:
		cout << "\nBuna ziua! Ce tip de bilet doriti?\n";
		cout << "\nTastati numarul corespunzator tipului de bilet dorit: \n\n1.Bilet Tribuna 1 1\n\n2.BIlet Tribuna 2\n\n3.Bilet Peluza\n\n4.Aflare informatii despre stadionul de fotbal (Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate) \n\n5.Incheiere Program\n\nCostul unui bilet de Tribuna 1 este de 30 de lei\nCostul unui bilet de Tribuna 2 este de 60 de lei\nCostul unui bilet pentru Peluza este de 120 de lei\n\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Fotbal BFO;
		if (categoria_aleasa == 1)
		{
			aproximativ = nr_locuri_fotbal[0] / 10;
			if (nr_locuri_fotbal[0] / 10 >= 1 && nr_locuri_fotbal[6] > 1)
			{
				if (nr_locuri_fotbal[0] / 10 == 15 || nr_locuri_fotbal[0] / 10 == 1)
				{

					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[0] - nr_locuri_fotbal[3]);
					nr_locuri_fotbal[3]++;
					nr_locuri_fotbal[6]--;

				}
				else if (nr_locuri_fotbal[3] == 149 || nr_locuri_fotbal[3] == 9)
				{
					nr_locuri_fotbal[3]++;
					BFO.setRand(aproximativ);
					BFO.setLoc((nr_locuri_fotbal[0] + 19) - nr_locuri_fotbal[3]);
					nr_locuri_fotbal[3] = 1;
					nr_locuri_fotbal[6]--;
				}
				else if (nr_locuri_fotbal[0] % 10 == 0)
				{
					BFO.setRand(aproximativ - 1);
					BFO.setLoc(nr_locuri_fotbal[0] - (aproximativ * 10));
					nr_locuri_fotbal[0]--;
					nr_locuri_fotbal[6]--;
				}
				else
				{
					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[0] - (aproximativ * 10));
					nr_locuri_fotbal[0]--;
					nr_locuri_fotbal[6]--;
				}
				BFO.set_NR_telefon(nrTelefon);
				BFO.set_NR_consoane(nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Filmul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(nume) << " si are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Tribuna 1 la randul : " << BFO.getRand() << " si locul : " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_1:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dori bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu )\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main3;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare3_1;
				}
			}
		}
		else if (categoria_aleasa == 2)
		{
			aproximativ = nr_locuri_fotbal[1] / 10;
			if (nr_locuri_fotbal[1] / 10 >= 1 && nr_locuri_fotbal[7] > 1)
			{
				if (nr_locuri_fotbal[1] / 10 == 10 || nr_locuri_fotbal[1] / 10 == 1)
				{

					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[1] - nr_locuri_fotbal[4]);
					nr_locuri_fotbal[4]++;
					nr_locuri_fotbal[7]--;

				}
				else if (nr_locuri_fotbal[4] == 99 || nr_locuri_fotbal[4] == 9)
				{
					nr_locuri_fotbal[4]++;
					BFO.setRand(aproximativ);
					BFO.setLoc((nr_locuri_fotbal[1] + 19) - nr_locuri_fotbal[4]);
					nr_locuri_fotbal[4] = 1;
					nr_locuri_fotbal[7]--;
				}
				else if (nr_locuri_fotbal[1] % 10 == 0)
				{
					BFO.setRand(aproximativ - 1);
					BFO.setLoc(nr_locuri_fotbal[1] - (aproximativ * 10));
					nr_locuri_fotbal[1]--;
					nr_locuri_fotbal[6]--;
				}
				else
				{
					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[1] - (aproximativ * 10));
					nr_locuri_fotbal[1]--;
					nr_locuri_fotbal[7]--;
				}
				BFO.set_NR_telefon(nrTelefon);
				BFO.set_NR_consoane(nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(nume) << " si are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Tribuna 2 la randul: " << BFO.getRand() << " si locul: " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_2:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dori bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main3;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare3_2;
				}
			}
		}
		else if (categoria_aleasa == 3)
		{
			aproximativ = nr_locuri_fotbal[2] / 10;
			if (nr_locuri_fotbal[2] / 10 >= 1 && nr_locuri_fotbal[8] > 1)
			{
				if (nr_locuri_fotbal[2] / 10 == 5 || nr_locuri_fotbal[5] / 10 == 1)
				{

					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[2] - nr_locuri_fotbal[5]);
					nr_locuri_fotbal[5]++;
					nr_locuri_fotbal[8]--;

				}
				else if (nr_locuri_fotbal[5] == 49 || nr_locuri_fotbal[5] == 9)
				{
					nr_locuri_fotbal[5]++;
					BFO.setRand(aproximativ);
					BFO.setLoc((nr_locuri_fotbal[2] + 19) - nr_locuri_fotbal[5]);
					nr_locuri_fotbal[5] = 1;
					nr_locuri_fotbal[8]--;
				}
				else if (nr_locuri_fotbal[2] % 10 == 0)
				{
					BFO.setRand(aproximativ - 1);
					BFO.setLoc(nr_locuri_fotbal[2] - (aproximativ * 10));
					nr_locuri_fotbal[2]--;
					nr_locuri_fotbal[8]--;
				}
				else
				{
					BFO.setRand(aproximativ);
					BFO.setLoc(nr_locuri_fotbal[2] - (aproximativ * 10));
					nr_locuri_fotbal[2]--;
					nr_locuri_fotbal[8]--;
				}
				BFO.set_NR_telefon(nrTelefon);
				BFO.set_NR_consoane(nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(nume) << " are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti pe Peluza la randul: " << BFO.getRand() << " si locul: " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_3:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dori bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu)\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main3;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare3_3;
				}
			}
		}
		else if (categoria_aleasa == 4)
		{
		A3:
			cout << "\nCe doriti sa aflati despre stadionul de fotbal?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului meci\n\n";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				cout << "\nNumarul total de locuri este de 300 locuri\n";
			}
			else if (r == 2)
			{
				cout << "\nNumarul total de locuri ocupate este: \n" << (300 - (nr_locuri_fotbal[6] + nr_locuri_fotbal[7] + nr_locuri_fotbal[8]));
				cout << "\nNumarul total de locuri ramase este: \n" << (nr_locuri_fotbal[6] + nr_locuri_fotbal[7] + nr_locuri_fotbal[8]);
			}
			else if (r == 3)
			{
				cout << "\nTribuna 1 are 15 randuri cu 10 scaune per rand\n";
				cout << "\nTribuna 2 are 10 randuri cu 10 scaune per rand\n";
				cout << "\nPeluza are 5 randuri cu 10 scaune per rand\n";
			}
			else if (r == 4)
			{
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << ", intre orele: " << BFO.getDurataSpectacol() << "." << endl;
			}
			else
			{
				cout << "\nValoarea introdusa nu face parte din comenzile meniului.";
				goto A3;
			}
		}
		else if (categoria_aleasa == 5)
		{
			printf("\nVa multumim pentru utilizare!\n");
			return 0;
		}
		else
		{
			cout << "\nValoarea introdusa nu face parte din lista de optiuni. Doriti sa incercati din nou? (Tastati 1 pentru da sau 0 pentru nu)";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main3;
			}
			else
			{
				cout << "\nVa multumim pentru utilizare!\n";
				return 0;
			}
		}
		fopen_s(&F3, "Fisier3.dat", "wb");
		if (F3 != NULL)
		{
			fwrite(&nr_locuri_fotbal, sizeof(int) * 9, 1, F3);
			fclose(F3);
		}
		else
		{
			printf("\nNu s-a deschis fisierul!");
		}
	}
	else if (categoria_aleasa == 2)
	{
	Nume_Cinematograf:

		cout << "\nLa ce cinematograf doriti sa mergeti? (Cinema Europa, Happy Cinema, Cinema City, Hollywood Multiplex)\n";
		getline(cin, nume_cinematograf);
		verificare = Verificare_Litere(nume_cinematograf);
		if (verificare == false)
		{
			system("CLS");
			cout << "\nVa rugam introduceti doar litere.\n";
			goto Nume_Cinematograf;
		}
		if (nume_cinematograf == cinematograf1 || nume_cinematograf == cinematograf2 || nume_cinematograf == cinematograf3 || nume_cinematograf == cinematograf4)
		{
		}
		else
		{
			cout << "\nCinematograful introdus nu face parte din lista de cinematografe disponibile\n";
			goto Nume_Cinematograf;
		}
		Operatie3:
		cout << "\nDoriti sa mergeti la un film? (Tastati 1 pentru da sau 0 pentru nu)\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (categoria_aleasa == 1)
		{
			FILE* F2;
			int Nr_Locuri_Film[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
			fopen_s(&F2, "Fisier2.dat", "wb");
			if (F2 != NULL)
			{
				cout << "\nS-a deschis fisierul!\n";
				fwrite(&Nr_Locuri_Film, sizeof(int) * 9, 1, F2);
				fclose(F2);
			}
			else
				cout <<"\nNu s-a deschis fisierul!";
		}
		else if (categoria_aleasa != 1 && categoria_aleasa != 0)
		{
			system("CLS");
			cout << "\nNumarul dat nu face parte din operatiile date\n";
			goto Operatie2;
		}
		FILE* F2;
		fopen_s(&F2, "Fisier2.dat", "rb");
		if (F2 != NULL)
		{
			fread(nr_locuri_film, sizeof(int) * 9, 1, F2);
			cout << "\n Numerele de locuri ramase din cele Normale, cele VIP si cele Ultra VIP, in ordine, sunt: ";
			for (int i = 6; i < 9; i++)
				cout << nr_locuri_film[i] << endl;
			fclose(F2);
		}
		else
			cout << "\nFisierul nu s-a putut deschide!\n";
	main2:
		cout << "\nBuna ziua! Ce tip de bilet doriti?\n";
		cout << "\nTastati numarul corespunzator tipului de bilet dorit: \n\n1.Bilet Normal 1\n\n2.Bilet VIP\n\n3.Bilet Ultra-VIP\n\n4.Aflare informatii despre sala de cinematograf (Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate) \n\n5.Incheiere Program\n\nCostul unui bilet Normal este de 30 de lei\nCostul unui bilet VIP este de 60 de lei\nCostul unui bilet Ultra VIP este de 120 de lei\n\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Film BF;
		if (categoria_aleasa == 1)
		{
			aproximativ = nr_locuri_film[0] / 10;
			if (nr_locuri_film[0] / 10 >= 1 && nr_locuri_film[6] > 1)
			{
				if (nr_locuri_film[0] / 10 == 15 || nr_locuri_film[0] / 10 == 1)
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[0] - nr_locuri_film[3]);
					nr_locuri_film[3]++;
					nr_locuri_film[6]--;
				}
				else if (nr_locuri_film[3] == 149 || nr_locuri_film[3] == 9)
				{
					nr_locuri_film[3]++;
					BF.setRand(aproximativ);
					BF.setLoc((nr_locuri_film[0] + 19) - nr_locuri_film[3]);
					nr_locuri_film[3] = 1;
					nr_locuri_film[6]--;
				}
				else if (nr_locuri_film[0] % 10 == 0)
				{
					BF.setRand(aproximativ - 1);
					BF.setLoc(nr_locuri_film[0] - (aproximativ * 10));
					nr_locuri_film[0]--;
					nr_locuri_film[6]--;
				}
				else
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[0] - (aproximativ * 10));
					nr_locuri_film[0]--;
					nr_locuri_film[6]--;
				}
				BF.set_NR_telefon(nrTelefon);
				BF.set_NR_consoane(nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(nume) << " si are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Aveti un bilet de tip Normal la randul : " << BF.getRand() << " si locul : " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2_1:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dori bilet la o alta categorie ? (Tastati 1 pentru da sau 0 pentru nu)\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main2;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare2_1;
				}
			}
		}
		else if (categoria_aleasa == 2)
		{
			aproximativ = nr_locuri_film[1] / 10;
			if (nr_locuri_film[1] / 10 >= 1 && nr_locuri_film[7] > 1)
			{
				if (nr_locuri_film[1] / 10 == 10 || nr_locuri_film[1] / 10 == 1)
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[1] - nr_locuri_film[4]);
					nr_locuri_film[4]++;
					nr_locuri_film[7]--;
				}
				else if (nr_locuri_film[4] == 99 || nr_locuri_film[4] == 9)
				{
					nr_locuri_film[4]++;
					BF.setRand(aproximativ);
					BF.setLoc((nr_locuri_film[1] + 19) - nr_locuri_film[4]);
					nr_locuri_film[4] = 1;
					nr_locuri_film[7]--;
				}
				else if (nr_locuri_film[1] % 10 == 0)
				{
					BF.setRand(aproximativ - 1);
					BF.setLoc(nr_locuri_film[1] - (aproximativ * 10));
					nr_locuri_film[1]--;
					nr_locuri_film[6]--;
				}
				else
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[1] - (aproximativ * 10));
					nr_locuri_film[1]--;
					nr_locuri_film[7]--;
				}
				BF.set_NR_telefon(nrTelefon);
				BF.set_NR_consoane(nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(nume) << " si are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Sunteti la VIP la randul: " << BF.getRand() << " si locul: " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
				reincercare2_2:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dorit alt bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu)\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main2;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare2_2;
				}
			}
		}
		else if (categoria_aleasa == 3)
		{
			aproximativ = nr_locuri_film[2] / 10;
			if (nr_locuri_film[2] / 10 >= 1 && nr_locuri_film[8] > 1)
			{	
				if (nr_locuri_film[2] / 10 == 5 || nr_locuri_film[5] / 10 == 1)
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[2] - nr_locuri_film[5]);
					nr_locuri_film[5]++;
					nr_locuri_film[8]--;
				}
				else if (nr_locuri_film[5] == 49 || nr_locuri_film[5] == 9)
				{
					nr_locuri_film[5]++;
					BF.setRand(aproximativ);
					BF.setLoc((nr_locuri_film[2] + 19) - nr_locuri_film[5]);
					nr_locuri_film[5] = 1;
					nr_locuri_film[8]--;
				}
				else if (nr_locuri_film[2] % 10 == 0)
				{
					BF.setRand(aproximativ - 1);
					BF.setLoc(nr_locuri_film[2] - (aproximativ * 10));
					nr_locuri_film[2]--;
					nr_locuri_film[8]--;
				}
				else
				{
					BF.setRand(aproximativ);
					BF.setLoc(nr_locuri_film[2] - (aproximativ * 10));
					nr_locuri_film[2]--;
					nr_locuri_film[8]--;
				}
				BF.set_NR_telefon(nrTelefon);
				BF.set_NR_consoane(nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(nume) << " are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Ultra VIP la randul: " << BF.getRand() << " si locul: " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
				reincercare2_3:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nAti dori bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu)\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main2;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam!\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare2_3;
				}
			}
		}
		else if (categoria_aleasa == 4)
		{
		A2:
			cout << "\nCe doriti sa aflati despre sala de cinematograf?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului spectacol\n\n";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
				cout << "\nNumarul total de locuri este de 300 de locuri\n";
			else if (r == 2)
			{
				cout << "\nNumarul total de locuri ocupate este: \n" << (300 - (nr_locuri_film[6] + nr_locuri_film[7] + nr_locuri_film[8]));
				cout << "\nNumarul total de locuri ramase este: \n" << (nr_locuri_film[6] + nr_locuri_film[7] + nr_locuri_film[8]);
			}
			else if (r == 3)
			{
				cout << "\nCategoria 1 are 15 randuri cu 10 scaune per rand\n";
				cout << "\nCategoria 2 are 10 randuri cu 10 scaune per rand\n";
				cout << "\nCategoria Loja are 5 randuri cu 10 scaune per rand\n";
			}
			else if (r == 4)
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
			else
			{
				cout << "\nValoarea introdusa nu face parte din comenzile meniului.";
				goto A2;
			}
		}
		else if (categoria_aleasa == 5)
		{
			cout << "\nVa multumim pentru utilizare!\n";
			return 0;
		}
		else
		{
			cout << "\nValoarea introdusa nu face parte din lista de optiuni. Doriti sa incercati din nou (Tastati 1 pentru da sau 0 pentru nu)";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main2;
			}
			else
			{
				cout << "\nVa multumim pentru utilizare!\n";
				return 0;
			}
		}
		fopen_s(&F2, "Fisier2.dat", "wb");
		if (F2 != NULL)
		{
			fwrite(&nr_locuri_film, sizeof(int) * 9, 1, F2);
			fclose(F2);
		}
		else
			cout << "\nNu s-a deschis fisierul!";
	}
	else if (categoria_aleasa == 3)
	{

		Nume_Teatru:

		cout << "\nLa ce teatru doriti sa mergeti? (Teatrul National Bucuresti, Teatrul de Comedie, Teatrul Odeon, Teatrul Nottara)\n";
		getline(cin, nume_teatru);
		verificare = Verificare_Litere(nume_teatru);
		if (verificare == false)
		{
			system("CLS");
			cout << "\nVa rugam introduceti doar litere.\n";
			goto Nume_Teatru;
		}
		if (nume_teatru == teatru1 || nume_teatru == teatru2 || nume_teatru == teatru3 || nume_teatru == teatru4)
		{
		}
		else
		{
			cout << "\nTeatrul introdus nu face parte din lista de teatre disponibile\n";
			goto Nume_Teatru;
		}

	Operatie:

		cout << "\nDoriti sa mergeti la o piesa de teatru? (Tastati 1 pentru da sau 0 pentru nu)\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (categoria_aleasa == 1)
		{
			FILE* F;
			int Nr_Locuri[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
			fopen_s(&F, "Fisier.dat", "wb");
			if (F != NULL)
			{
				cout << "\nS-a deschis fisierul!\n";
				fwrite(&Nr_Locuri, sizeof(int) * 9, 1, F);
				fclose(F);
			}
			else
				cout << "\nNu s-a deschis fisierul!";
		}
		else if (categoria_aleasa != 1 && categoria_aleasa != 0)
		{
			system("CLS");
			cout << "\nNumarul dat nu face parte din operatiile date\n";
			goto Operatie;
		}
		FILE* F;
		fopen_s(&F, "Fisier.dat", "rb");
		if (F != NULL)
		{
			fread(nr_locuri, sizeof(int) * 9, 1, F);
			cout << "\nNumerul de locuri ramase din Cateogoria 1, 2 si Loja, in ordine, sunt: ";
			for (int i = 6; i < 9; i++)
				cout << nr_locuri[i] << ' ';
			fclose(F);
		}
		else
			cout << "\nFisierul nu s-a putut deschide!\n";

	main:

		cout << "\nBuna ziua! Ce tip de bilet doriti?\n";
		cout << "\nTastati numarul corespunzator biletului dorit: \n\n1.Bilet Categorie 1\n\n2.Bilet Categorie 2\n\n3.Bilet Loja\n\n4.Aflare informatii despre sala de teatru ( Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate ) \n\n5.Incheiere Program\n\nCostul unui bilet din Categoria 1 este de 30 lei\nCostul unui bilet din Categoria 2 este de 60 lei\nCostul unui bilet din Categoria 3 este de 120 lei\n\n";
		cin >> categoria_aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Teatru BT;
		if (categoria_aleasa == 1)
		{
			aproximativ = nr_locuri[0] / 10;
			if (nr_locuri[0] / 10 >= 1 && nr_locuri[6] > 1)
			{
				if (nr_locuri[0] / 10 == 15 || nr_locuri[0] / 10 == 1)
				{

					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[0] - nr_locuri[3]);
					nr_locuri[3]++;
					nr_locuri[6]--;

				}
				else if (nr_locuri[3] == 149 || nr_locuri[3] == 9)
				{
					nr_locuri[3]++;
					BT.setRand(aproximativ);
					BT.setLoc((nr_locuri[0] + 19) - nr_locuri[3]);
					nr_locuri[3] = 1;
					nr_locuri[6]--;
				}
				else if (nr_locuri[0] % 10 == 0)
				{
					BT.setRand(aproximativ - 1);
					BT.setLoc(nr_locuri[0] - (aproximativ * 10));
					nr_locuri[0]--;
					nr_locuri[6]--;
				}
				else
				{
					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[0] - (aproximativ * 10));
					nr_locuri[0]--;
					nr_locuri[6]--;
				}
				BT.set_NR_telefon(nrTelefon);
				BT.set_NR_consoane(nume);
				BT.set_ID_bilet();
				cout << endl << "La ce teatru din " << BT.getOras() << " doriti a merge?" << endl;
				cout << nume_teatru;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de: " << BT.getData() << ", intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(nume) << ", cu numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Categoria 1, pe randul : " << BT.getRand() << ", locul: " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare1:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nDoriti bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu )\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare!\n";
					goto main;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam.\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare1;
				}
			}
		}
		else if (categoria_aleasa == 2)
		{
			aproximativ = nr_locuri[1] / 10;
			if (nr_locuri[1] / 10 >= 1 && nr_locuri[7] > 1)
			{
				if (nr_locuri[1] / 10 == 10 || nr_locuri[1] / 10 == 1)
				{

					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[1] - nr_locuri[4]);
					nr_locuri[4]++;
					nr_locuri[7]--;

				}
				else if (nr_locuri[4] == 99 || nr_locuri[4] == 9)
				{
					nr_locuri[4]++;
					BT.setRand(aproximativ);
					BT.setLoc((nr_locuri[1] + 19) - nr_locuri[4]);
					nr_locuri[4] = 1;
					nr_locuri[7]--;
				}
				else if (nr_locuri[1] % 10 == 0)
				{
					BT.setRand(aproximativ - 1);
					BT.setLoc(nr_locuri[1] - (aproximativ * 10));
					nr_locuri[1]--;
					nr_locuri[6]--;
				}
				else
				{
					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[1] - (aproximativ * 10));
					nr_locuri[1]--;
					nr_locuri[7]--;
				}
				BT.set_NR_telefon(nrTelefon);
				BT.set_NR_consoane(nume);
				BT.set_ID_bilet();
				cout << endl << "La ce teatru din " << BT.getOras() << " doriti a merge?" << endl;
				cout << nume_teatru;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de: " << BT.getData() << ", intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(nume) << ", cu numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Categoria 2, pe randul: " << BT.getRand() << ", locul: " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2:
				cout << "\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n";
				cout << "\nDoriti bilet la o alta categorie? (Tastati 1 pentru da sau 0 pentru nu )\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare!\n";
					goto main;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam.\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare2;
				}
			}
		}
		else if (categoria_aleasa == 3)
		{
			aproximativ = nr_locuri[2] / 10;
			if (nr_locuri[2] / 10 >= 1 && nr_locuri[8] > 1)
			{
				if (nr_locuri[2] / 10 == 5 || nr_locuri[5] / 10 == 1)
				{

					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[2] - nr_locuri[5]);
					nr_locuri[5]++;
					nr_locuri[8]--;

				}
				else if (nr_locuri[5] == 49 || nr_locuri[5] == 9)
				{
					nr_locuri[5]++;
					BT.setRand(aproximativ);
					BT.setLoc((nr_locuri[2] + 19) - nr_locuri[5]);
					nr_locuri[5] = 1;
					nr_locuri[8]--;
				}
				else if (nr_locuri[2] % 10 == 0)
				{
					BT.setRand(aproximativ - 1);
					BT.setLoc(nr_locuri[2] - (aproximativ * 10));
					nr_locuri[2]--;
					nr_locuri[8]--;
				}
				else
				{
					BT.setRand(aproximativ);
					BT.setLoc(nr_locuri[2] - (aproximativ * 10));
					nr_locuri[2]--;
					nr_locuri[8]--;
				}
				BT.set_NR_telefon(nrTelefon);
				BT.set_NR_consoane(nume);
				BT.set_ID_bilet();
				cout << endl << "La ce teatru din " << BT.getOras() << " doriti a merge?" << endl;
				cout << nume_teatru;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de: " << BT.getData() << ", intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(nume) << ", cu numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Loja, pe randul: " << BT.getRand() << ", locul: " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3:
				cout << "\nDoriti alt bilet la o alta categorie? (Tastati 1 pentru da say 0 pentru nu)\n";
				cin >> categoria_aleasa;
				if (categoria_aleasa == 1)
				{
					system("CLS");
					cout << "\nVa multumim pentru rabdare.\n";
					goto main;
				}
				else if (categoria_aleasa == 0)
				{
					cout << "\nNe pare rau ca nu am putut sa va ajutam.\n";
					cout << "\nVa multumim pentru utilizare!\n";
				}
				else
				{
					cout << "\nNu ati introdus o valoare posibila!\n";
					goto reincercare3;
				}
			}
		}
		else if (categoria_aleasa == 4)
		{
		A:
			cout << "\nCe doriti sa aflati despre sala de teatru?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului spectacol\n\n";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
				cout << "\nNumarul total de locuri este 300 de locuri\n";
			else if (r == 2)
			{
				cout << "\nNumarul total de locuri ocupate este: " << (300 - (nr_locuri[6] + nr_locuri[7] + nr_locuri[8])) << endl;
				cout << "\nNumarul total de locuri ramase este: " << (nr_locuri[6] + nr_locuri[7] + nr_locuri[8]) << endl;
			}
			else if (r == 3)
			{
				cout << "\nCategoria 1 are 15 randuri cu 10 scaune per rand\n";
				cout << "\nCategoria 2 are 10 randuri cu 10 scaune per rand\n";
				cout << "\nCategoria Loja are 5 randuri cu 10 scaune per rand\n";
			}
			else if (r == 4)
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de: " << BT.getData() << ", intre orele: " << BT.getDurataSpectacol() << "." << endl;
			else
			{
				cout << "\nNu ati introdus o valoare posibila!";
				goto A;
			}
		}
		else if (categoria_aleasa == 5)
		{
			cout << "\nVa multumim pentru utilizare!\n";
			return 0;
		}
		else
		{
			cout << "\nNu ati introdus o valoare posibila!" << endl << "Doriti sa incercati din nou? (Tastati 1 pentru da sau 0 pentru nu)";
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main;
			}
			else
			{
				cout << "\nVa multumim pentru utilizare!\n";
				return 0;
			}
		}
		fopen_s(&F, "Fisier.dat", "wb");
		if (F != NULL)
		{
			fwrite(&nr_locuri, sizeof(int) * 9, 1, F);
			fclose(F);
		}
		else
			cout << "\nNu s-a deschis fisierul!";
	}
	else
	{
		cout << "\nNu ati introdus o valoare posibila!\n";
		goto Eveniment;
	}
	return 0;
}
