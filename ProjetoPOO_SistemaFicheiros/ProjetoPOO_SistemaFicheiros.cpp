#include <iostream>
#include <string>
#include <dirent.h>

#include <list>
#include "ObjetoGeral.h"
#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"
#include "XMLHandler.h"

using namespace std;

int main()
{
	SistemaFicheiros SF;
	bool loadCheck = SF.Load("C:\\Users\\Pedro\\Desktop\\POO_Proj_SistemaFicheiros\\POOPROJ");

	//SF.Tree();
	cout << *SF.FicheiroMaior();
	SF.Tree();

	return 0;
}