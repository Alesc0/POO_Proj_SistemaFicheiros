#ifndef OBJETOGERAL_H
#define OBJETOGERAL_H

#include <iostream>

using namespace std;

class Directoria;
class Ficheiro;

class ObjetoGeral
{
	string nome;
	Directoria* parent = NULL;
	string data;
public:
	ObjetoGeral();
	~ObjetoGeral();
	void setNome(string _nome);
	string getNome();
	virtual string getTipo() = 0;
	void setParent(Directoria* _dir);
	Directoria* getParent();
	void getPath(string* fullpath);
	void setData(string _data);
	string getData();
	virtual int getSize() = 0;
	virtual void Tree(int nivel = 0);
	virtual int countFiles();
	virtual int countDirs();
	virtual int dirMaisElementos(string*& dir, int c = 0) = 0;
	virtual int dirMenosElementos(string*& dir, int c = 0) = 0;
	virtual int fichMaior(string*& fich, int c = 0) = 0;
	virtual int DirectoriaMaisEspaco(string& dir, int c = 0) = 0;
	virtual void Search(const string& s, int Tipo, string& path) = 0;
	virtual bool RemoverAll(const string& s, const string& tipo, int del = 0) = 0;
	virtual bool MoveFicheiro(const string& Fich, const string& DirNova) = 0;
	virtual void findFile(string fich, Ficheiro*& fileptr) = 0;
	virtual void findDir(string dir, Directoria*& dirptr) = 0;
	virtual bool MoverDirectoria(const string& DirOld, const string& DirNew) = 0;
	virtual void RenomearFicheiros(const string& fich_old, const string& fich_new) = 0;
private:

};

#endif