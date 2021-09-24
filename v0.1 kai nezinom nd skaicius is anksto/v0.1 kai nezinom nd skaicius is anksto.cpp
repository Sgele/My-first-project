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
void pild(studentas& kint, int x);
studentas studentai[30]; //sukuriamas studentu sarasas
bool ar_turi_skaiciu(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
};

int main()
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
        cout << "Jeigu norite, kad galutinis balas butu su vidurkiu rasykite '0', jeigu su mediania '1': "; cin >> x; cout << endl;

        for (int i = 0; i < m; i++)
        {
            do {
                pild(studentai[i], x); //bus pildoma informacija apie studenta
            } while (ar_turi_skaiciu(studentai[i].vardas) || ar_turi_skaiciu(studentai[i].pavarde));

        }

        cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << ((x == 0) ? "Galutinis (vid.)" : "Galutinis(med.)") << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < m; i++)
            print(studentai[i]); //spausdinami rezultatai 
    }
}

void pild(studentas& kint, int x) //informacijos pildymo funkcija
{
    double n; //namu darbu skaicius
    int sk; 
    double sum = 0; //bus saugoma bendra visu pazymiu suma
    double vid = 0; // visu pazymiu vidurkis
    double mediana = 0;
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "P.S. Jeigu netycia  pvz.: vietoj raides ivedete skaiciu, uzbaikite rasyti viska toliau ir tuomet vel automatiskai" << endl;
    cout << "atsiras galimybe parasyti viska is naujo." << endl;
    cout << "Programa neissaugos apie studenta informacijos" << endl;
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
        do {
            try {
                 if (cin.fail() || n <= -1 || n > 10) {
                        throw std::runtime_error("Ivedete ne toki simboli!!!\n");
                 }
            }
            catch (const std::runtime_error& e) {
                    cout << e.what();
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Veskite simoli dar karta: ";
                    cin >> n;
            }
        } while (cin.fail() == true || n <= -1 || n > 10);
            if (n > 0 && n <= 10)
            {
              kint.nd[k-1] = n;
              sum = sum + kint.nd[k-1];
              k++;
            }
            else
            {
                break;
            }
        }
        
        vid = sum / k;
        sort(kint.nd, kint.nd + k);
        if (k % 2 != 0)
        {
            mediana = (double)kint.nd[k / 2];
        }
        else
        {
            mediana = (double)(kint.nd[(k - 1) / 2] + kint.nd[k / 2]) / 2.0;
        }
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
        do {
            try {
                if (cin.fail() || kint.egz <= 0 || kint.egz > 10) {
                    throw std::runtime_error("Ivedete ne toki simboli!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Veskite simoli dar karta: ";
                cin >> kint.egz;
            }
        } while (cin.fail() == true || kint.egz <= 0 || kint.egz > 10);

    }
    if (sk > 0) 
    {
          cout << "Iveskite namu darbu pazymius: " << endl;
          for (int i = 0; i < sk; i++)
          {
             cin >> kint.nd[i];
             do {
                 try {
                     if (cin.fail() || kint.nd[i] <= 0 || kint.nd[i] > 10) {
                         throw std::runtime_error("Ivedete ne toki simboli!!!\n");
                     }
                 }
                 catch (const std::runtime_error& e) {
                     cout << e.what();
                     cin.clear();
                     cin.ignore(256, '\n');
                     cout << "Veskite simoli dar karta: ";
                     cin >> kint.nd[i];
                 }
             } while (cin.fail() == true || kint.nd[i] <= 0 || kint.nd[i] > 10);

             sum = sum + kint.nd[i];
          }
          
        vid = sum / sk; //skaiciuojame pazymiu vidurki
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
        do {
            try {
                if (cin.fail() || kint.egz <= 0 || kint.egz > 10) {
                    throw std::runtime_error("Ivedete ne toki simboli!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Veskite simoli dar karta: ";
                cin >> kint.egz;
            }
        } while (cin.fail() == true || kint.egz <= 0 || kint.egz > 10);
        sort(kint.nd, kint.nd + sk);

        
        if (sk % 2 != 0)
            mediana = (double)kint.nd[sk / 2];
        else
        {
           mediana =  (double)(kint.nd[(sk - 1) / 2] + kint.nd[sk / 2]) / 2.0;

        }
    }
    if (x == 0) {
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
