#ifndef funkcje_H
#define funkcje_H

#include"Nag³ówek.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<Windows.h>
using namespace std;

void wstep() {
	cout << "Witaj w grze! Utworz swojego bohatera wpisujac jego nazwe lub wpisz nazwe wczesniej utworzonego bohatera." << endl;
	
	cout << "Zatwierdz wciskajac Enter. Gra zapisuje sie automatycznie." << endl;

	cout << "Celem gry jest zdobycie 10 poziomu postaci. Poziomy zdobywa sie pokonujac przeciwnkow. Powodzenia!" << endl;
}

void nowy_bohater(string n) {
	cout << "Wybierz rase postaci wpisujac odpowiednia liczbe:" << endl;
	cout << "1.Wojownik 2.Mag 3.Elf" << endl;
	string nr;
	int lvl = 1;
	int cecha;
	getline(cin, nr);
	if (nr == "1") {
		cecha = 5;
		utworz_plik(n, 1, 1, wybor2(1, 1, cecha), 5);
	}
	else {
		if (nr == "2") {
			cecha = 7;
			utworz_plik(n, 2, 1, wybor2(1, 2, cecha), 3);
		}
		else {
			if (nr == "3") {
				cecha = 6;
				utworz_plik(n, 3, 1, wybor2(1, 3, cecha), 4);
			}
			else {
				cout << "Nie poprawna liczba, sprobuj ponownie." << endl;
				nowy_bohater(n);
			}

		}
	}
}
		
void utworz_plik(string n,int r,int l, int c, int h){
		fstream plik;
		plik.open(n + ".txt", ios::out);
		if (plik.good() == true) {
			plik << n << endl << r << endl << l << endl << c << endl << h;
			plik.close();
		}
		else
		{
			cout << "Problem z utworzeniem pliku.";
			exit(0);
		}
}
//Nazwa, 1.Wojownik 2.Mag 3.Elf, lvl, cecha, hp

void odczyt(string n,Postac * Bohater) {
	clrscr();
	fstream plik;
	plik.open(n + ".txt", ios::in);
	if (plik.good() == true) {
		getline(plik, Bohater->nazwa);
		plik >> Bohater->rasa >> Bohater->lvl >> Bohater->cecha >> Bohater->hp;
		plik.close();
		if (Bohater->lvl == 10)
			cout << "Brawo wygrales, pokonales wszystkich przeciwnikow. Wielkie Gratulacje !" << endl;
		else {
			cout << "Twoj bohater :" << endl;
			cout << "-----------------------" << endl << Bohater->nazwa << endl;
			string klasa;
			string cecha;
			switch (Bohater->rasa)
			{
			case 1:
				klasa = "Wojownik";
				cecha = "Sila";
				break;
			case 2:
				klasa = "Mag";
				cecha = "Umiejetnosci";
				break;
			case 3:
				klasa = "Elf";
				cecha = "Zrecznosc";
				break;
			default:
				break;
			}
			cout << "Rasa : " << klasa << endl << "Poziom : " << Bohater->lvl << endl << cecha << " : " << Bohater->cecha << endl;
			cout << "Wytrzymalosc : " << Bohater->hp << endl << "-----------------------" << endl;
		}
	}
	else
	{
		cout << "Problem z odczytem pliku.";
		exit(0);
	}
}

inline void clrscr()
{
	COORD coordStart = { 0, 0 };
	DWORD dwCharsWr;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(console, (TCHAR) ' ', dwConSize, coordStart, &dwCharsWr);
	FillConsoleOutputAttribute(console, csbi.wAttributes, dwConSize, coordStart, &dwCharsWr);
	SetConsoleCursorPosition(console, coordStart);
}

