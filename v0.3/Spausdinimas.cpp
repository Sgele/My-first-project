#include "Spausdinimas.h"

void Spausdinimas(vector<studentas> kint, int x)
{

    std::ofstream output;
    output.open("rezultatai.txt");
    output << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(15) << ((x == 0) ? "Galutinis (vid.)" : "Galutinis (med.)") << endl;
    output << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < kint.size(); i++)
    {
        output << left << setw(20) << kint[i].pavarde << setw(20) << kint[i].vardas << setw(15) << setprecision(3) << kint[i].galutinis << endl;
    }
}