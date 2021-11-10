#include "functions.h"

void ivedimas_struct(vector<studentas>&studentai,int kiek)
{

    clock_t begin = clock();
    ifstream failas;
    //vector<studentas> studentai(kiek + 10);
    string pavadinimas = "studentai" + to_string(kiek) + ".txt";
    failas.open(pavadinimas);
    int temp;
    for (float i = 0; i < kiek; i++)
    {
        studentas st;
        failas >> st.vardas >> st.pavarde;
        for (int i = 0; i < 5;i++)
        {
            failas >> temp;
            st.nd.push_back(temp);
        }
        failas >> st.egz;
        failas >> st.rezultatas;
        studentai.push_back(st);
    }
    failas.close();
    cout << studentai.size() << endl;
    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout << kiek << " failo nuskaitymo trukme: " << laikas_sekundemis << " sec." << endl;

}

void dalijimas_struct(vector<studentas> &studentai)
{
    int dydis = studentai.size();
    // Dalijimas
    clock_t begin = clock();
    vector<studentas> kvaili;
    vector<studentas> protingi;
    for (double i = dydis; i > 0; i--)
    {
        studentas stud = studentai.back();
        studentai.pop_back();
        if (stud.egz < 5)
        {
            kvaili.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }
        kvaili.shrink_to_fit();
        protingi.shrink_to_fit();

    }
    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout << dydis << " failo dalijimo trukme: " << laikas_sekundemis << " sec." << endl;
    kvaili.clear();
    protingi.clear();


}

void testuoti_struct(int kiek)
{
    clock_t begin = clock();

    vector<studentas> studentai;
    studentai.reserve(kiek + 10);
    ivedimas_struct(studentai,kiek);

    dalijimas_struct(studentai);

    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << endl;
}

list<studentas> ivedimas_list(int kiek)
{
    clock_t begin = clock();
    ifstream failas;
    list<studentas> studentai;
    string pavadinimas = "studentai" + to_string(kiek) + ".txt";
    failas.open(pavadinimas);
    int temp;
    for (int i = 0; i < kiek; i++)
    {
        studentas st;
        failas >> st.vardas >> st.pavarde;
        for (int i = 0; i < 5;i++) {
            failas >> temp;
            st.nd.push_back(temp);
        }
        failas >> temp;
        st.egz = temp;
        failas >> temp;
        st.rezultatas = temp;
        studentai.push_back(st);
    }
    failas.close();

    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout << kiek << " failo nuskaitymo trukme: " << laikas_sekundemis << " sec." << endl;
    return studentai;
}

void dalijimas_list(list<studentas> studentai)
{
    int dydis = studentai.size();
    // Dalijimas
    clock_t begin = clock();
    list<studentas> kvaili;
    list<studentas> protingi;
    for (int i = 0; i < dydis; i++)
    {
        studentas stud = studentai.back();
        studentai.pop_back();
        if (stud.egz < 5)
        {
            kvaili.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }


    }
    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout << dydis << " failo dalijimo trukme: " << laikas_sekundemis << " sec." << endl;


}

void testuoti_list(int kiek)
{
    clock_t begin = clock();

    list<studentas> studentai = ivedimas_list(kiek);

    dalijimas_list(studentai);

    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;

    cout << endl;
}
