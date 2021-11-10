#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <random>
#include <list>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd = { 0 };
    int egz;
    float rezultatas;
};

void ivedimas_struct(vector<studentas>&studentai,int kiek);
void dalijimas_struct(vector<studentas> &studentai);
void testuoti_struct(int kiek);
list<studentas> ivedimas_list(int kiek);
void dalijimas_list(list<studentas> studentai);
void testuoti_list(int kiek);
