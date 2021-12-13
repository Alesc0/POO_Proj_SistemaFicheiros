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

string* Directoria::dirMaisElementos(Directoria* dir, int c) {
	int atualc = 0;

	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		if (typeid(*it).name() == typeid(Directoria*).name()) {
			atualc++;
			(*it)->dirmaiselementos(dir, c);
		}
	}

	if (atualc > c) {
		c = atualc;
		dir = this;
	}
	return new string(dir->returnNome());
}

bool Directoria::processItems(const string& path, Directoria* nowDir)
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
				atualDir->parent = this;
				if (nowDir != NULL)
					nowDir->Items.push_back(atualDir);
				else
					Items.push_back(atualDir);
				processItems(p, atualDir);
			}
			else if (S_ISREG(status.st_mode)) // if file
			{
				Ficheiro* fich = new Ficheiro();
				fich->setNome(entry->d_name);
				if (nowDir != NULL)
					nowDir->Items.push_back(fich);
				else
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

void Directoria::treeView(int nivel = 0)
{
	DirSpaces(nivel);
	cout << returnNome() << endl;
	list<ObjetoGeral*>::iterator it = Items.begin();
	for (it; it != Items.end(); it++)
	{
		(*it)->treeView(nivel + 1);
	}
}