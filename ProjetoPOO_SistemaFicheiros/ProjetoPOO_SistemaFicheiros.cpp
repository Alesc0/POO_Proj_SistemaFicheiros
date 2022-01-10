#include <iostream>
#include <string>
#include <dirent.h>

#include <list>
#include "ObjetoGeral.h"
#include "Directoria.h"
#include "SistemaFicheiros.h"
#include "Ficheiro.h"


using namespace std;
void press() {
	cin.ignore();
	cout << "\n\nPressione qualquer tecla para continuar!" << endl;
	getc(stdin);
}

void menu() {
	cout << "1) Carregar diretoria" << endl;
	cout << "2) Contar número de ficheiros em memória" << endl;
	cout << "3) Contar número de diretorias em memória" << endl;
	cout << "4) Determinar memória ocupada" << endl;
	cout << "5) Diretoria com mais informação" << endl;
	cout << "6) Diretoria com menos informação" << endl;
	cout << "7) Ficheiro que ocupa mais espaço" << endl;
	cout << "8) Diretoria que ocupa mais espaço" << endl;
	cout << "9) Ficheiro/Diretoria existe?" << endl;
	cout << "10) Remover todas Ficheiros ou Diretorias" << endl;
	cout << "11) Gravar Sistema Ficheiros em XML" << endl;
	cout << "12) Ler XML" << endl;
	cout << "13) Mover ficheiro" << endl;
	cout << "14) Mover Diretoria" << endl;
	cout << "15) Devolver data ficheiro" << endl;
	cout << "16) Tree" << endl;
	cout << "17) Pesquisar Diretorias com nome x e colocar em y" << endl;
	cout << "18) Pesquisar Ficheiros com nome x e colocar em y" << endl;
	cout << "19) Renomear Ficheiros" << endl;
	cout << "20) Verificar se existem Ficheiros com mesmo nome" << endl;
	cout << "21) Copiar ficheiros de directoria para outra" << endl;
}

int main()
{
	SistemaFicheiros SF;
	int op = 99;
	string aux;
	string aux2;
	string aux3;
	int auxInt=0;
	list<string> auxLista;

	while (op != 0) {
		system("cls");
		menu();
		cin >> op;
		switch (op) {

		case 0:
			break;
		case 1:
			system("cls");
			cout << "Path->";
			cin >> aux;
			if (SF.Load(aux))
				cout << "Sucesso!" << endl;

			press();
			break;
		case 2:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existem ficheiros em memória";
				press();
				break;
			}
			cout << "Número de ficheiros em memória: " << SF.ContarFicheiros() << endl;
			press();
			break;
		case 3:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existem diretorias em memória!";
				press();
				break;
			}
			cout << "Número de diretorias em memória: " << SF.ContarDirectorias() << endl;
			press();
			break;
		case 4:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existem dados em memória!";
				press();
				break;
			}
			cout << SF.Memoria() << " bytes" << endl;
			press();
			break;
		case 5:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "A diretoria com mais informação é: " << *SF.DirectoriaMaisElementos() << endl;

			press();
			break;
		case 6:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "A diretoria com menos informação é: " << *SF.DirectoriaMenosElementos() << endl;

			press();
			break;
		case 7:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Ficheiro que ocupa mais espaço(path): " << *SF.FicheiroMaior() << endl;
			press();
			break;
		case 8:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}	
			cout << "Diretoria que ocupa mais espaço: " << SF.DirectoriaMaisEspaco() << endl;
			press();
			break;
		case 9:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome: ";
			cin >> aux;
			cout << "\nTipo: ";
			cin >> auxInt;
			cout << *SF.Search(aux, auxInt) << endl;
			press();
			break;
		case 10:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome:";
			cin >> aux2;
			cout << "Tipo:";
			cin >> aux;
			if (SF.RemoverAll(aux2, aux)) {
				cout << "Sucesso!";
			}
			else {
				cout << "Erro!";
			}
			press();
			break;
		case 11:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome do xml: ";
			cin >> aux;
			SF.Escrever_XML(aux);
			cout << "Ficheiro criado!";
			press();
			break;
		case 12:
			if (SF.getRoot() != nullptr) {
				delete SF.getRoot();
			}
			cout << "Path: ";
			cin >> aux;
			if (SF.Ler_XML(aux))
				cout << "Sucesso";
			else
				cout << "Eroo!";
			press();
			break;
		case 13:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome do ficheiro: ";
			cin >> aux;
			cout << "\nNome da diretoria: ";
			cin >> aux2;
			if (SF.MoveFicheiro(aux, aux2))
				cout << "Sucesso!";
			else
				cout << "Erro!";
			press();
			break;
		case 14:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome da diretoria a mover: ";
			cin >> aux;
			cout << "\nNome da diretoria final: ";
			cin >> aux2;
			if (SF.MoverDirectoria(aux, aux2))
				cout << "Sucesso!";
			else
				cout << "Erro!";
			press();
			break;
		case 15:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome do ficheiro: ";
			cin >> aux;
			cout << "Data: " << SF.DataFicheiro(aux);
			press();
			break;
		case 16:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "1)Consola" << endl;
			cout << "Ou nome do ficheiro:" << endl;
			cin >> aux;
			if (aux == "1")
				SF.Tree();
			else
				SF.Tree(new string(aux));
			press();
			break;
		case 17:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome da dir:";
			cin >> aux;
			SF.PesquisarAllDirectorias(auxLista, aux);
			press();
			break;
		case 18:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome do ficheiro:";
			cin >> aux;
			SF.PesquisarAllFicheiros(auxLista, aux);
			press();
			break;
		case 19:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Nome do ficheiro: ";
			cin >> aux;
			cout << "\nNome novo: ";
			cin >> aux2;
			SF.RenomearFicheiros(aux, aux2);
			cout << "Sucesso";
			press();
			break;
		case 20:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			if (SF.FicheiroDuplicados())
				cout << "Existem ficheiros duplicados!";
			else
				cout << "Não existem ficheiros duplicados";
			break;
		case 21:
			system("cls");
			if (SF.getRoot() == nullptr)
			{
				cout << "Não existe nada em memória!";
				press();
				break;
			}
			cout << "Padrao: ";
			cin >> aux;
			cout << "Origem: ";
			cin >> aux2;
			cout << "Destino: ";
			cin >> aux3;
			
			if (SF.CopyBatch(aux, aux2, aux3))
				cout << "Sucesso";
			else
				cout << "Erro";
			press();
			break;
		default:
			cout << "Opção Inválida!" << endl;
			break;
		}
	}

	return 0;
}