void utworz_przeciwnika(Postac * Przeciwnik,int poziom) {
	switch (poziom)
	{
	case 2:
		Przeciwnik->nazwa = "Buntownik";
		Przeciwnik->rasa = 1;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 8;
		Przeciwnik->hp = 12;
		break;
	case 3:
		Przeciwnik->nazwa = "Poczatkujacy Mag";
		Przeciwnik->rasa = 2;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 18;
		Przeciwnik->hp = 12;
		break;
	case 4:
		Przeciwnik->nazwa = "Samotny Elf";
		Przeciwnik->rasa = 3;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 22;
		Przeciwnik->hp = 18;
		break;
	case 5:
		Przeciwnik->nazwa = "Nieustraszony Wojownik";
		Przeciwnik->rasa = 1;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 20;
		Przeciwnik->hp = 30;
		break;
	case 6:
		Przeciwnik->nazwa = "Grupka Elfow";
		Przeciwnik->rasa = 3;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 35;
		Przeciwnik->hp = 25;
		break;
	case 7:
		Przeciwnik->nazwa = "Olbrzym";
		Przeciwnik->rasa = 1;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 30;
		Przeciwnik->hp = 40;
		break;
	case 8:
		Przeciwnik->nazwa = "Wiedzma";
		Przeciwnik->rasa = 2;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 55;
		Przeciwnik->hp = 25;
		break;
	case 9:
		Przeciwnik->nazwa = "Mroczny Elf";
		Przeciwnik->rasa = 3;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 55;
		Przeciwnik->hp = 35;
		break;
	case 10:
		Przeciwnik->nazwa = "Arcymag";
		Przeciwnik->rasa = 2;
		Przeciwnik->lvl = poziom;
		Przeciwnik->cecha = 70;
		Przeciwnik->hp = 30;
		break;
	default:
		cout << "Brawo wygrales, pokonales wszystkich przecinkow!"; 
		break;
	}


}

void pokaz_przeciwnika(Postac * Przeciwnik) {
	cout << "Twoj przeciwnik :" << endl;
	cout << "-----------------------" << endl << Przeciwnik->nazwa << endl;
	string klasa;
	string cecha;
	switch (Przeciwnik->rasa)
	{
	case 1:
		klasa = "Wojownik";
		cecha = "Sila";
		break;
	case 2:
		klasa = "Mag";
		cecha = "Umiejetnosci";
		break;
	case 3:
		klasa = "Elf";
		cecha = "Zrecznosc";
		break;
	default:
		break;
	}
	cout << "Rasa : " << klasa << endl << "Poziom : " << Przeciwnik->lvl << endl << cecha << " : " << Przeciwnik->cecha << endl;
	cout << "Wytrzymalosc : " << Przeciwnik->hp << endl << "-----------------------" << endl;

}

void wybor(Postac * Bohater,Postac * Przeciwnik)
{
	cout << "Wybierz trening lub walke z przeciwnikiem(jezeli Twoj bohater jest na to gotowy)." << endl;
	cout << "Wpisz 1 jezeli wybierasz trening, 2 jezeli wybierasz walke, lub 3 jezeli chcesz zakonczyc gre." << endl;
	string nr;
	getline(cin, nr);
	if (nr == "1") {
		clrscr();
		trening(Bohater,Przeciwnik);
	}
	else
	{
		if (nr == "2") {
			clrscr();
			walka(Bohater, Przeciwnik);
		}
		else
		{
			if (nr == "3")
				exit(0);
			else
			{
                cout << "Nie poprawna liczba, sprobuj ponownie." << endl;
				wybor(Bohater, Przeciwnik);
			}
		}
	}

}

