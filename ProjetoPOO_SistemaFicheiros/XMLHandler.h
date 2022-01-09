#ifndef XMLHANDLER
#define XMLHANDLER

#include <iostream>
#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"


class XMLHandler
{
public:
	XMLHandler();
	~XMLHandler();
	bool WriteAll(Directoria* dir);
	bool ReadXml(const string& path);
private:

};

#endif
