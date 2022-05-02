//
// Created by Daniel on 11/02/2021.
//

#ifndef NASP_LAB02_GA_H
#define NASP_LAB02_GA_H


#include <string>
#include "Jedinka.h"
using namespace std;

class GA
{
private:
    int VEL_POP; // veličina populacije, odnosno broj jedinki u populaciji
    double m_pm; // vjerojatnost mutacije
    double m_pc; // vjerojatnost križanja

    double random_broj(); // vraća slučajni broj između 0.0 i 1.0
    static double dobrota(int vrijednostJedinke); // funkcija dobrote
    static string decUBin(int ulaz); // pretvorba cjelobrojna vrijednost jedinke u binarnu vrijednost
    static int binUDec(string ulaz); // pretvorba binarna vrijednost u cjelobrojnu vrijednost jedinke
    void pocetna_generacija(); // generiranje početne populacije jedinki, slučajna cjelobrojna vrijednost u intervalu [0, 1023]
    void mutacija(); // ulazna metoda za mutaciju svih jedinki
    void mutacija_jedinke(Jedinka *k); // metoda za mutaciju odabrane jedinke k
    void krizanje(); // ulazna metoda za križanje svih jedinki
    void jednostavno_krizanje(Jedinka *r1, Jedinka *r2, Jedinka *d1); // metoda za jednostavno križanje ulaznih vrijednosti jedinki roditelja r1 i r2. Izlazna vrijednost iz metode je jedinka dijete d1
    void ispis(); // ispis svih jedinki u populaciji

public:
    double max_dobrota; // maksimalna dobrota u populaciji
    Jedinka* populacija = new Jedinka[VEL_POP]; // populacija jedinki

    GA(); // konstruktor, inicira random seed generator i početnu populaciju jedinki
    ~GA(); // dekonstruktor, oslobađa memoriju zauzetu s VEL_POP jedinki
    void odrediRjesenje(int _broj_iteracija, double _pm, double _pc); // ulazna funkcija
};


#endif //NASP_LAB02_GA_H
