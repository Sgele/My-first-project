#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::setprecision;
using std::setw;
using std::endl;
using std::string;
using std::left;
using std::right;
using std::sort;

struct studentas {
    string vardas, pavarde;
    double nd[10]; //namu darbu rezultatai
    double egz; //egzamino rezultatas
    double galutinis;
};

void print(studentas& kint);
void pild(studentas& kint);
studentas studentai[10]; //sukuriamas studentu sarasas


int main()
{
    int m; //studentu skaicius
    cout << "Iveskite studentu skaiciu: "; cin >> m; cout << endl;
    for (int i = 0; i < m; i++)
        pild(studentai[i]); //bus pildoma informacija apie studenta
    cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << "Galutinis (vid.) / Galutinis (med.)" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < m; i++)
        print(studentai[i]); //spausdinami rezultatai 

}

void pild(studentas& kint) //informacijos pildymo funkcija
{
    int n; //namu darbu skaicius
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek namu darbu bus? (1-10): "; cin >> n; cout << endl;
    cout << "Iveskite namu darbu pazymius: " << endl;
    double sum = 0; //bus saugoma bendra visu pazymiu suma
    double vid = 0; // visu pazymiu vidurkis
    double mediana = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum = sum + kint.nd[i];
    }
    sort(kint.nd, kint.nd + n);
    if (n % 2 != 0)
    {
        mediana = (double)kint.nd[n / 2];
    }
    else
    {
        mediana = (double)(kint.nd[(n - 1) / 2] + kint.nd[n / 2]) / 2.0;
    }  
    vid = sum / n; //skaiciuojame pazymiu vidurki 
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
    int m; //pagal si kintamaji nusprendziam ar vartotojas nori medianos ar vidurkio;
    cout << "Jeigu norite, kad galutinis pazymys butu su vidurkiu iveskite 0, jeigu su mediana - 1: "; cin >> m; cout << endl;
    if (m == 0) {
        kint.galutinis = 0.4 * vid + 0.6 * kint.egz; //apskaiciuojamas galutinis balas
    }
    else {
        kint.galutinis = 0.4 * mediana + 0.6 * kint.egz;
    }
    
}

void print(studentas& kint) //spausdinimo funkcija
{
    cout << left << setw(12) << kint.pavarde << setw(12) << kint.vardas << setw(10) << setprecision(3) << kint.galutinis << endl;

}

