#ifndef DIRECTORIA_H
#define DIRECTORIA_H

#include <iostream>
#include <algorithm>
#include <list>
#include "Ficheiro.h"

using namespace std;

class Directoria
{
	string nome;
	Directoria* parent;
	list<Directoria*> Dirs;
	list<Ficheiro*> Ficheiros;
public:
	Directoria();
	~Directoria();
	int countFiles();
	int countDirs();
	void setNome(string nome);
	bool processDir(const string& path,Directoria* nowDir);
	void treeView(int nivel);

private:

};

#endif