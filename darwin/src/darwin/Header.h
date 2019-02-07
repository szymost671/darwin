#include <iostream>
#include <cstdlib>
#include <stdlib.h>  
#include <time.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

struct chromosomePart {
	int value;
	chromosomePart *next;	//wskaznik na kolejny element
};

struct individual {
	int id;
	chromosomePart *chromosome;
	individual *next;
};

void in(individual **population, string inputFilename, int &items);
void out(individual *population, string outputFilename);
void crossPopulation(individual **population, int items, int p);
void randW();
void randR();
void randK(int items);
void randD();
void h();
