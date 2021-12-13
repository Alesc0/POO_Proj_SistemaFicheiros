#include "ObjetoGeral.h"

ObjetoGeral::ObjetoGeral()
{
}

ObjetoGeral::~ObjetoGeral()
{
}
void ObjetoGeral::setNome(string _nome)
{
	nome = _nome;
}

string ObjetoGeral::returnNome()
{
	return nome;
}

void ObjetoGeral::treeView(int nivel)
{
}

int ObjetoGeral::countFiles()
{
	return 0;
}

int ObjetoGeral::countDirs()
{
	return 0;
}
