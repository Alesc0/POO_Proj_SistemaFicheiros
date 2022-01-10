#ifndef DIRECTORIA_H
#define DIRECTORIA_H

#include <iostream>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include "Ficheiro.h"
#include <iostream>
#include "ObjetoGeral.h"

using namespace std;

class Directoria : public ObjetoGeral
{
	list<ObjetoGeral*> Items;
public:
	Directoria(string _nome, string data, Directoria* _parent = nullptr);
	~Directoria();
	void setItems(list<ObjetoGeral*> Items);
	list<ObjetoGeral*> getItems();
	string getTipo();
	int countFiles();
	int countDirs();
	bool processItems(const string& path);
	void Tree(int nivel = 0);
	void TreeToFile(const string* file, ofstream& stream, int nivel = 0);
	void dirMaisElementos(Directoria* &dir);
	void dirMenosElementos(Directoria*& dir);
	void fichMaior(Ficheiro* &fich);
	int getSize();
	int DirectoriaMaisEspaco(string& dir, int c = 0);
	string Search(const string& s, int Tipo);
	bool RemoverAll(const string& s, const string& tipo);
	void removerRecursive(string tipo);
	bool MoveFicheiro(const string& Fich, const string& DirNova);
	void findFile(string fich, Ficheiro*& fileptr);
	void findAllFiles(string str, list<Ficheiro*>& lst);
	void findDir(string dir, Directoria*& dirptr);
	bool MoverDirectoria(const string& DirOld, const string& DirNew);
	bool dirInsideDir(Directoria* dirB);
	string* DataFicheiro(const string& ficheiro);
	void RenomearFicheiros(const string& fich_old, const string& fich_new);
	void FicheiroDuplicados(list<string>& l, bool& _found);
	void PesquisarAllFicheiros(list<string>& lres, const string& file);
	void PesquisarAllDirectorias(list<string>& lres, const string& dir);
	bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);
	void FixNames();
	bool Writing(Directoria* dir, ostream& f, int nmrTabs=0);
	Directoria* processXML(ifstream& file); 
private:

};

#endif