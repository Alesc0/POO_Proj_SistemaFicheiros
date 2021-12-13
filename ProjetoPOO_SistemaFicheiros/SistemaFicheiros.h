#ifndef SISTEMAFICHEIROS_H
#define SISTEMAFICHEIROS_H

#include <iostream>
#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"

class SistemaFicheiros
{
	string pathToRoot;
	Directoria* root = NULL;
public:
	SistemaFicheiros();
	~SistemaFicheiros();
	Directoria* outRoot();
	bool Load(const string& path);
	int ContarFicheiros();
	int ContarDirectorias();
	int Memoria();
	string* DirectoriaMaisElementos();
private:

};

#endif