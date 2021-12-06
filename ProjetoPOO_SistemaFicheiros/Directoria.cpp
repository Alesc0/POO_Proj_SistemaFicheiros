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
	list<Directoria*>::iterator it = Dirs.begin();
	list<Ficheiro*>::iterator it2 = Ficheiros.begin();
	for (it2; it2 != Ficheiros.end(); it2++)
	{
		c++;
	}
	for (it; it != Dirs.end(); it++)
	{
		c += (*it)->countFiles();
	}
	return c;
}


int Directoria::countDirs()
{
	int c = 0;
	list<Directoria*>::iterator it = Dirs.begin();
	for (it; it != Dirs.end(); it++)
	{
		c += 1 + (*it)->countDirs();
	}
	return c;
}

void Directoria::setNome(string _nome)
{
	nome = _nome;
}

bool Directoria::processDir(const string& path, Directoria* nowDir)
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
				if (nowDir != NULL)
					nowDir->Dirs.push_back(atualDir);
				else
					Dirs.push_back(atualDir);
				processDir(p, atualDir);
			}
			else if (S_ISREG(status.st_mode)) // if file
			{
				Ficheiro* fich = new Ficheiro();
				fich->setNome(entry->d_name);
				if (nowDir != NULL)
					nowDir->Ficheiros.push_back(fich);
				else
					Ficheiros.push_back(fich);
			}
		}
	}
	closedir(dir);
	return true;
}

void spaces(int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
	}
}

void Directoria::treeView(int nivel = 0)
{
	spaces(nivel);
	cout << nome << endl;

	list<Directoria*>::iterator it = Dirs.begin();
	for (it; it != Dirs.end(); it++)
	{
		(*it)->treeView(nivel + 1);
	}

	list<Ficheiro*>::iterator it2 = Ficheiros.begin();
	for (it2; it2 != Ficheiros.end(); it2++)
	{
		spaces(nivel + 1);
		cout << (*it2)->returnNome() << endl;
	}
}

