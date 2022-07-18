#include "TipoNo.h"
#include <iostream>

TipoNo::TipoNo()
{
	this->nome = "";
}

TipoNo::~TipoNo()
{
	//delete this->dadosBinarios;
}

/// <summary>
/// Define o valor do nome
/// </summary>
/// <param name="nome">Valor a ser atribuido</param>
void TipoNo::SetNome(std::string nome)
{
	this->nome = nome;
}

/// <summary>
/// Retorna o nome
/// </summary>
/// <returns></returns>
std::string TipoNo::GetNome()
{
	return this->nome;
}

/// <summary>
/// Imprime o nome na saida padr�o
/// </summary>
void TipoNo::ImprimeNome()
{
	std::cout << this->nome << " ";
}

/// <summary>
/// Imprime os dados na saida padr�o
/// </summary>
void TipoNo::ImprimeDados()
{
	//dadosBinarios->Imprime();
}
