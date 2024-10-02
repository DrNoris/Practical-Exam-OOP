#pragma once
#include "repo.h"
#include <exception>
class UndoActiune {
public:
	virtual void undo() = 0;
	virtual ~UndoActiune() = default;
};

class service
{
private:
	repo& r;
	vector<UndoActiune> actiuni;
	int cp = 0;
	int index = 0;
public:
	service(repo& rep) : r{ rep } {}

	//functia returneaza prin reference vectorul din repo
	vector<masina>& getAllService() {
		return r.getAllRepo();
	}

	//functia de incrementare apealeaza incrementarea din repo
	void increment();

	//functia de decrementare apeleaza decrementarea din repo pentru fiecare masina si decrementeaza anul de fabricatie
	void decrement();

	//functia de stergere, primeste un vector de int pentru a sterge fiecare masina de la acel index
	void sterge(vector<int> index);

	//functia ce adauga un aobiecte pentru a face undo la incrementare
	void addUndoInc(service& r);

	//functia ce adauga un aobiecte pentru a face undo la decrementare
	void addUndoDec(service& r);

	//functia ce trece prin lista de obiecte de undo si le face undo
	void undo() {
		actiuni[index--].undo();
		actiuni.pop_back();
	}
};

class UndoInc : public UndoActiune {
private:
	service& ser;
public:
	UndoInc(service& r) : ser{ r } {}

	void undo() override {
		ser.decrement();
	}
};

class UndoDec : public UndoActiune {
private:
	service& ser;
public:
	UndoDec(service& r) : ser{ r } {}

	void undo() override {
		ser.increment();
	}
};