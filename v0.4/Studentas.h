#pragma once
#include <string>
#include <vector>
using namespace std;

struct studentas {
    std::string vardas, pavarde;
    std::vector<double> nd; //namu darbu rezultatai
    double egz; //egzamino rezultatas
    double galutinis;
    double mediana;
};
