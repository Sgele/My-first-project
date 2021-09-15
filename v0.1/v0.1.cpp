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
studentas studentai[10];


int main()
{
    int m; //studentu skaicius
    cout << "Iveskite studentu skaiciu: "; cin >> m; cout << endl;
    for (int i = 0; i < m; i++)
        pild(studentai[i]);
    cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << "Galutinis (vid.) " << endl;
    for (int i = 0; i < m; i++)
        print(studentai[i]);
    
}

void pild(studentas& kint)
{
    int n; //namu darbu skaicius
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek namu darbu bus? (1-10): "; cin >> n; cout << endl;
    cout << "Iveskite namu darbu pazymius: " << endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum = sum + kint.nd[i];
    }
    vid = sum / n;
    cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
    kint.galutinis = 0.4 * vid + 0.6 * kint.egz;
}

void print(studentas& kin)
{
    cout << left << setw(12) << kin.vardas << setw(12) << kin.pavarde << setw(10) << setprecision(2) << kin.galutinis << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
