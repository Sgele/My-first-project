#include "Studentas.h"
#include "Vidurkis.h"
#include "Skaitymas.h"
#include "Cmp.h"
#include "Spausdinimas.h"
#include "Pildymas.h"
#include "Ar_turi_skaiciu.h"
#include "Print.h"
#include "KiekZodziu.h"
#include "Mediana.h"
#include "Vidurkis.h"
#include "Pildymas.h"



int main()
{
    vector<studentas> studentai;
    int k; //vartotojas nuspres kaip bus gaunami duomenys
    cout << "Irasykite 0, jeigu duomenis nuskaitysite is failo;" << endl;
    cout << "Irasykite 1, jeigu vesite 'ranka'." << endl;
    cin >> k;
    if (k == 0)
    {
        //vector<studentas> studentai;
        int pazymiu_sk;
        char temp;
        int x;
        cout << "Jeigu norite, kad galutinis balas butu su vidurkiu rasykite '0', jeigu su mediania '-1': "; cin >> x; cout << endl;
        Skaitymas(studentai, &pazymiu_sk, x);
        sort(studentai.begin(), studentai.end(), Cmp);
        Spausdinimas(studentai, x);
    }
    else
    {
        double m; //studentu skaicius
        cout << "Iveskite studentu skaiciu: "; cin >> m; cout << endl;
        if (abs(m - int(m)) > 0)
        {
            cout << "Ivestas skaicius turi buti sveikasis! Pabandykite is naujo" << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            int x;
            cout << "Jeigu norite, kad galutinis balas butu su vidurkiu rasykite '0', jeigu su mediana '-1': "; cin >> x; cout << endl;

            for (int i = 0; i < m; i++)
            {
                do {
                    Pildymas(studentai[i], x); //bus pildoma informacija apie studenta
                } while (Ar_turi_skaiciu(studentai[i].vardas) || Ar_turi_skaiciu(studentai[i].pavarde));

            }

            cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << ((x == 0) ? "Galutinis (vid.)" : "Galutinis(med.)") << endl;
            cout << "---------------------------------------------------------------" << endl;
            for (int i = 0; i < m; i++)
                Print(studentai[i]); //spausdinami rezultatai 
        }
    }

    return 0;
}

