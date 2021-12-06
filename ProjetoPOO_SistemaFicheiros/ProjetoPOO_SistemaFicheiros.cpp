#include <iostream>
#include <string>
#include <dirent.h>

#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"

using namespace std;

int main()
{
	SistemaFicheiros SF;
	int i = 0, r = 0;
	bool loadCheck = SF.Load("C:/Users/Pedro/Desktop/POOPROJ");

	cout << SF.outRoot()->countDirs() << endl;



	return 0;
}