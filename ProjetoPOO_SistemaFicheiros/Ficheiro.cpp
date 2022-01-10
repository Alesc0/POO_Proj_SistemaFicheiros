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


void Ficheiro::Tree(int nivel)
{
	cout << Spaces(nivel) << getNome() << endl;
}

void Ficheiro::TreeToFile(const string* file, ofstream& stream, int nivel)
{
	string h = Spaces(nivel) + getNome() + "---(" + to_string(tamanho) + ")" + getData() + "\n";
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

void Ficheiro::dirMaisElementos(Directoria*& dir)
{
}

void Ficheiro::dirMenosElementos(Directoria*& dir)
{
}

void Ficheiro::fichMaior(Ficheiro*& fich)
{
	if (!fich || tamanho > fich->tamanho) {
		fich = this;
	}
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

bool Ficheiro::RemoverAll(const string& s, const string& tipo, int del)
{
	if (del)
		delete this;
	return true;
}

void Ficheiro::removerRecursive(string tipo)
{
	delete this;
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

void Ficheiro::findAllFiles(string str, list<Ficheiro*>& lst)
{
	if (strstr(getNome().c_str(), str.c_str())) {
		lst.push_back(this);
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

