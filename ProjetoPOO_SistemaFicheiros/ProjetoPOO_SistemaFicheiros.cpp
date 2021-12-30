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
	//bool loadCheck = SF.ReadXml("C:\\Users\\Sheep\\Desktop\\Repositories\\POO_Proj_SistemaFicheiros\\ProjetoPOO_SistemaFicheiros\\XML.xml");
	//SF.getRoot()->Tree();
	Directoria* idk = new Directoria("ola", "idk");
	Ficheiro* idk2 = new Ficheiro("nome", idk, 50, "32312");
	list<ObjetoGeral*> asdasd;
	asdasd.push_back(idk2);
	idk->setItems(asdasd);
	for (list<ObjetoGeral*>::iterator it= idk->getItems().begin(); it != idk->getItems().end(); it++)
	{
		cout << (*it)->getNome();
	}

	//ObjetoGeral* asd = idk->getItems().begin();
	//cout << asd->getNome();
	
	//XMLHandler x;
	//x.WriteAll(SF.getRoot());
	return 0;
}