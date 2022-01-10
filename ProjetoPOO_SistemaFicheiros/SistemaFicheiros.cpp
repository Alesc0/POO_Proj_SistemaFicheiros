#include "SistemaFicheiros.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool SistemaFicheiros::Load(const string& path) {
	pathToRoot = path;
	auto pos = path.find_last_of('\\');
	if (pos != string::npos) {
		root = new Directoria(path.substr(pos + 1), "");
	}
	return root->processItems(path);
}

void SistemaFicheiros::Escrever_XML(const string& s) {
	ofstream f;
	f.open(s + ".xml");
	root->Writing(root, f);
	f.close();
}

bool SistemaFicheiros::Ler_XML(const string& path) {
	ifstream file;
	string txt;
	file.open(path);
	pathToRoot = "";

	getline(file, txt);
	txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
	if (!(txt.find("<directoria>") != string::npos)) {
		return false;
	}

	getline(file, txt);
	txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
	if (txt.find("<nome>") != string::npos) {
		string nome = txt.substr(6, txt.length() - 13);
		getline(file, txt);
		txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
		if (txt.find("<data>") != string::npos) {
			string data = txt.substr(6, txt.length() - 13);
			root = new Directoria(nome, data);

			getline(file, txt);
			txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
			if (txt.find("<Items>") != string::npos) {
				root->processXML(file);
			}
		}
	}
	if (!root)
		return false;
	return true;
}

SistemaFicheiros::SistemaFicheiros()
{
}

SistemaFicheiros::~SistemaFicheiros()
{
	delete root;
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
	return root->getSize();
}

string* SistemaFicheiros::DirectoriaMaisElementos()
{
	Directoria* dir = nullptr;
	root->dirMaisElementos(dir);
	return new string(dir->getNome());
}
string* SistemaFicheiros::DirectoriaMenosElementos()
{
	Directoria* dir = nullptr;
	root->dirMenosElementos(dir);
	return new string(dir->getNome());
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
string* SistemaFicheiros::FicheiroMaior()
{
	Ficheiro* fich = nullptr;
	root->fichMaior(fich);
	return new string(fich->getPath());
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
