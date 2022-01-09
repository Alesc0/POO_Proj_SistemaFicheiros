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
	bool loadCheck = SF.Load("C:\\Users\\Pedro\\Desktop\\POO_Proj_SistemaFicheiros\\POOPROJ");

	cout << *SF.Search("subsubfolder1",1);

	return 0;
}