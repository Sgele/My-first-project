#include "Generavimas.h"

int random_sk()
{
	int r = rand() % 10 + 1;
	return r;
}

vector<int> auto_marks(int kiek_pazymiu)
{
	vector<int> skaiciai;
	for (int i = 0; i < kiek_pazymiu; i++)
	{
		skaiciai.push_back(random_sk());
	}
	return skaiciai;
}

double galut(vector<int> skaiciai) {
	
	
	student stud;
	stud.galutinis = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * random_sk();
	return stud.galutinis;
}

int generavimas(vector<int> pazymiai)
{
	int kiekis;
	cout << "Iveskite studentu kieki: " << endl;
	cin >> kiekis;
	string pavadinimas = "Kursiokai_" + to_string(kiekis) + ".txt";
	auto start = chrono::high_resolution_clock::now();
	ofstream out_data(pavadinimas);
	vector<int> skaiciai;
	student stud;
	out_data << setw(20) << left << "Vardas"
		<< setw(20) << left << "Pavarde"
		<< setw(20) << left << "Galutinis(Vid.)" << endl;

	srand(int(time(0)));
	for (int s = 1; s <= kiekis; s = s + 1)
	{
		
		skaiciai = auto_marks(5);
		out_data << setw(20) << "Vardas" + to_string(s) << setw(20) << "Pavarde" + to_string(s) <<
			setw(18) << galut(skaiciai) << endl;
		skaiciai.clear();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> skirt = end - start;
	cout << "Failo su " + to_string(kiekis) + " irasu kurimas uztruko: " << skirt.count() << " s\n";

	return kiekis;
}

void Read(vector<student>& stud, int kiekis)
{
	int studentu_sk = 0;
	ifstream failoSkait;
	string pavadinimas = "Kursiokai_" + to_string(kiekis) + ".txt";
	string buff;
	failoSkait.open(pavadinimas);
	if (failoSkait.is_open())
	{
		auto start = chrono::high_resolution_clock::now();
		getline(failoSkait >> ws, buff);
		while (studentu_sk < kiekis)
		{
			stud.resize(stud.size() + 1);
			failoSkait >> stud.at(studentu_sk).vardas;
			failoSkait >> stud.at(studentu_sk).pavarde;
			failoSkait >> stud.at(studentu_sk).galutinis;
			studentu_sk++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> skirt = end - start;
		cout << "Failo su " + to_string(kiekis) + " irasu nuskaitymas uztruko: " << skirt.count() << " s\n";
	}
}

