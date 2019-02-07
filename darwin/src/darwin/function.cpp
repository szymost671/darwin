#include "pch.h"
#include "Header.h"

using namespace std;

void showPopulation(individual *population)
{
	individual *temp = population;
	cout << "\nPopulacja: " << endl;
	while (temp != NULL)
	{
		cout << " - ID osobnika: " << temp->id + 1 << "\n";
		cout << " - Chromosom osobnika: ";
		chromosomePart *nextValue = temp->chromosome;
		while (nextValue != NULL)
		{
			cout << nextValue->value << " ";
			nextValue = nextValue->next;
		}
		temp = temp->next;
		cout << endl;
	}
}

void crossPopulation(individual **population, int items, int p)
{
	int howMuch = 0;														//ilość elementów  w chromosomie
	int quantity = 0;														//stworzono by wyznaczyć miejsce złamania chromosomu
	
	for (int i = 0; i < p; i++)
	{
		individual *temp = *population;
		cout << "\nPOPULACJA " << i+1 << "GO POKOLENIA: \n\n";
		while (temp != NULL)
		{
			cout << "Chromosom "<< temp->id + 1 <<"-go osobnika: \n";
			chromosomePart *nextValue = temp->chromosome;
			while (nextValue != NULL)
			{
				nextValue = nextValue->next;
				howMuch++;													//sprawdzamy ile jest elementów  w chromosomie
			}
			quantity = rand() % howMuch;
			do{
				quantity = rand() % howMuch;
			} while (quantity == 0 | quantity == howMuch);
			cout << "Zlamanie nastapilo po " << quantity << " elemencie chromosomu\n";
			randW();
			randR();
			randD();
																			//TUTAJ NASTĘPUJE WYSYŁANIE ELEMENTÓW CHROMOSOMU PO QUANTITY DO NASTĘPNEGO OSOBNIKA  
			temp = temp->next;
			cout << endl;
			howMuch = 0;
		}

	}
}

void in(individual **population, string inputFilename, int &items)
{
	fstream handler;
	handler.open(inputFilename, ios::in);
	if (handler.good() == true)
	{
		string line;
		while (!handler.eof())
		{
			individual *newIndividual = new individual;
			newIndividual->next = NULL;
			getline(handler, line);
			stringstream stream(line);
			newIndividual->chromosome = new chromosomePart;
			newIndividual->chromosome->next = NULL;
			newIndividual->id = items;
			stream >> newIndividual->chromosome->value;

			while (1)
			{
				int value;
				stream >> value;
				if (!stream)
					break;
				chromosomePart *temp = newIndividual->chromosome;
				chromosomePart *newChromosome = new chromosomePart;
				newChromosome->value = value;
				newChromosome->next = NULL;

				while (temp->next)
				{
					temp = temp->next;
				}

				temp->next = newChromosome;
			}

			chromosomePart *temp = newIndividual->chromosome;
			while (temp != NULL)
			{
				temp = temp->next;
			}
																						//new individual

			if (items == 0)
			{
				*population = newIndividual;
			}
			else
			{
				individual *individualTemp = *population;
				while (individualTemp->next != NULL)
				{
					individualTemp = individualTemp->next;
				}
				individualTemp->next = newIndividual;

			}
			items++;																	//ilość elementów w chromosomie
		}
	}
	else
	{
		cout << "Plik nie istnieje" << endl;
	}
	randK(items);
	handler.close();
	showPopulation(*population);
}

void h()
{
	cout << "KROTKA POMOC:\nDostepne paramatry:\n-i(plik wejsciowy z populacja)\n-o(plik wyjsciowy z populacja)\n-w(wspolczynnik wymierania w ∈ [0, 1])\n-r(wspolczynnik rozmnazania r ∈ [0, 1])\n-p(liczba pokolen p)\n-k(liczba k par osobnikow losowanych do krzyzowania)\n";
}

void out(individual *population, string outputFilename)
{
	fstream handler;
	handler.open(outputFilename, ios::trunc | ios::out);

	individual *temp = population;
	while (temp != NULL)
	{
		chromosomePart *nextValue = temp->chromosome;
		while (nextValue != NULL)
		{
			handler << nextValue->value << " ";
			nextValue = nextValue->next;
		}
		handler << endl;
		temp = temp->next;
	}

	if (handler.good() == true)
	{
		cout << "\n\nZapisano liste osobnikow do pliku: " << outputFilename << "\n\n" << endl;
	}
	else
	{
		cout << "Plik nie istnieje" << endl;
	}
	handler.close();
}

void randW()																				//wsp wymieralnosci
{
	int min = 0;
	int max = 100;
	int draw = rand() % (max - min + 1) + min;												//draw = losowa
	float w = draw / 100.0f;

	cout <<"Wspolczynnik wymieralnosci wynosi: "<< w <<endl;
}

void randR()																				//wsp rozmnazania
{
	int min = 0;
	int max = 100;
	int draw = rand() % (max - min + 1) + min;												//draw = losowa
	float r = draw / 100.0f;

	cout << "Wspolczynnik rozmnazania wynosi: " << r << endl;
}

void randK(int items)																		//ilosc par do krzyzowania
{
	srand(time(NULL));
	int pairs = rand()%items;
	cout << "Ilosc wylosowanych par: " << pairs <<endl;
}

void randD()																				//wsp dopasowania
{
	int min = 0;
	int max = 100;
	int draw = rand() % (max - min + 1) + min;												//draw = losowa
	float d = draw / 100.0f;
	cout << "Wspolczynnik dopasowania wynosi: " << d << endl;
}

