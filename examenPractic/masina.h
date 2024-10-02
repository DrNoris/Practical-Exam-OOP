#pragma once
#include <string>
#include <vector>
using namespace std;


//clasa pentru obiectul masina cu: nrin - string, denumire - string, an - int si tip - string
class masina
{
private:
	string nrin;
	string denumire;
	int an;
	string tip;
public:
	masina(string n, string d, int a, string t) : nrin{ n }, denumire{ d }, an{ a }, tip{ t } {}

	string get_nrin() {
	//getter nrin
		return nrin;
	}

	string get_denumire() {
	//getter denumire
		return denumire;
	}

	int get_an() {
	//getter an
		return an;
	}

	string get_tip() {
	//getter tip
		return tip;
	}

	void set_an(int a) {
		an = a;
	}
};

