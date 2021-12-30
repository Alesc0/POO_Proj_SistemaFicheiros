#include <dirent.h>
#include "Directoria.h"
#include <string>
#include <iostream>
#include <fstream>

Directoria::Directoria(string _nome, string _data, Directoria* _parent)
{
	setNome(_nome);
	setParent(_parent);
	setData(_data);
}

Directoria::~Directoria()
{
	//dtor
}

int Directoria::countFiles()
{
	int c = 0;
	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		c += (*it)->countFiles();
	}
	return c;
}


int Directoria::countDirs()
{
	int c = 1;
	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		c += (*it)->countDirs();
	}
	return c;
}

int Directoria::dirMaisElementos(string*& dir, int c) {
	int atualc = (int)Items.size();

	if (atualc > c) {
		c = atualc;
		dir = new string(this->getNome());
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		c = (*it)->dirMaisElementos(dir, c);
	}
	return atualc;
}

int Directoria::dirMenosElementos(string*& dir, int c) {
	if (c == -1) c = (int)Items.size();
	int atualc = (int)Items.size();

	if (atualc < c) {
		c = atualc;
		dir = new string(this->getNome());
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		c = (*it)->dirMenosElementos(dir, c);
	}
	return atualc;
}

int Directoria::fichMaior(string*& fich, int c)
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		c = (*it)->fichMaior(fich, c);
	}
	return c;
}

int Directoria::getSize()
{
	int _size = 0;
	_size = getNome().size();
	_size += sizeof(getParent());
	_size += getData().size();
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		_size += (*it)->getSize();
	}
	return _size;
}

int Directoria::DirectoriaMaisEspaco(string& dir, int c) {

	int atualc = 0;

	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if ((*it)->getTipo() == typeid(Ficheiro*).name()) {
			atualc += (*it)->DirectoriaMaisEspaco(dir, c);
		}
		else
		{
			c = (*it)->DirectoriaMaisEspaco(dir, c);
		}
	}
	if (atualc > c) {
		c = atualc;
		dir = this->getNome();
	}
	return c;
}

void Directoria::Search(const string& s, int Tipo, string& _path)
{
	//tipo 0 -> ficheiro
	//tipo 1 -> directoria

	if (getNome() == s)
	{
		string* path = new string();

		if ((Tipo == 1) && (getTipo() == typeid(Directoria*).name()))
		{
			_path = getPath();
		}
	}

	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if (_path != "") return;
		(*it)->Search(s, Tipo, _path);
	}
}

bool Directoria::RemoverAll(const string& s, const string& tipo, int del)
{
	string name = getNome();
	string type = "";

	if (name == s)
	{
		del = 1;
	}

	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it)
	{
		type = (*it)->getTipo();
		name = (*it)->getNome();
		(*it)->RemoverAll(s, tipo, del);

		if (name == s)
		{
			del = 2;
		}

		if (del > 0) {
			if (tipo == "DIR") {
				if (type == typeid(Directoria*).name()) {
					delete* it;
					it = Items.erase(it);
					if (del > 1) {
						del = 0;
					}
					continue;
				}
			}
			else
			{
				if (type == typeid(Ficheiro*).name()) {
					it = Items.erase(it);
					continue;
				}
			}
		}
		it++;

	}

	return true;
}

bool Directoria::MoveFicheiro(const string& Fich, const string& DirNova)
{
	Ficheiro* file = nullptr;
	findFile(Fich, file);
	Directoria* dir = nullptr;
	findDir(DirNova, dir);

	if (file == nullptr || dir == nullptr) {
		return false;
	}

	Directoria* p = nullptr;
	p = file->getParent();
	p->Items.remove(file);

	dir->Items.push_back(file);
	file->setParent(dir);

	return true;
}

void Directoria::findFile(string fich, Ficheiro*& fileptr)
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if (fileptr == nullptr)
			(*it)->findFile(fich, fileptr);

	}
}

void Directoria::findDir(string dir, Directoria*& dirptr)
{
	if (getNome() == dir) {
		dirptr = this;
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if (dirptr == nullptr)
			(*it)->findDir(dir, dirptr);

	}
}

bool Directoria::MoverDirectoria(const string& DirOld, const string& DirNew)
{
	Directoria* dirO = nullptr;
	findDir(DirOld, dirO);
	Directoria* dirN = nullptr;
	findDir(DirNew, dirN);

	if (dirO->dirInsideDir(dirN))
		return false;

	if (dirO == nullptr || dirN == nullptr) {
		return false;
	}
	Directoria* p = nullptr;
	p = dirO->getParent();
	p->Items.remove(dirO);

	dirN->Items.push_back(dirO);
	dirO->setParent(dirN);

	return true;
}

bool Directoria::dirInsideDir(Directoria* dirB)
{
	bool check = false;
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if (*it == dirB)
		{
			return true;
		}
		check = (*it)->dirInsideDir(dirB);
	}
	return check;
}

string* Directoria::DataFicheiro(const string& ficheiro)
{
	Ficheiro* file = nullptr;
	findFile(ficheiro, file);
	if (file == nullptr) return new string("NULL");
	return new string(file->getData());
}

void Directoria::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->RenomearFicheiros(fich_old, fich_new);
	}
}

void Directoria::FicheiroDuplicados(list<string>& l, bool& _found)
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		if (!_found) (*it)->FicheiroDuplicados(l, _found);
	}
}

void Directoria::PesquisarAllFicheiros(list<string>& lres, const string& file)
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->PesquisarAllFicheiros(lres, file);
	}
}

void Directoria::PesquisarAllDirectorias(list<string>& lres, const string& dir)
{
	if (getNome() == dir) {
		lres.push_back(getPath());
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->PesquisarAllDirectorias(lres, dir);
	}
}

bool Directoria::processItems(const string& path)
{
	DIR* dir;
	struct dirent* entry;
	struct stat status;

	dir = opendir(path.c_str());

	if (!dir) {
		cout << "ERRO! Directoria não encontrada." << endl;
		return false;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
			string p = string(path).append("\\").append(string(entry->d_name));
			stat(p.c_str(), &status);

			if (S_ISDIR(status.st_mode)) // if dir
			{
				struct tm data;
				localtime_s(&data, &status.st_mtime);
				char buffer[100];
				strftime(buffer, 100, "%d/%m/%Y (%R)", &data);
				string dt = buffer;
				Directoria* atualDir = new Directoria(entry->d_name, dt, this);
				Items.push_back(atualDir);
				atualDir->processItems(p);
			}
			else if (S_ISREG(status.st_mode)) // if file
			{
				struct tm data;
				localtime_s(&data, &status.st_mtime);
				char buffer[100];
				strftime(buffer, 100, "%d/%m/%Y (%R)", &data);
				string dt = buffer;
				Ficheiro* fich = new Ficheiro(entry->d_name, this, status.st_size, dt);
				Items.push_back(fich);
			}
		}
	}
	closedir(dir);
	return true;
}

string DirSpaces(int n) {
	string spaces = "";
	for (int i = 0; i < n; i++)
	{
		spaces.append("\t");
	}
	return spaces;
}

void Directoria::Tree(int nivel)
{
	DirSpaces(nivel);
	string h = getData();
	cout << getNome() << " --- " << h << endl;
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->Tree(nivel + 1);
	}
}

void Directoria::TreeToFile(const string* file, ofstream& stream, int nivel)
{
	string h = DirSpaces(nivel) + getNome() + " --- " + getData() + "---" + getPath() + "\n";
	stream << h;
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->TreeToFile(file, stream, nivel + 1);
	}
}

string Directoria::getTipo()
{
	return typeid(this).name();
}

