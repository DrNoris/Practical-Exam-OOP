#include "repo.h"
#include <sstream>
#include <fstream>
#include <qDebug>
#include <algorithm>

void repo::loadfromfile()
{
	ifstream fin(filename);

	string linie;

	while (getline(fin, linie)) {
		stringstream ss(linie);

		string nrin;
		string denumire;
		string as;
		int a;
		string tip;

		getline(ss, nrin, ';');
		getline(ss, denumire, ';');
		getline(ss, as, ';');
		a = stoi(as);
		getline(ss, tip, ';');

		masina m = { nrin, denumire, a, tip };
		masini.push_back(m);
	}
	
	sort(masini.begin(), masini.end(), [&](masina& m1, masina& m2) {
		return m1.get_nrin() < m2.get_nrin();
		});

	fin.close();

	writetofile();
}

void repo::writetofile() {
	sort(masini.begin(), masini.end(), [&](masina& m1, masina& m2) {
		return m1.get_nrin() < m2.get_nrin();
		});

	ofstream fout(filename);

	for (auto& masina : masini) {
		fout << masina.get_nrin() << ';' << masina.get_denumire() << ';' << masina.get_an() << ';' << masina.get_tip() << endl;
	}

	fout.close();
}

void repo::incrementareRepo(masina& m)
{
	int an = m.get_an();
	m.set_an(an + 1);

	writetofile();
}

void repo::decrementareRepo(masina& m)
{
	int an = m.get_an();
	m.set_an(an - 1);

	writetofile();
}

void repo::stergeIndex(int i)
{
	for (; i < masini.size() - 1; ++i)
		masini[i] = masini[i + 1];

	masini.pop_back();

	writetofile();
}
