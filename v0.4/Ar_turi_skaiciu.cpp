#include "Ar_turi_skaiciu.h"
#include "Studentas.h"

bool Ar_turi_skaiciu(std::string s) //tikrinam ar zodyje nera netycia ivestu skaiciu
{
    return (s.find_first_of("0123456789") != std::string::npos);
};