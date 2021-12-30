#ifndef SISTEMAFICHEIROS_H
#define SISTEMAFICHEIROS_H

#include <iostream>
#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"
#include <list>

class SistemaFicheiros
{
	string pathToRoot;
	Directoria* root = NULL;
public:
	SistemaFicheiros();
	~SistemaFicheiros();
	Directoria* getRoot();
	string getRootPath();
	bool Load(const string& path);
	int ContarFicheiros();
	int ContarDirectorias();
	int Memoria();
	string* DirectoriaMaisElementos();
	string* DirectoriaMenosElementos();
	string* DirectoriaMaisEspaco();
	string* Search(const string& s, int Tipo);
	bool RemoverAll(const string& s, const string& tipo);
	bool MoveFicheiro(const string& Fich, const string& DirNova);
	bool MoverDirectoria(const string& DirOld, const string& DirNew);
	string* DataFicheiro(const string& ficheiro);
	void RenomearFicheiros(const string& fich_old, const string& fich_new);
	bool FicheiroDuplicados();
	void PesquisarAllFicheiros(list<string>& lres, const string& file);
	void PesquisarAllDirectorias(list<string>& lres, const string& dir); 
	void Tree(const string* fich = nullptr);
private:

};

#endif