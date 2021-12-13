#ifndef FICHEIRO_H
#define FICHEIRO_H
#include <iostream>
#include <algorithm>
#include "ObjetoGeral.h"

using namespace std;

class Ficheiro: public ObjetoGeral
{
public:
	Ficheiro();
	~Ficheiro();
	virtual void treeView(int nivel);
	virtual int countFiles();

private:

};

#endif 