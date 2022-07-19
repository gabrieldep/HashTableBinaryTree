#include "TipoNo.h"
#include <iostream>

TipoNo::TipoNo()
{
	this->message = "";
}

TipoNo::~TipoNo()
{
}

/// <summary>
/// Define o valor do nome
/// </summary>
/// <param name="nome">Valor a ser atribuido</param>
void TipoNo::SetMessage(std::string nome)
{
	this->message = nome;
}

void TipoNo::SetId(int valor)
{
	this->id = valor;
}

/// <summary>
/// Retorna o nome
/// </summary>
/// <returns></returns>
std::string TipoNo::GetMessage()
{
	return this->message;
}

int TipoNo::GetId()
{
	return this->id;
}
