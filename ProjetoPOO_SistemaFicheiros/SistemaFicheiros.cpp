#include "SistemaFicheiros.h"


bool SistemaFicheiros::Load(const string& path) {
	root = new Directoria();
	pathToRoot = path;
	auto pos = path.find_last_of('\\');
	if (pos != string::npos) {
		root->setNome(path.substr(pos + 1));
	}
	return root->processItems(path);
}

SistemaFicheiros::SistemaFicheiros()
{
}

SistemaFicheiros::~SistemaFicheiros()
{
}

Directoria* SistemaFicheiros::outRoot()
{
	return root;
}

int SistemaFicheiros::Memoria() {
	return 0;
}

string* SistemaFicheiros::DirectoriaMaisElementos()
{
	string* dir = NULL;
	root->dirMaisElementos(dir);
	return dir;
}
string* SistemaFicheiros::DirectoriaMenosElementos()
{
	string* dir = NULL;
	root->dirMenosElementos(dir);
	return dir;
}

int SistemaFicheiros::ContarFicheiros() {
	return root->countFiles();
}

int SistemaFicheiros::ContarDirectorias() {
	return root->countDirs();
}
