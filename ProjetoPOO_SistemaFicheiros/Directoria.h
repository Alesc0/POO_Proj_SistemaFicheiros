#ifndef DIRECTORIA_H
#define DIRECTORIA_H

#include <iostream>
#include <algorithm>
#include <list>
#include "Ficheiro.h"
#include "ObjetoGeral.h"

using namespace std;

class Directoria : public ObjetoGeral
{
	Directoria* parent;
	list<ObjetoGeral*> Items;
public:
	Directoria();
	~Directoria();
	//int countFiles();
	//int countDirs();
	bool processItems(const string& path, Directoria* nowDir);
	virtual void treeView(int nivel);

private:

};

#endif