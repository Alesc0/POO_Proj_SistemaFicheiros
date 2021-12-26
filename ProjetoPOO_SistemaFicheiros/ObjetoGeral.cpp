#include "ObjetoGeral.h"
#include "Directoria.h"

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

void ObjetoGeral::setParent(Directoria* _dir)
{
	parent = _dir;
}

Directoria* ObjetoGeral::getParent()
{
	return parent;
}

string ObjetoGeral::getNome()
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

void ObjetoGeral::getPath(string* fullpath)
{
	fullpath->insert(0, "\\");
	fullpath->insert(0, getNome());
	Directoria* parent = getParent();
	if (parent != NULL) {
		parent->getPath(fullpath);
	}
}

string ObjetoGeral::getTipo()
{
	return string();
}


