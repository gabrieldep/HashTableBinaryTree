#pragma once
#include <string>
#include "Email.h"
class TipoNo
{
public:
	TipoNo();
	~TipoNo();
	void SetMessage(std::string nome);
	void SetId(int valor);
private:
	Email email;
	TipoNo* esq;
	TipoNo* dir;
	friend class BinaryTree;
};

