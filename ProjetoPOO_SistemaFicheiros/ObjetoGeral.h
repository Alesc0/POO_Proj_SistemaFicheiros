#ifndef OBJETOGERAL_H
#define OBJETOGERAL_H

#include <iostream>

using namespace std;

class ObjetoGeral
{
	string nome;
public:
	ObjetoGeral();
	~ObjetoGeral();
	void setNome(string nome);
	string returnNome();
private:

};

#endif