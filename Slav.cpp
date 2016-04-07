#include "Slav.h"
#include <fstream>
#include <iterator>

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{	/*Do amountOfNames przypisywana jest liczba wczytanych słowian (wartość zwracana przez
	funkcję size()). Odbywa się to tylko raz
	ponieważ przed wyrażeniem znajduje się "static". Tworzenie tego obiektu jest opóźnione.
	Proces ten nazywany jest leniwym inicjowaniem */
	
	static int amountOfNames = (init(), names.size()); 
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

/*sex Slav::slav_sex()
{
	for(int i = 0; i < _counter; i++)
	{
		return (*_name.end()=="a")?female:male;
	}
}*/

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}