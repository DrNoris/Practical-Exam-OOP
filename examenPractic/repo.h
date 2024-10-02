#pragma once
#include "masina.h"

class repo
{
private:
	vector<masina> masini;
	string filename;
public:
	repo(string file) : filename{ file } {
		loadfromfile();
	}

	//fucntai incarca din fisier in repo
	void loadfromfile();

	//functia scrie din repo in fisier
	void writetofile();

	//functia ce returneaza vectorul de masini prin reference
	vector<masina>& getAllRepo() {
		return masini;
	}

	//functia de incrementare primeste o masina ca parametru si ii incrementeaza anul 
	void incrementareRepo(masina& m);

	//functia de decrementare primeste o masina ca parametru si ii decrementeaza anul
	void decrementareRepo(masina& m);

	//functia ce sterge o masina de la un index dat ca prametru
	void stergeIndex(int i);
};