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

	//SF.Tree();
	SF.CopyBatch("folder","folder 1","folder 2");
	SF.Tree();

	return 0;
}