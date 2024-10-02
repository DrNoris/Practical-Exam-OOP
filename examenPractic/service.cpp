#include "service.h"

void service::increment()
{
	for (auto& m : r.getAllRepo())
		r.incrementareRepo(m);
}

void service::decrement()
{
	for (auto& m : r.getAllRepo())
		r.decrementareRepo(m);
}

void service::sterge(vector<int> index)
{
	for (auto i : index)
		r.stergeIndex(i);
}

void service::addUndoInc(service& s)
{
	actiuni[cp++] = UndoInc{s};
	index = cp;
}

void service::addUndoDec(service& s)
{
	actiuni[cp++] = UndoDec{ s };
	index = cp;
}