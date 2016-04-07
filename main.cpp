// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>

#include "Slav.h"
#include <string>

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void mapBySex(Slav *, int);


int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	mapBySex(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	
	for(int i = 0; i < n; i++)
		vectorOfSlavs.insert(vectorOfSlavs.begin() + rand()%(vectorOfSlavs.size() + 1), slavs+i);
		
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze

	for(vector <Slav *>::iterator iVectorOfSlavs = vectorOfSlavs.begin(); iVectorOfSlavs < vectorOfSlavs.end();iVectorOfSlavs++)
		cout << (*iVectorOfSlavs)->description() << endl;
	

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.

	for(int i = 0; i < n; i++)
	{
		setOfSlavs.insert(vectorOfSlavs.back());
		vectorOfSlavs.pop_back();
	}

	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	for(set <Slav *>::iterator iSetOfSlavs = setOfSlavs.begin(); iSetOfSlavs != setOfSlavs.end();iSetOfSlavs = setOfSlavs.erase(iSetOfSlavs))
		mapOfSlavs[*iSetOfSlavs] = *(iSetOfSlavs=(setOfSlavs.erase(iSetOfSlavs)));


	// Wykorzystując iterator, wyświetl wszystkie pary Słowian

	for(map <Slav *, Slav*>::iterator iMapOfSlavs = mapOfSlavs.begin(); iMapOfSlavs != mapOfSlavs.end(); iMapOfSlavs++)
		cout << (iMapOfSlavs->first)->description() << " " << (iMapOfSlavs->second)->description()<< endl;
	
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i = 0; i < n; i++)
		queueOfSlavs.push(slavs+i);
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	for(int i = 0; i < n; i++)
		{
			stackOfSlavs.push(queueOfSlavs.front());
			queueOfSlavs.pop();
		}

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.

	for(int i = 0; i < n; i++)
	{
		cout << stackOfSlavs.top()->description() << endl;
		stackOfSlavs.pop();
	}



	REPORT_ADAPTERS;
}

void mapBySex(Slav * slavs, int n)
{
	map <_sex, vector <Slav*>> _mapBySex;
	for(int i=0; i < n; i++)
	{
		if(slavs[i].sex() == male)
			_mapBySex[male].push_back(slavs + i);
		else
			_mapBySex[female].push_back(slavs + i);
	}
	cout << "Males:" <<endl;
	for(vector <Slav*>::iterator iMapBySex = _mapBySex[male].begin(); iMapBySex != _mapBySex[male].end(); iMapBySex++)
		cout << (*iMapBySex)->description() << endl;
	cout << "Females:" <<endl;
	for(vector <Slav*>::iterator iMapBySex = _mapBySex[female].begin(); iMapBySex != _mapBySex[female].end(); iMapBySex++)
		cout << (*iMapBySex)->description() << endl;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
