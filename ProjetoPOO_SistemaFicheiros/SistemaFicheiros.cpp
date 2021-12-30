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

bool SistemaFicheiros::ReadXml(const string& path) {
	ifstream file;
	string txt;
	file.open(path);
	string idk = "C:\\Users\\Sheep\\Desktop\\Repositories\\POO_Proj_SistemaFicheiros\\POOPROJ";
	pathToRoot = "";

	getline(file, txt);
	txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
	if (!(txt[0] == '<' && (txt.find("directoria") != string::npos))) {
		return false;
	}

	getline(file, txt);
	txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
	if (txt[0] == '<' && (txt.find("nome") != string::npos)) {
		string nome = txt.substr(6, txt.length() - 13);
		getline(file, txt);
		txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
		if (txt[0] == '<' && (txt.find("data") != string::npos)) {
			string data = txt.substr(6, txt.length() - 13);

			root = new Directoria(nome, data);

			while (getline(file, txt)) {
				txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
				if (txt[0] == '<' && (txt.find("directoria") != string::npos) && !(txt.find("/directoria") != string::npos)) {
					//cout << "dir";
					root->getItems().push_back(root->processXML(root, file));
				}
				else if (txt[0] == '<' && (txt.find("ficheiro") != string::npos) && !(txt.find("/ficheiro") != string::npos)) {
					//cout << "fic" << endl;
					getline(file, txt);
					txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
					string nome = txt.substr(6, txt.length() - 13);
					getline(file, txt);
					txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
					string data = txt.substr(6, txt.length() - 13);
					getline(file, txt);
					txt.erase(remove(txt.begin(), txt.end(), '\t'), txt.end());
					int tamanho = stoi(txt.substr(9, txt.length() - 19));
					Ficheiro* f = new Ficheiro(nome, root, 10, data);
					root->getItems().push_back(f);
					
				}

			}

		}
	}



	return true;
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

