#ifndef FICHEIRO_H
#define FICHEIRO_H
#include <iostream>
#include <algorithm>

using namespace std;

class Ficheiro
{
	string nome;
public:

	void setNome(string nome);
	string returnNome();
	Ficheiro();
	~Ficheiro();

private:

};

#endif 