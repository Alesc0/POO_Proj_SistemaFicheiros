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
	list<ObjetoGeral*> Items;
public:
	Directoria();
	~Directoria();
	string getTipo();
	int countFiles();
	int countDirs();
	bool processItems(const string& path);
	void treeView(int nivel = 0);
	int dirMaisElementos(string*& dir, int c = 0);
	int dirMenosElementos(string*& dir, int c = -1);
	int fichMaior(string*& fich, int c = 0);
	int getSize();
	int DirectoriaMaisEspaco(string& dir, int c = 0);
	void Search(const string& s, int Tipo,string &path);
	bool RemoverAll(const string& s, const string& tipo,int del = 0);

private:

};

#endif