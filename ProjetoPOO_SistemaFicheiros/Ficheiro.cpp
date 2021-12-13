#include "Ficheiro.h"

Ficheiro::Ficheiro()
{
}

Ficheiro::~Ficheiro()
{
}

void FileSpaces(int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
	}
}

void Ficheiro::treeView(int nivel)
{
	FileSpaces(nivel);
	cout << returnNome() << endl;
}

int Ficheiro::countFiles()
{
	return 1;
}
