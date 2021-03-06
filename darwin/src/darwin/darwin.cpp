#include "pch.h"
#include "Header.h"

using namespace std;

int main(int argc, char *argv[])
{
	individual *population = new individual;
	population->next = NULL;
	population->chromosome = NULL;

	int items = 0; //licznik osobników
	float r = 0.0;
	float w = 0.0;
	int k = 0;
	int p = 0;
	string inputFilename = "";
	string outputFilename = "";


	cout << "Witaj w projekcie DARWIN" << endl <<endl;
	if (argc<7)
	{
		cout << "Zbyt mala ilosc parametrow! \n";
		h();
	}
	else 
	{
		for (int i = 1; i < argc; i++)
		{

			string arg = argv[i];
			if (arg == "-i")
			{
				inputFilename = argv[++i];
			}
			if (arg == "-o")
			{
				outputFilename = argv[++i];
			}
			if (arg == "-w")
			{
				//współczynnik wymierania w ∈ [0, 1]
			}
			if (arg == "-r")
			{
				//współczynnik rozmnażania r ∈ [0, 1]
			}
			if (arg == "-p")
			{
				p = atoi(argv[++i]);//konwertowanie z char na int
				//liczba pokoleń p
			}
			if (arg == "-k")
			{
				//tutaj wysyłamy ilość osobników żeby wylosować liczbe par z zakresu od 1 do ilosc osobnikow				!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				//randK();//liczba k par osobników losowanych do krzyżowania
			}
			if (arg == "-h")
			{	
				h();//pomoc wyświetlana po uruchomieniu z tym przełącznikiem
			}
		}
		in(&population, inputFilename, items);//plik wejściowy "population.txt" z populacją	
		crossPopulation(&population, items, p);//funkcja krzyżująca
		out(population, outputFilename);//plik wyjściowy "results.txt" z populacją
	}
	system("Pause");
	return 0;
}


