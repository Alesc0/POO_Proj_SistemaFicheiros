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
	Directoria(string _nome,string data, Directoria* _parent = nullptr);
	~Directoria();
	string getTipo();
	int countFiles();
	int countDirs();
	bool processItems(const string& path);
	void Tree(int nivel = 0);
	int dirMaisElementos(string*& dir, int c = 0);
	int dirMenosElementos(string*& dir, int c = -1);
	int fichMaior(string*& fich, int c = 0);
	int getSize();
	int DirectoriaMaisEspaco(string& dir, int c = 0);
	void Search(const string& s, int Tipo, string& path);
	bool RemoverAll(const string& s, const string& tipo, int del = 0);
	bool MoveFicheiro(const string& Fich, const string& DirNova);
	void findFile(string fich, Ficheiro* &fileptr);
	void findDir(string dir, Directoria* &dirptr);
	bool MoverDirectoria(const string& DirOld, const string& DirNew);
	string* DataFicheiro(const string& ficheiro);
	void RenomearFicheiros(const string& fich_old, const string& fich_new);

private:

};

#endif