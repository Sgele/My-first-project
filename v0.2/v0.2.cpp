#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <istream>
#include <fstream>
#include <sstream>
#include <iterator>
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


void skaitymas(vector<studentas>& kint, int* pazymiu_sk);
unsigned int KiekZodziu(string const& str);
void spausdinimas(vector<studentas>  kint);
double mediana(vector<double> nd);
double vidurkis(vector<double> nd, double sum);

void print(studentas& kint);
void pild(studentas& kint);
studentas studentai[30]; //sukuriamas studentu sarasas
bool ar_turi_skaiciu(string s) //tikrinam ar zodyje nera netycia ivestu skaiciu
{
    return (s.find_first_of("0123456789") != string::npos);
};
//rusiuojam pagal varda
bool cmp(const studentas& s1, const studentas& s2) {
    return s1.vardas < s2.vardas;
}
//tikrinisim ar failas nera tuscias
bool is_empty(std::ifstream& pFile) 
{
    return pFile.peek() != std::ifstream::traits_type::eof();
}


int main()
{
    int k; //vartotojas nuspres kaip bus gaunami duomenys
    cout << "Irasykite 0, jeigu duomenis nuskaitysite is failo;" << endl;
    cout << "Irasykite 1, jeigu vesite 'ranka'." << endl;
    cin >> k;
    if (k == 0)
    {
        vector<studentas> studentai;
        int pazymiu_sk;
        char temp;
        skaitymas(studentai, &pazymiu_sk);
        sort(studentai.begin(), studentai.end(), cmp);
        spausdinimas(studentai);
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
        for (int i = 0; i < m; i++)
        {
            do {
                pild(studentai[i]); //bus pildoma informacija apie studenta
            } while (ar_turi_skaiciu(studentai[i].vardas) || ar_turi_skaiciu(studentai[i].pavarde));

        }

        cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << "Galutinis (vid.) / Galutinis (med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < m; i++)
            print(studentai[i]); //spausdinami rezultatai 


    }
    return 0;
 
}

void skaitymas(vector<studentas>& kint, int* pazymiu_sk) 
{
    int stud_sk = 0;
    int temp;
    double vid = 0;
    double sum;
    std::ifstream fileRead;
    string failas; // laikyti string tipui
    fileRead.open("kursiokai2.txt");
    if (!fileRead)
    {
        cout << "Failas nera atidarytas!" << endl;
        exit(EXIT_FAILURE);
    }
    if (is_empty(fileRead))
    {
        getline(fileRead >> std::ws, failas); //ws nepraleidzia tarpu
        *pazymiu_sk = KiekZodziu(failas) - 3; //atimame 3 (vardas,pavarde,egzaminas)
        while (true)
        {

            kint.resize(kint.size() + 1);
            fileRead >> kint.at(stud_sk).vardas; //at grazina reiksme vektoriuj i jo vieta, siuo atveju stud_sk
            cout << kint[stud_sk].vardas;
            if (fileRead.eof()) 
            { 
                kint.pop_back(); // Removes the last element in the vector, effectively reducing the container size by one
                break; 
            } 
            fileRead >> kint.at(stud_sk).pavarde;
            cout << kint[stud_sk].pavarde << endl;
            sum = 0;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                
                fileRead >> temp;
                cout << temp << "   ";
                sum = sum + temp;
                kint.at(stud_sk).nd.push_back(temp);
                
                
            }
            //cout << endl;
            //cout << "pazymiu skaicius: " << *pazymiu_sk << endl;
            //cout << endl;            
            fileRead >> kint.at(stud_sk).egz;
            cout << "egzamino paz: " << kint.at(stud_sk).egz << endl;
            int m; //pagal si kintamaji nusprendziam ar vartotojas nori medianos ar vidurkio; 
            cout << "Jeigu norite, kad galutinis pazymys butu su vidurkiu iveskite 0, jeigu su mediana - 1: "; cin >> m; cout << endl;
            if (m == -1)
            {
                kint.at(stud_sk).galutinis = mediana(kint.at(stud_sk).nd) * 0.4 + 0.6 * kint.at(stud_sk).egz;
            }
            else
            {
                kint.at(stud_sk).galutinis = vidurkis(kint.at(stud_sk).nd, sum) * 0.4 + 0.6 * kint.at(stud_sk).egz;
            }
            stud_sk++;
        }
     
    }
    else { cout << "FAILAS TUSCIAS!"; }

    
}
unsigned int KiekZodziu(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}
void spausdinimas(vector<studentas> kint)
{

    std::ofstream output;
    output.open("rezultatai.txt");
    output << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << "Galutinis (vid.) / Galutinis (med.)" << endl;
    output << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < kint.size(); i++)
    {
        output << left << setw(12) << kint[i].pavarde << setw(12) << kint[i].vardas << setw(10) << setprecision(3) << kint[i].galutinis << endl;
    }
}
double mediana(vector<double> nd)
{
    size_t size = nd.size();

    if (size == 0)
    {
        return 0;  // jeigu tuscias vektorius
    }
    else
    {
        sort(nd.begin(), nd.end());
        if (size % 2 == 0)
        {
            return (double)(nd[size / 2 - 1] + nd[size / 2]) / 2.0;
        }
        else
        {
            return (double)nd[size / 2];
        }
    }
}
double vidurkis(vector<double> nd, double sum)
{
    double vid = 0;
    double n = nd.size();
    n = n * 1.00;
    return vid = sum / n ;
}


//kai ranka ivesdineja

void pild(studentas& kint) //informacijos pildymo funkcija
{
    int n; //namu darbu skaicius
    int sk;
    double sum = 0; //bus saugoma bendra visu pazymiu suma
    double vid = 0; // visu pazymiu vidurkis
    double mediana = 0;
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "P.S. Jeigu netycia  pvz.: vietoj raides ivedete skaiciu, uzbaikite rasyti viska toliau ir tuomet vel automatiskai " << endl;
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
            if (n > 0 && n <= 10)
            {
                kint.nd.push_back(n);
                sum = sum + kint.nd[k - 1];
                k++;
            }
            else if (n < 0 || isdigit(n) == false)
            {
                cout << "Ivestas simbolis nera skaicius 1-10!" << endl;
                exit(EXIT_FAILURE);
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
