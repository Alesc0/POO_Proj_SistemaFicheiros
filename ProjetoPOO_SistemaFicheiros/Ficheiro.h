#ifndef FICHEIRO_H
#define FICHEIRO_H
#include <iostream>
#include <algorithm>
#include "ObjetoGeral.h"
#include "Directoria.h"

using namespace std;

class Directoria;

class Ficheiro : public ObjetoGeral
{
	int tamanho;
public:
	Ficheiro();
	~Ficheiro();
	void treeView(int nivel);
	int countFiles();
	int dirMaisElementos(string*& dir, int c = 0);
	int dirMenosElementos(string*& dir, int c = 0);
	int fichMaior(string*& fich, int c = 0);
	void setTamanho(int _tamanho);
	int getSize();
	int DirectoriaMaisEspaco(int c, string*& dir);
private:

};

#endif 