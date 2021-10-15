#include <algorithm>
#include "Mediana.h"

double Mediana(std::vector<double> nd)
{
    size_t size = nd.size();

    if (size == 0)
    {
        return 0;  // jeigu tuscias vektorius
    }
    else
    {
        std::sort(nd.begin(), nd.end());
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