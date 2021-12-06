#include "SistemaFicheiros.h"


bool SistemaFicheiros::Load(const string& path) {
	root = new Directoria();
	pathToRoot = path; 
	auto pos = path.find_last_of('/');
	if (pos != string::npos) {
		root->setNome(path.substr(pos+1));
	}
	return root->processDir(path,NULL);
}

SistemaFicheiros::SistemaFicheiros()
{
}

SistemaFicheiros::~SistemaFicheiros()
{
}

Directoria* SistemaFicheiros::outRoot()
{
	return root;
}

int SistemaFicheiros::Memoria() {
	return 0;
}

int SistemaFicheiros::ContarFicheiros() {
	return root->countFiles();
}