#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;
using std::setprecision;
using std::setw;
using std::endl;
using std::string;
using std::left;
using std::right;
using std::sort;
using std::vector;

struct studentas {
    string vardas, pavarde;
    vector<double> nd; //namu darbu rezultatai
    double egz; //egzamino rezultatas
    double galutinis;
    double mediana;
};

void print(studentas& kint);
void pild(studentas& kint);
studentas studentai[30]; //sukuriamas studentu sarasas

int main ()
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
    int sk;
    double sum = 0; //bus saugoma bendra visu pazymiu suma
    double vid = 0; // visu pazymiu vidurkis
    double mediana = 0;
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Parasykite, jeigu zinote namu darbu skaiciu (1-10), jeigu nezinote, parasykite '-1'" << endl;
    cin >> sk;
    if (sk == -1)
    {
        int k = 1; //pazymio vieta masyve nd
        cout << "Ivedus 0, programa supras, kad baigete nd pazymiu ivedima" << endl;
        cout << "Iveskite namu darbu pazymius: " << endl;

        while (k > 0)
        {
            cin >> n;
            if (n > 0)
            {
                kint.nd.push_back(n);
                sum = sum + kint.nd[k - 1];
                k++;
            }
            else
            {
                break;
            }
        }
        int p = 0;
        p = kint.nd.size(); //atimame viena, kadangi gale irasome 0
        vid = sum / p;
        sort(kint.nd.begin(), kint.nd.end());
        if (p % 2 != 0)
        {
            mediana = (double)kint.nd[p / 2];
        }
        else
        {
            mediana = (double)(kint.nd[(p - 1) / 2] + kint.nd[p / 2]) / 2.0;
        }
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;

    }
    if (sk > 0)
    {
        cout << "Iveskite namu darbu pazymius: " << endl;
        for (int i = 0; i < sk; i++)
        {
            cin >> n;
            kint.nd.push_back(n);
            sum = sum + kint.nd[i];
        }

        vid = sum / sk; //skaiciuojame pazymiu vidurki
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
        sort(kint.nd.begin(), kint.nd.end());

        if (sk % 2 != 0)
            mediana = (double)kint.nd[sk / 2];
        else
        {
            mediana = (double)(kint.nd[(sk - 1) / 2] + kint.nd[sk / 2]) / 2.0;

        }
    }
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
