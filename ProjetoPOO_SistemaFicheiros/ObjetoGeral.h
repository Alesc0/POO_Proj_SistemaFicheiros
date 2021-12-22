#ifndef OBJETOGERAL_H
#define OBJETOGERAL_H

#include <iostream>

using namespace std;

class Directoria;

class ObjetoGeral
{
	string nome;
	Directoria* parent = NULL;
public:
	ObjetoGeral();
	~ObjetoGeral();
	void setNome(string nome);
	void setParent(Directoria* _dir);
	Directoria* getParent();
	string getNome();
	virtual void treeView(int nivel = 0);
	virtual int countFiles();
	virtual int countDirs();
	virtual int dirMaisElementos(string*& dir, int c = 0) = 0;
	virtual int dirMenosElementos(string*& dir, int c = 0) = 0;
	virtual int fichMaior(string*& fich, int c = 0) = 0;
	virtual int getSize() = 0;
	void getPath(string* fullpath);
	virtual int DirectoriaMaisEspaco(int c, string*& dir) = 0;
private:

};

#endif