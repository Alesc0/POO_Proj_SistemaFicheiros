#include <dirent.h>
#include "Directoria.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Directoria::Directoria(string _nome, string _data, Directoria* _parent)
{
	setNome(_nome);
	setParent(_parent);
	setData(_data);
}

Directoria::~Directoria()
{
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		delete* it;
	}
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

int Directoria::dirMaisElementos(string& dir, int c) {
	int atualc = (int)Items.size();

	if (atualc > c) {
		c = atualc;
		dir = this->getNome();
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		c = (*it)->dirMaisElementos(dir, c);
	}
	return c;
}

int Directoria::dirMenosElementos(string& dir, int c) {
	if (c == -1) c = (int)Items.size();
	int atualc = (int)Items.size();

	if (atualc < c) {
		c = atualc;
		dir = this->getNome();
	}
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		c = (*it)->dirMenosElementos(dir, c);
	}
	return c;
}

int Directoria::fichMaior(string& fich, int c)
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

string Directoria::Search(const string& s, int Tipo)
{
	//tipo 0 -> ficheiro
	//tipo 1 -> directoria

	if (Tipo == 0)
	{
		Ficheiro* fich = nullptr;
		findFile(s, fich);
		if (!fich) return "";
		return fich->getPath();
	}
	else if (Tipo == 1)
	{
		Directoria* dir = nullptr;
		findDir(s, dir);
		if (!dir) return "";
		return dir->getPath();
	}
	return "";
}

bool Directoria::RemoverAll(const string& s, const string& tipo, int del)
{
	Directoria* dir = nullptr;
	findDir(s, dir);
	if (!dir) return false;

	dir->removerRecursive(tipo);

	return true;
}

void Directoria::removerRecursive(string tipo)
{
	if (tipo == "DIR")
	{
		for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it)
		{
			if ((*it)->getTipo() == typeid(Directoria*).name())
			{
				delete* it;
				it = Items.erase(it);
				continue;
			}
			it++;
		}
	}
	else
	{
		string tipo;
		for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it)
		{
			tipo = (*it)->getTipo();
			(*it)->removerRecursive(tipo);
			if (tipo == typeid(Ficheiro*).name())
			{
				it = Items.erase(it);
				continue;
			}
			it++;
		}
	}
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

bool Directoria::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	list<Ficheiro*> files;
	Directoria* dirO = nullptr;
	Directoria* dirN = nullptr;

	findDir(DirOrigem, dirO);
	findDir(DirDestino, dirN);

	dirO->findAllFiles(padrao, files);

	for (list<Ficheiro*>::iterator i = files.begin(); i != files.end(); i++)
	{
		dirN->Items.push_back(*i);
	}

	dirN->FixNames();

	return false;
}

void Directoria::FixNames() {

	int occ = 0;
	string nome;
	ostringstream st;
	list<ObjetoGeral*>::iterator it1;
	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		occ = 0;
		nome = (*it)->getNome();
		it1 = it;
		it1++;

		for (; it1 != Items.end(); it1++)
		{
			if ((*it1)->getNome() == nome)
			{
				occ++;
				st << setfill('0') << setw(3) << occ;
				string n = nome;
				n.insert(n.find_last_of("."), "(" + st.str() + ")");
				(*it)->setNome(n);
				st.str("");
				st.clear();
			}
		}
	}
}

void Directoria::findAllFiles(string str, list<Ficheiro*>& lst) {

	for (list<ObjetoGeral*>::iterator it = Items.begin(); it != Items.end(); it++)
	{
		(*it)->findAllFiles(str, lst);
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
	string h = getData();
	cout << DirSpaces(nivel) << getNome() << " --- " << h << endl;
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

