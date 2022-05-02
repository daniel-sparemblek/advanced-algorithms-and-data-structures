//
// Created by Daniel on 11/02/2021.
//

#ifndef NASP_LAB02_JEDINKA_H
#define NASP_LAB02_JEDINKA_H

#include <string>

using namespace std;

class Jedinka {
public:
    int m_vrijednost_int; // cjelobrojna vrijednost jedinke, npr. 139
    string m_vrijednost_bin; // binarna reprezentacija pogodna za primjenu operatora mutacije, npr. 0010001011
    double m_dobrota; // iznos dobrote jedinke, npr. 104.167
    void ispis(); // ispis za gornji primjer: "Jedinka: 0010001011(bin) 139(int) Dobrota: 104.167"
};


#endif //NASP_LAB02_JEDINKA_H
