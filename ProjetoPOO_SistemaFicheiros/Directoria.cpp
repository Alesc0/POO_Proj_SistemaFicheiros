#include <dirent.h>
#include "Directoria.h"

Directoria::Directoria()
{
	//ctor
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
	int c = 0;
	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		c += (*it)->countDirs();
	}
	return c + 1;
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
		if ((Tipo == 0) && (getTipo() == typeid(Ficheiro*).name())) {
			getPath(path);
			_path = *path;
		}
		else if ((Tipo == 1) && (getTipo() == typeid(Directoria*).name()))
		{
			getPath(path);
			_path = *path;
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
				Directoria* atualDir = new Directoria();
				atualDir->setNome(entry->d_name);
				atualDir->setParent(this);
				Items.push_back(atualDir);
				atualDir->processItems(p);
			}
			else if (S_ISREG(status.st_mode)) // if file
			{
				Ficheiro* fich = new Ficheiro();
				fich->setNome(entry->d_name);
				fich->setTamanho(status.st_size);
				fich->setParent(this);
				Items.push_back(fich);
			}
		}
	}
	closedir(dir);
	return true;
}

void DirSpaces(int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
	}
}

void Directoria::treeView(int nivel)
{
	DirSpaces(nivel);
	string* str = new string();
	getPath(str);
	cout << getNome() << " --- " << *str << endl;
	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		(*it)->treeView(nivel + 1);
	}
}

string Directoria::getTipo()
{
	return typeid(this).name();
}