void walka(Postac * Bohater, Postac * Przeciwnik) {
	
	double sumaB, sumaP;
	
	switch (Bohater->rasa)
	{
	case 1:
		sumaB = (Bohater->cecha*0.5) + (Bohater->hp*0.5);
		break;
	case 2:
		sumaB = (Bohater->cecha*0.7) + (Bohater->hp*0.3);
		break;
	case 3:
		sumaB = (Bohater->cecha*0.6) + (Bohater->hp*0.4);
		break;
	default:
		break;
	}

	switch (Przeciwnik->rasa)
	{
	case 1:
		sumaP = (Przeciwnik->cecha*0.5) + (Przeciwnik->hp*0.5);
		break;
	case 2:
		sumaP = (Przeciwnik->cecha*0.7) + (Przeciwnik->hp*0.3);
		break;
	case 3:
		sumaP = (Przeciwnik->cecha*0.6) + (Przeciwnik->hp*0.4);
		break;
	default:
		break;
	}

	if (sumaB > sumaP) {
			cout << "Brawo pokonales przeciwnika, tym samym awansowales na " << Bohater->lvl + 1 << " poziom." << endl;
			if (Bohater->lvl == 9)
				cout << "Brawo wygrales, pokonales wszystkich przeciwnikow. Wielkie Gratulacje !" << endl;
			else {
			cout << Przeciwnik->nazwa << " prosi o wybaczenie, chce Ci pomoc w dalszej wyprawie." << endl;
			cout << "Odrzucajac jego propozcyje zabierzesz mu jego cenny ekwipunek. Zdecyduj madrze!" << endl;
		    }
			wygrana(Bohater, Przeciwnik);
	}
	if (sumaB <= sumaP) {
		cout << Przeciwnik->nazwa << " okazal sie silniejszy, przygotuj sie lepiej nastepnym razem!" << endl;
		opisPorazki(Bohater, Przeciwnik);
	}
	
}

void opisPorazki(Postac * Bohater, Postac * Przeciwnik) {
	cout << "Aby kontynuowac wcisnij Enter." << endl;
	string smiec;
	getline(cin, smiec);
    clrscr();
    odczyt(Bohater->nazwa, Bohater);
	pokaz_przeciwnika(Przeciwnik);
	wybor(Bohater, Przeciwnik);
}

int wybor2(int lvl, int rasa, int cecha) {
	switch (lvl)
	{
	case 1:
		cout << "Bron to wazny element ekwipunku Twojego bohater." << endl;
		cout << "Wybierz madrze, wpisujac odpowiednia liczbe:" << endl;
		cout << "1. Luk 2. Miecz 3. Rozdzka" << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		default:
			break;
	    }
		break;
	case 2:
		cout << "Przed Toba trudny wybor drogi." << endl;
		cout << "Wpisz 1 wybierajac droge przez miasto, 2 przez gory, 3 przez las." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 3:
		cout << "Na swojej drodze spotykasz kupca, ktory pozwala Ci wybrac jedna z jego ksiag." << endl;
		cout << "Wpisz 1 wybierajac Rosliny I Ich Zastosowanie, 2 Kontrola Umyslu, 3 Zbroje I Miecze." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 4:
		cout << "Zbroja zwieksza Twoje szanse na wygranie walki. Jaka wybierzesz ?" << endl;
		cout << "Wpisz 1 wybierajac Zbroje Ciezka, 2 Zbroje Lekka, 3 nie potrzbujesz zadnej zbroi." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 5:
		cout << "Chcesz udoskonalic swoje umiejetnosci udajesz sie do ?" << endl;
		cout << "Wpisz 1 wybierajac Zielarza, 2 Turniej Rycerski, 3 Opuszczone Ruiny." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 6:
		cout << "Na drodze spotykasz ogromnego bestie co robisz ?" << endl;
		cout << "Wpisz 1 wybierajac Walke, 2 Chytre Oszustwo Besti, 3 Ominiecie Besti." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 7:
		cout << "Jestes ranny po ostatnim starciu, musisz sie wyleczyc !" << endl;
		cout << "Wpisz 1 Leczac Sie Ziolami, 2 Szukajac Pomocy W Miescie, 3 Leczyc Sie Poprzez Medytacje." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 8:
		cout << "Masz do wyboru jeden z trzech przedmitow, wybierz madrze !" << endl;
		cout << "Wpisz 1 wybierajac Magiczny Medialion, 2 Zestaw Alchemika, 3 Tarcze." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		default:
			break;
		}
		break;
	case 9:
		cout << "Przed ostatnim starciem wybierz magiczny przedmiot." << endl;
		cout << "Wpisz 1 wybierajac Peleryne Niewidke, 2 Niezniszczalny Pancerz, 3 Starozytny Klejnot." << endl;
		switch (rasa) {
		case 1:
			cecha = cecha + odpowiedz("2");
			return cecha;
			break;
		case 2:
			cecha = cecha + odpowiedz("3");
			return cecha;
			break;
		case 3:
			cecha = cecha + odpowiedz("1");
			return cecha;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}


