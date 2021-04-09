#include<iostream>
#include<string>
#include<fstream>
#include"Nag³ówek.h"
using namespace std;

int main() {
	setlocale(LC_ALL," "); // polskie znaki
	string nazwa_postaci;
	wstep();
	getline(cin, nazwa_postaci);
	fstream plik;
	plik.open(nazwa_postaci + ".txt", ios::in);
	if (plik.good() == false)
		nowy_bohater(nazwa_postaci);
	plik.close();
	Postac * Bohater = new Postac;
	Postac * Przeciwnik = new Postac;
		while (Bohater->lvl < 10) {
			odczyt(nazwa_postaci, Bohater);
			if (Bohater->lvl < 10) {
				utworz_przeciwnika(Przeciwnik, Bohater->lvl + 1);
				pokaz_przeciwnika(Przeciwnik);
				wybor(Bohater, Przeciwnik);
				utworz_plik(Bohater->nazwa, Bohater->rasa, Bohater->lvl, wybor2(Bohater->lvl, Bohater->rasa, Bohater->cecha), Bohater->hp);
			}
		}
	system("pause");
	return 0;
}