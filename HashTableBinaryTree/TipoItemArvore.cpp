#include "TipoItemArvore.h"

TipoItemArvore::TipoItemArvore()
{
	this->id = -1;
	this->message = "";
}

TipoItemArvore::TipoItemArvore(std::string nome, int id)
{
	this->message = nome;
	this->id = id;
}

void TipoItemArvore::SetMessage(std::string valor)
{
	this->message = valor;
}

void TipoItemArvore::SetId(int valor)
{
	this->id = valor;
}

std::string TipoItemArvore::GetMessage()
{
	return this->message;
}

int TipoItemArvore::GetId()
{
	return this->id;
}
