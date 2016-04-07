#include "Slav.h"
#include <fstream>

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
{
	static int amountOfNames = (init(), names.size()); 
	/*
	Proces nazywa się leniwą inicjalizacją, polega on na tym,że opóźnieniu tworzenia obiektu do momentu gdy bedzię on potrzebny. 
	W tym przypadku najpierw zostanie wywołana funkcja init() a następnie zmienna statyczna amountofNames zostanie zaincjalizowana 
	wartoscią zwróconą przez funkcję size() należącą do klasy names zostanie
	*/
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

int Slav::sex()
{
		if(_name.back() == 'a') return female;
		return male;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}
