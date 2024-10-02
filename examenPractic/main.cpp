#include "examenPractic.h"
#include <QtWidgets/QApplication>
#include "repo.h"
#include "service.h"
#include "gui.h"
#include <assert.h>

void test_repo() {
    repo r{ "test1.txt" };

    auto& masini = r.getAllRepo();
    auto& m = masini[0];


    assert(m.get_nrin() == "cj14sda");
    
    assert(r.getAllRepo().size() == 4);

    assert(m.get_an() == 2005);

    r.decrementareRepo(m);

    assert(m.get_an() == 2004);

    r.decrementareRepo(m);

    assert(m.get_an() == 2003);

    r.incrementareRepo(m);
    r.incrementareRepo(m);
    assert(m.get_an() == 2005);

    r.stergeIndex(1);

    assert(r.getAllRepo().size() == 3);
}

void test_service() {
    masina m{ "cj14sda", "audi a4", 2005, "hatch" };
   
    repo r{ "test.txt" };
    service s{ r };

    assert(s.getAllService().size() == 4);

    s.sterge({ 1,2 });

    assert(s.getAllService().size() == 2);

    s.decrement();

    assert(s.getAllService()[0].get_an() == 2004);

    s.increment();

    assert(s.getAllService()[0].get_an() == 2005);
}


void test_all() {
    test_repo();
    test_service();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    //test_all();

    repo r{ "Text.txt" };
    service s{ r };
    gui ui{ s };

    ui.show();

    return a.exec();
}
