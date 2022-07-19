#pragma once
#include <string>
#include "Email.h"
class TipoNo
{
public:
	TipoNo(int e, int n, int u, string message);
	TipoNo(int e);
	TipoNo(Email e);
	~TipoNo();
	void SetEmail(Email email);
	Email* GetEmail();
private:
	Email* email;
	TipoNo* esq;
	TipoNo* dir;
	friend class BinaryTree;
};

