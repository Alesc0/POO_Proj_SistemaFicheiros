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
	SF.RemoverAll("POOPROJ","asd");
	SF.Tree();

	return 0;
}