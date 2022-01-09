#ifndef FICHEIRO_H
#define FICHEIRO_H
#include <iostream>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include "ObjetoGeral.h"
#include "Directoria.h"

using namespace std;

class Directoria;

class Ficheiro : public ObjetoGeral
{
	int tamanho = 0;
public:
	Ficheiro(string _nome, Directoria* _parent, int _tamanho, string _data);
	~Ficheiro();
	virtual string getTipo();
	void Tree(int nivel);
	void TreeToFile(const string* file,ofstream &stream, int nivel = 0);
	int countFiles();
	int countDirs();
	int dirMaisElementos(string& dir, int c = 0);
	int dirMenosElementos(string& dir, int c = 0);
	int fichMaior(string& fich, int c = 0);
	void setTamanho(int _tamanho);
	int getSize();
	int DirectoriaMaisEspaco(string& dir, int c);
	bool RemoverAll(const string& s, const string& tipo, int del = 0);
	bool MoveFicheiro(const string& Fich, const string& DirNova);
	void findFile(string fich, Ficheiro*& fileptr);
	void findDir(string dir, Directoria*& dirptr);
	bool MoverDirectoria(const string& DirOld, const string& DirNew);
	bool dirInsideDir(Directoria* dirB);
	void RenomearFicheiros(const string& fich_old, const string& fich_new);
	void FicheiroDuplicados(list<string>& l, bool &_found);
	void PesquisarAllFicheiros(list<string>& lres, const string& file);
	void PesquisarAllDirectorias(list<string>& lres, const string& dir);
private:

};

#endif 