#ifndef Nag³ówek_H
#define Nag³ówek_H

#include<string>
#include<iostream>
using namespace std;

struct Postac {
	string nazwa;
	int rasa;    // 1 Woj 2 Mag 3 Elf
	int cecha;
	int lvl;
	int hp;
};

void wstep();

void nowy_bohater(string n);

void odczyt(string n,Postac * Bohater);

inline void clrscr(); //czysci konsole

void utworz_plik(string n, int r ,int l, int c, int h);

void utworz_przeciwnika(Postac * Przeciwnik,int poziom);

void pokaz_przeciwnika(Postac * Przeciwnik);

void wybor(Postac * Bohater,Postac * Przeciwnik);

void walka(Postac * Bohater,Postac * Przeciwnik);

void opisPorazki(Postac * Bohater, Postac * Przeciwnik);

int wybor2(int lvl,int rasa,int cecha);

int odpowiedz(string odp);

void trening(Postac * Bohater,Postac * Przeciwnik);

void wygrana(Postac * Bohater,Postac * Przeciwnik);



#endif