int odpowiedz(string odp) {
	string smiec;
	string nr;
	getline(cin, nr);
	if (nr == odp) {
		clrscr();
		cout << "Brawo Twoj wybor zwiekszyl glowna ceche Twojego bohatera o 5 !" << endl;
		cout << "Czas poznac Twojego przeciwnika !" << endl;
		cout << "Aby kontynuowac wcisnij Enter." << endl;
		getline(cin, smiec);
		return 5;
	}
	else {
		if (nr == "1" || nr == "2" || nr == "3") {
			clrscr();
			cout << "Brawo Twoj wybor zwiekszyl glowna ceche Twojego bohatera o 3 !" << endl;
			cout << "Czas poznac Twojego przeciwnika !" << endl;
			cout << "Aby kontynuowac wcisnij Enter." << endl;
			getline(cin, smiec);
			return 3;
        }
		else {
			cout << "Nie poprawna liczba, sprobuj ponownie." << endl;
			odpowiedz(odp);
		}

	}
}

void trening(Postac * Bohater,Postac * Przeciwnik) {
	cout << "Witaj na treningu!" << endl;
	cout << "Po kilku godzinach ciezkiego treningu Twoja wytrzymalosc wzrosla o 1 punkt." << endl;
	cout << "Gratulacje!" << endl;
	Bohater->hp += 1;
	utworz_plik(Bohater->nazwa, Bohater->rasa, Bohater->lvl, Bohater->cecha, Bohater->hp);
	cout << "Aby kontynuowac wcisnij Enter." << endl;
	string smiec;
	getline(cin, smiec);
	odczyt(Bohater->nazwa, Bohater);
	pokaz_przeciwnika(Przeciwnik);
	wybor(Bohater, Przeciwnik);
}

void wygrana(Postac * Bohater,Postac * Przeciwnik) {
	Bohater->lvl += 1;
	if (Bohater->lvl < 10) {
		cout << "Wpisz 1 jezeli akceptujesz propozycje bohatera, 2 jezeli wolisz zabrac jego cenne rzeczy." << endl;
		string odp;
		string smiec;
		getline(cin, odp);
		if (odp == "1") {
			if (Bohater->rasa == Przeciwnik->rasa) {
				Bohater->cecha += 5;
				clrscr();
				cout << "Brawo Twoja decyzja zwiekszyla glowna ceche Twojego bohatera o 5 !" << endl;
				cout << "Aby kontynuowac wcisnij Enter." << endl;
				getline(cin, smiec);
			}
			else {
				Bohater->cecha += 3;
				clrscr();
				cout << "Brawo Twoja decyzja zwiekszyla glowna ceche Twojego bohatera o 3 !" << endl;
				cout << "Aby kontynuowac wcisnij Enter." << endl;
				getline(cin, smiec);
			}
			utworz_plik(Bohater->nazwa, Bohater->rasa, Bohater->lvl, Bohater->cecha, Bohater->hp);
			clrscr();
		}
		else
		{
			if (odp == "2") {
				if (Bohater->rasa != Przeciwnik->rasa) {
				Bohater->cecha += 5;
				clrscr();
				cout << "Brawo Twoja decyzja zwiekszyla glowna ceche Twojego bohatera o 5 !" << endl;
				cout << "Aby kontynuowac wcisnij Enter." << endl;
				getline(cin, smiec);
			    }
				else {
					Bohater->cecha += 3;
					clrscr();
					cout << "Brawo Twoja decyzja zwiekszyla glowna ceche Twojego bohatera o 3 !" << endl;
					cout << "Aby kontynuowac wcisnij Enter." << endl;
					getline(cin, smiec);
				}
				utworz_plik(Bohater->nazwa, Bohater->rasa, Bohater->lvl, Bohater->cecha, Bohater->hp);
				clrscr();
			}
			else
			{
				cout << "Nie poprawna liczba, sprobuj ponownie." << endl;
				wygrana(Bohater, Przeciwnik);
			}
		}
	}

}
#endif