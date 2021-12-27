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
private:

};

#endif
