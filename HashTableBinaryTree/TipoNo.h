#pragma once
#include "TipoItem.h"
#include <string>
class TipoNo
{
public:
	TipoNo();
	~TipoNo();
	void SetNome(std::string nome);
	std::string GetNome();
	void ImprimeNome();
	void ImprimeDados();
private:
	std::string nome;
	TipoNo* esq;
	TipoNo* dir;
	friend class ArvoreBinaria;
};

