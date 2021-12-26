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
	int tamanho = 0;
public:
	Ficheiro();
	~Ficheiro();
	virtual string getTipo();
	void treeView(int nivel);
	int countFiles();
	int dirMaisElementos(string*& dir, int c = 0);
	int dirMenosElementos(string*& dir, int c = 0);
	int fichMaior(string*& fich, int c = 0);
	void setTamanho(int _tamanho);
	int getSize();
	int DirectoriaMaisEspaco(string& dir, int c);
	void Search(const string& s, int Tipo, string& path);
	bool RemoverAll(const string& s, const string& tipo,int del = 0);
private:

};

#endif 