#include "ObjetoGeral.h"
#include "Directoria.h"

ObjetoGeral::ObjetoGeral()
{
}

ObjetoGeral::~ObjetoGeral()
{
}
void ObjetoGeral::setNome(string _nome)
{
	nome = _nome;
}

void ObjetoGeral::setParent(Directoria* _dir)
{
	parent = _dir;
}

Directoria* ObjetoGeral::getParent()
{
	return parent;
}

string ObjetoGeral::getNome()
{
	return nome;
}

string ObjetoGeral::getPath()
{
	Directoria* parent = getParent();
	if (parent != nullptr) {
		return parent->getPath() + "\\" + getNome();
	}
	return getNome();
}

void ObjetoGeral::setData(string _data)
{
	data = _data;
}

string ObjetoGeral::getData()
{
	return data;
}

string ObjetoGeral::Spaces(int n)
{
	{
		string spaces = "";
		if (n == 1)
		{
			spaces.append("|_____");
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (i != n)
				{
					spaces.append("|     ");
				}
				else
				{
					spaces.append("|_____");
				}
			}
		}
		return spaces;
	}
}

