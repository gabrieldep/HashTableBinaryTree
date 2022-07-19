#pragma once
#include <string>
#include "Email.h"
class TipoNo
{
public:
	TipoNo(int e, int n, int u, string message);
	TipoNo(int e);
	~TipoNo();
private:
	Email* email;
	TipoNo* esq;
	TipoNo* dir;
	friend class BinaryTree;
};

