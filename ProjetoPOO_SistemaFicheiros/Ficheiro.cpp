#include "Ficheiro.h"
#include <string>
#include <fstream>

Ficheiro::Ficheiro(string _nome, Directoria* _parent, int _tamanho, string _data)
{
	setNome(_nome);
	setParent(_parent);
	setData(_data);
	tamanho = _tamanho;
}
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

void Ficheiro::Tree(int nivel)
{
	FileSpaces(nivel);
	string h = getData();
	cout << getNome() << "---(" << tamanho << ")" << h << endl;
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
	_size += getData().size();
	return _size;
}

int Ficheiro::DirectoriaMaisEspaco(string& dir, int c)
{
	return getSize();
}

void Ficheiro::Search(const string& s, int Tipo, string& _path)
{
	string* path = new string();
	if ((Tipo == 0) && (getTipo() == typeid(Ficheiro*).name())) {
		getPath(path);
		_path = *path;
	}
}

bool Ficheiro::RemoverAll(const string& s, const string& tipo, int del)
{
	if (del)
		delete this;
	return true;
}

bool Ficheiro::MoveFicheiro(const string& Fich, const string& DirNova)
{
	return false;
}

void Ficheiro::findFile(string fich, Ficheiro*& fileptr)
{
	if (getNome() == fich) {
		fileptr = this;
	}
}

void Ficheiro::findDir(string fich, Directoria*& dirptr)
{
	return;
}

bool Ficheiro::MoverDirectoria(const string& DirOld, const string& DirNew)
{
	return false;
}

void Ficheiro::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
	if (getNome() == fich_old)
		setNome(fich_new);
}

string Ficheiro::getTipo()
{
	return typeid(this).name();
}

bool Ficheiro::Writing(Directoria* dir, ostream& f, int nmrTabs=0) {
	string x = "";
	for (int i = 0; i < nmrTabs; i++)
	{
		x += "\t";
	}
	string y = "";
	for (int i = 0; i < nmrTabs; i++)
	{
		y += "\t";
	}
	f << x << "<ficheiro>" << endl;
	f << y << "<nome>" << this->getNome() << "</nome>" << endl;
	f << y << "<data>" << this->getData() << "</data>" << endl;
	f << y << "<tamanho>" << this->getSize() << "</tamanho>" << endl;
	f << x << "</ficheiro>" << endl;
	return true;
}

