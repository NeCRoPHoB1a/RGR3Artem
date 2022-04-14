#include "iostream"
#include "fstream"
#include "string"
#include <vector>
#include <algorithm>



using namespace std;
ifstream f("1.txt");

struct chell
{

	string fname, sname, lname;
	string date;
	float match, goal, pas, yell, red;
	void print();
	float r;
	void res();
};

void chell::print()
{
	cout << fname << " " << sname << " " << lname << " " << r << endl;
}
void chell::res()
{
	 r = ((goal + pas) / match)*100;//переделай под что она скажет
}


int main()
{
	system("chcp 1251");
	int n = 0;
	string s, l;

	vector<chell> list;
	chell b;
	while (f.peek() != EOF)
	{
		list.push_back(b);
		getline(f, l);
		list[n].fname = l;
		getline(f, l);
		list[n].sname = l;
		getline(f, l);
		list[n].lname = l;
		getline(f, l);
		list[n].date = l;
		getline(f, l);
		list[n].match = stof(l);
		getline(f, l);
		list[n].goal = stof(l);
		getline(f, l);
		list[n].pas = stof(l);
		getline(f, l);
		list[n].yell = stof(l);
		getline(f, l);
		list[n].red = stof(l);
		list[n].res();
		n++;
		getline(f, l);
	}

	sort(list.begin(), list.end(), [](const chell& lhs, const chell& rhs) {return lhs.r > rhs.r; });
	for (int i=0; i < 6; i++)list[i].print();
	cout << "---------------------------------\n";
	for (int i=0; i < list.size(); i++)if(list[i].red>0)list[i].print();
	system("Pause");
}
/*Сведения об игроках футбольной команды включают : Ф.И.О.игрока, дату рождения,
количество сыгранных матчей, число забитых мячей, количество голевых передач, количество
желтых карточек, количество красных карточек.
Вывести 6 лучших игроков(голы + передачи) с указанием их результативности.Вывести всех
игроков, имеющих в активе красные карточки*/
