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
	bool loadCheck = SF.Load("C:\\Users\\ProHa\\Desktop\\POO_Proj_SistemaFicheiros\\POOPROJ");

	

	return 0;
}