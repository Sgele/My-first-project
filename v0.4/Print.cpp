#include "Print.h"


void Print(studentas& kint) //spausdinimo funkcija
{
    cout << left << setw(20) << kint.pavarde << setw(20) << kint.vardas << setw(15) << setprecision(3) << kint.galutinis << endl;

}