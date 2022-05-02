#include "Jedinka.h"
#include "GA.h"

void odrediRjesenje(int _broj_iteracija, double _pm, double _pc) {
    int VEL_POP = 20;
    Jedinka* populacija = new Jedinka[VEL_POP];
    populacija->ispis();
    GA *g = new GA;
    g->odrediRjesenje(10, 10, 10);
}