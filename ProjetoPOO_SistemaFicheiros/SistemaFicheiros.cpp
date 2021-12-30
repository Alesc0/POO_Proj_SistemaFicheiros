#include "SistemaFicheiros.h"
#include <iostream>
#include <fstream>


bool SistemaFicheiros::Load(const string& path) {
	pathToRoot = path;
	auto pos = path.find_last_of('\\');
	if (pos != string::npos) {
		root = new Directoria(path.substr(pos + 1), "");
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
		path = "Caminho n�o encontrado";
	}
	else
	{
		path.insert(0, "\\");
		path.insert(0, pathToRoot);
	}
	ptr = new string(path);
	return ptr;

}
bool SistemaFicheiros::RemoverAll(const string& s, const string& tipo) {
	return root->RemoverAll(s, tipo);
}

bool SistemaFicheiros::MoveFicheiro(const string& Fich, const string& DirNova) {
	return root->MoveFicheiro(Fich, DirNova);
}

bool SistemaFicheiros::MoverDirectoria(const string& DirOld, const string& DirNew)
{
	return root->MoverDirectoria(DirOld, DirNew);
}

string* SistemaFicheiros::DataFicheiro(const string& ficheiro)
{
	return root->DataFicheiro(ficheiro);;
}

void SistemaFicheiros::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
	root->RenomearFicheiros(fich_old, fich_new);
}
bool SistemaFicheiros::FicheiroDuplicados() {
	list<string> l;
	bool found = false;
	root->FicheiroDuplicados(l, found);
	return found;
}

void SistemaFicheiros::PesquisarAllFicheiros(list<string>& lres, const string& file)
{
	root->PesquisarAllFicheiros(lres, file);
}

void SistemaFicheiros::PesquisarAllDirectorias(list<string>& lres, const string& dir)
{
	root->PesquisarAllDirectorias(lres, dir);
}

void SistemaFicheiros::Tree(const string* fich) {
	if (fich == nullptr)
		root->Tree();
	else
	{
		ofstream stream;
		stream.open(*fich);
		root->TreeToFile(fich,stream);
		stream.close();
	}
}