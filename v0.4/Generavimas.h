#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <chrono>
#include <stdio.h>      /
#include <stdlib.h>     
#include <time.h>   
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


struct student {
	string vardas, pavarde;
	vector <int> nd;
	double egzaminas;
	double galutinis;
};

int random_sk();
double galut(vector<int> skaiciai);
int generavimas(vector<int> pazymiai);
void Read(vector<student>& stud, int kiekis);
