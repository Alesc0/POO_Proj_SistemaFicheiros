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