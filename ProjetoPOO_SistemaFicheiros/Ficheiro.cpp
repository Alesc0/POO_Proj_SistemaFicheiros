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
	cout << getNome() << "---(" << tamanho << ")" << endl;
}

int Ficheiro::countFiles()
{
	return 1;
}

int Ficheiro::dirMaisElementos(string*& dir, int c)
{
	return c;
}
int Ficheiro::dirMenosElementos(string*& dir, int c)
{
	return c;
}

int Ficheiro::fichMaior(string*& fich, int c)
{
	int atualc = tamanho;

	if (atualc > c) {
		c = atualc;
		fich = new string(this->getNome());
	}
	return c;
}

void Ficheiro::setTamanho(int _tamanho)
{
	tamanho = _tamanho;
}

int Ficheiro::getSize()
{
	int _size = 0;
	_size += getNome().size();
	_size += sizeof(tamanho);
	_size += sizeof(getParent());
	return _size;
}

int Ficheiro::DirectoriaMaisEspaco(int c, string*& dir)
{
	return 1;
}

