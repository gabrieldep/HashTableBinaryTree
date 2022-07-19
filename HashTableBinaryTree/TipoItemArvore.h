#pragma once
#include <string>
#include "Email.h"
class TipoItemArvore
{
public:
	TipoItemArvore(Email* email);
	TipoItemArvore();
	~TipoItemArvore();
	void SetEmail(Email* email);
	Email* GetEmail();
private:
	Email* email;
};