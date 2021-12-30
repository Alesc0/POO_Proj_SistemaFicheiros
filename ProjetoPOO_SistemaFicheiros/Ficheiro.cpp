#include "Ficheiro.h"
#include <string>
#include <iostream>
#include <fstream>

Ficheiro::Ficheiro(string _nome, Directoria* _parent, int _tamanho, string _data)
{
	setNome(_nome);
	setParent(_parent);
	setData(_data);
	tamanho = _tamanho;
}

Ficheiro::~Ficheiro()
{
}

string FileSpaces(int n) {
	string spaces = "";
	for (int i = 0; i < n; i++)
	{
		spaces.append("\t");
	}
	return spaces;
}

void Ficheiro::Tree(int nivel)
{
	FileSpaces(nivel);
	string h = getData();
	cout << getNome() << "---(" << tamanho << ")" << h << endl;

}

void Ficheiro::TreeToFile(const string* file, ofstream& stream, int nivel)
{
	string h = FileSpaces(nivel) + getNome() + "---(" + to_string(tamanho) + ")" + getData() + "\n";
	stream << h;
}

int Ficheiro::countFiles()
{
	return 1;
}

int Ficheiro::countDirs()
{
	return 0;
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

		_path = getPath();
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

bool Ficheiro::dirInsideDir(Directoria* dirB)
{
	return false;
}

void Ficheiro::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
	if (getNome() == fich_old)
		setNome(fich_new);
}

void Ficheiro::FicheiroDuplicados(list<string>& l, bool& _found)
{
	for (list<string>::iterator it = l.begin(); it != l.end(); it++)
	{
		if (*it == getNome())
			_found = true;
	}
	if (!_found)
		l.push_back(getNome());

}

void Ficheiro::PesquisarAllFicheiros(list<string>& lres, const string& file)
{
	if (file == getNome())
	{
		lres.push_back(getPath());
	}
}

void Ficheiro::PesquisarAllDirectorias(list<string>& lres, const string& dir)
{
}


string Ficheiro::getTipo()
{
	return typeid(this).name();
}

