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
	string dir = "";
	root->dirMaisElementos(dir);
	return new string(dir);
}
string* SistemaFicheiros::DirectoriaMenosElementos()
{
	string dir;
	root->dirMenosElementos(dir);
	return new string(dir);
}


string* SistemaFicheiros::DirectoriaMaisEspaco() {
	string dir;
	root->DirectoriaMaisEspaco(dir);
	return new string(dir);
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

	string path = root->Search(s, Tipo);
	if (path == "") {
		path = "Caminho nao encontrado ou tipo invalido";
	}
	return new string(path);

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
		root->TreeToFile(fich, stream);
		stream.close();
	}
}

bool SistemaFicheiros::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	return root->CopyBatch(padrao, DirOrigem, DirDestino);
}
