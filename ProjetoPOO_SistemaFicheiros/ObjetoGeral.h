#ifndef OBJETOGERAL_H
#define OBJETOGERAL_H

#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Directoria;
class Ficheiro;

class ObjetoGeral
{
	string nome;
	Directoria* parent = nullptr;
	string data;
public:
	ObjetoGeral();
	virtual ~ObjetoGeral();
	void setNome(string _nome);
	string getNome();
	virtual string getTipo() = 0;
	void setParent(Directoria* _dir);
	Directoria* getParent();
	string getPath();
	void setData(string _data);
	string getData();
	string Spaces(int n);
	virtual int getSize() = 0;
	virtual void Tree(int nivel = 0) = 0;
	virtual void TreeToFile(const string* file, ofstream& stream, int nivel = 0) = 0;
	virtual int countFiles() = 0;
	virtual int countDirs() = 0;
	virtual void dirMaisElementos(Directoria*& dir) = 0;
	virtual void dirMenosElementos(Directoria*& dir) = 0;
	virtual void fichMaior(Ficheiro* &fich) = 0;
	virtual int DirectoriaMaisEspaco(string& dir, int c = 0) = 0;
	virtual void removerRecursive(string tipo) = 0;
	virtual void findFile(string fich, Ficheiro*& fileptr) = 0;
	virtual void findAllFiles(string str, list<Ficheiro*>& lst) = 0;
	virtual void findDir(string dir, Directoria*& dirptr) = 0;
	virtual bool MoverDirectoria(const string& DirOld, const string& DirNew) = 0;
	virtual bool dirInsideDir(Directoria* dirB) = 0;
	virtual void RenomearFicheiros(const string& fich_old, const string& fich_new) = 0;
	virtual void FicheiroDuplicados(list<string>& l, bool& _found) = 0;
	virtual void PesquisarAllFicheiros(list<string>& lres, const string& file) = 0;
	virtual void PesquisarAllDirectorias(list<string>& lres, const string& dir) = 0;
	virtual bool Writing(Directoria* dir, ostream& f,int nmrTabs=0) = 0;
private:

};

#endif