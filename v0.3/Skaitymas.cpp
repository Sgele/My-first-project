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
#include "Skaitymas.h"
#include "KiekZodziu.h"
#include "Vidurkis.h"
#include "Is_empty.h"
#include "Mediana.h"
using namespace std;


void Skaitymas(std::vector<studentas>& kint, int* pazymiu_sk, int x)
{
    int stud_sk = 0;
    int temp;
    double vid = 0;
    double sum;
    std::ifstream fileRead;
    string failas; // laikyti string tipui
    try {
         fileRead.open("kursiokai.txt");

         if (!fileRead.is_open())
             throw 0;

         getline(fileRead >> std::ws, failas); //ws nepraleidzia tarpu
         *pazymiu_sk = KiekZodziu(failas) - 3; //atimame 3 (vardas,pavarde,egzaminas)
         while (true)
         {
             kint.resize(kint.size() + 1); //viena vieta jau sukuriame
             fileRead >> kint.at(stud_sk).vardas; //at grazina reiksme vektoriui i jo vieta, siuo atveju stud_sk
             if (fileRead.eof())
             {
                 kint.pop_back(); // kadangi vieta buvo sukurta naujam elementui, bet jo nebus, tada sumaziname vienu dydziu
                 break;
             }
             fileRead >> kint.at(stud_sk).pavarde;
             sum = 0;
             for (int i = 0; i < *pazymiu_sk; i++)
             {

                 fileRead >> temp;
                 sum = sum + temp;
                 kint.at(stud_sk).nd.push_back(temp);


             }
             fileRead >> kint.at(stud_sk).egz;
             if (x == -1)
             {
                 kint.at(stud_sk).galutinis = Mediana(kint.at(stud_sk).nd) * 0.4 + 0.6 * kint.at(stud_sk).egz;
             }
             else
             {
                 kint.at(stud_sk).galutinis = Vidurkis(kint.at(stud_sk).nd, sum) * 0.4 + 0.6 * kint.at(stud_sk).egz;
             }
             stud_sk++;
         }
    }
    catch (int e)
    {
    
        std::cout << "Patikrinkite faila: " << e << std::endl;


    }

}