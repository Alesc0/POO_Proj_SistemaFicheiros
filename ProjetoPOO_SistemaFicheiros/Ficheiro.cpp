#include "Ficheiro.h"
#include <iostream>
#include <algorithm>

void Ficheiro::setNome(string _nome)
{
	nome = _nome;
}

string Ficheiro::returnNome()
{
	return nome;
}

Ficheiro::Ficheiro()
{
}

Ficheiro::~Ficheiro()
{
}