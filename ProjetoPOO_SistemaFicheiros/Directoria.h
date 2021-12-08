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
	list<Directoria*> Dirs;
	list<Ficheiro*> Ficheiros;
public:
	Directoria();
	~Directoria();
	int countFiles();
	int countDirs();
	bool processDir(const string& path,Directoria* nowDir);
	void treeView(int nivel);
	string* dirMaisElementos(Directoria* big,int count);

private:

};

#endif