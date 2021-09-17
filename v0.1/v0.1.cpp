// v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::setprecision;
using std::setw;
using std::endl;
using std::string;
using std::left;
using std::right;

struct studentas {
    string vardas, pavarde;
    float nd[10]; //namu darbu rezultatai
    float egz; //egzamino rezultatas
    float galutinis;
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
    cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << "Galutinis (vid.) " << endl;
    for (int i = 0; i < m; i++)
        print(studentai[i]); //spausdinami rezultatai 
    
}

void pild(studentas& kint) //informacijos pildymo funkcija
{
    int n; //namu darbu skaicius
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek namu darbu bus? (1-10): "; cin >> n; cout << endl;
    cout << "Iveskite namu darbu pazymius: " << endl;
    float sum = 0, //bus saugoma bendra visu pazymiu suma
    float vid = 0; // visu pazymiu vidurkis
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum = sum + kint.nd[i];
    }
    vid = sum / n; //skaiciuojame pazymiu vidurki 
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
    kint.galutinis = 0.4 * vid + 0.6 * kint.egz; //apskaiciuojamas galutinis balas
}

void print(studentas& kin) //spausdinimo funkcija
{
    cout << left << setw(12) << kin.pavarde << setw(12) << kin.vardas << setw(10) << setprecision(3) << kin.galutinis << endl;
}




