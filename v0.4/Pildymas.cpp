#include "Pildymas.h"


void Pildymas(studentas& kint, int x) //informacijos pildymo funkcija
{
    double n; //namu darbu skaicius
    int sk;
    double sum = 0; //bus saugoma bendra visu pazymiu suma
    double vid = 0; //pazymiu vidurkis
    double mediana = 0;
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "P.S. Jeigu netycia  pvz.: vietoj raides ivedete skaiciu, uzbaikite rasyti viska toliau ir tuomet vel automatiskai" << endl;
    cout << "atsiras galimybe parasyti viska is naujo." << endl;
    cout << "Programa neissaugos apie studenta informacijos" << endl;
    cout << "Parasykite, jeigu zinote namu darbu skaiciu (1-10), jeigu nezinote, parasykite '-1'" << endl;
    cout << "jeigu norite, kad skaiciai butu generuojami atsitiktinai parasykite '-2'" << endl;
    cin >> sk;
    if (sk == -1)
    {
        int k = 1; //pazymio vieta vektoriuje
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
        p = kint.nd.size();
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
            cin >> n;
            do {
                try {
                    if (cin.fail() || n <= 0 || n > 10) {
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
            } while (cin.fail() == true || n <= 0 || n > 10);
            kint.nd.push_back(n);
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

        sort(kint.nd.begin(), kint.nd.end());
        if (sk % 2 != 0)
            mediana = (double)kint.nd[sk / 2];
        else
        {
            mediana = (double)(kint.nd[(sk - 1) / 2] + kint.nd[sk / 2]) / 2.0;

        }
    }
    if (sk == -2)
    {
        int k;
        cout << "Iveskite skaiciu kiek norite, jog butu atsitiktinai parinkta nd pazymiu: "; cin >> k; cout << endl;
        for (int i = 0; i < k; i++)
        {
            int random_x;
            random_x = rand() % 10 + 1;
            kint.nd.push_back(random_x);
            cout << kint.nd[i] << endl;
            sum = sum + kint.nd[i];

        }
        kint.egz = rand() % 10 + 1;
        cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << kint.egz << endl;
        int p = 0;
        p = kint.nd.size();
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
    }

    if (x == 0) {
        kint.galutinis = 0.4 * vid + 0.6 * kint.egz; //apskaiciuojamas galutinis balas su vidurkiu
    }
    else {
        kint.galutinis = 0.4 * mediana + 0.6 * kint.egz; //apskaiciuojamas galutinis balas su vidurkiu
    }
}