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

Directoria* SistemaFicheiros::getRoot()
{
	return root;
}

string SistemaFicheiros::getRootPath()
{
	return pathToRoot;
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


string* SistemaFicheiros::DirectoriaMaisEspaco() {
	string dir;
	root->DirectoriaMaisEspaco(dir);
	string* ptr = new string(dir);
	return ptr;
}

int SistemaFicheiros::ContarFicheiros() {
	return root->countFiles();
}

int SistemaFicheiros::ContarDirectorias() {
	return root->countDirs();
}

string* SistemaFicheiros::Search(const string& s, int Tipo) {
	//tipo 0 -> ficheiro
	//tipo 1 -> directoria

	string path = "";
	string* ptr = NULL;
	root->Search(s, Tipo, path);
	if (path == "") {
		path = "Caminho não encontrado";
	}
	ptr = new string(path);
	return ptr;

}
bool SistemaFicheiros::RemoverAll(const string& s, const string& tipo) {
	return root->RemoverAll(s, tipo);
}