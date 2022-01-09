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
	int i = 0, r = 0;
	
	//bool loadCheck = SF.Load("C:\\Users\\Pedro\\Desktop\\POO_Proj_SistemaFicheiros\\POOPROJ");
	//bool loadCheck = SF.Load("C:\\Users\\Sheep\\Desktop\\Repositories\\POO_Proj_SistemaFicheiros\\POOPROJ");
	//SF.ReadXml("C:\\Users\\Sheep\\Desktop\\Repositories\\POO_Proj_SistemaFicheiros\\ProjetoPOO_SistemaFicheiros\\XML.xml");

	SF.getRoot()->Tree();

	return 0;
}