#include "functions.h"
using namespace std;


int main()
{
    //struct timespec ts; //fast seeded
    //clock_gettime(CLOCK_MONOTONIC, &ts); //fast seeded
    //srand((time_t)ts.tv_nsec); //fast seeded
    srand(int(time(NULL))); // seeded
    cout << "STRUCT TESTAVIMAS" << endl;
    testuoti_struct(1000);
    testuoti_struct(10000);
    testuoti_struct(100000);
    //testuoti_struct(1000000);
    //testuoti_struct(10000000);

    cout << "LIST TESTAVIMAS" << endl;
    testuoti_list(1000);
    testuoti_list(10000);
    testuoti_list(100000);
    testuoti_list(1000000);
    //testuoti_list(10000000);

    return 0;
}
