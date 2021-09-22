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


int main()
{
    vector<studentas> studentai;
    int pazymiu_sk;
    char temp;
    skaitymas(studentai, &pazymiu_sk);
    spausdinimas(studentai);
    
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
    fileRead.open("kursiokai.txt");
    if (fileRead.is_open())
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
            cout << endl;
            cout << "pazymiu skaicius: " << *pazymiu_sk << endl;
            //vid = sum / double(*pazymiu_sk);
            cout << endl;
            cout << "vidurkis: " << vid << endl;
            
            fileRead >> kint.at(stud_sk).egz;
            cout << "egzamino paz: " << kint.at(stud_sk).egz << endl;
            int m; //pagal si kintamaji nusprendziam ar vartotojas nori medianos ar vidurkio; 
            cout << "Jeigu norite, kad galutinis pazymys butu su vidurkiu iveskite 0, jeigu su mediana - 1: "; cin >> m; cout << endl;
            if (m == 0)
            {
                kint.at(stud_sk).galutinis = mediana(kint.at(stud_sk).nd) * 0.4 + 0.6 * kint.at(stud_sk).egz;
            }
            else
            {
                kint.at(stud_sk).galutinis = vidurkis(kint.at(stud_sk).nd, sum) * 0.4 + 0.6 * kint.at(stud_sk).egz;
            }
            //std::cout << kint.at(stud_sk).vard;
            //kint.at(stud_sk).galutinis = kint.at(stud_sk).galutinis / *pazymiu_sk;
            //kint.at(stud_sk).galutinis = kint.at(stud_sk).galutinis * 0.4 + 0.6 * kint.at(stud_sk).egz;
            stud_sk++;
        }
     
    }
    else { std::cout << "-\n"; }

    
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
    size_t size = nd.size();
    return vid = sum / nd.size();
}