#include "XMLHandler.h"
#include <iostream>
#include <fstream>

XMLHandler::XMLHandler() {

}

XMLHandler::~XMLHandler() {

}

bool XMLHandler::WriteAll(Directoria* dir) {
	ofstream f;
	f.open("XML.xml");
	dir->Writing(dir, f);
	f.close();
	return true;
}