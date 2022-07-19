#include "TipoItemArvore.h"

TipoItemArvore::TipoItemArvore(Email* email)
{
	this->email = email;
}

TipoItemArvore::TipoItemArvore()
{
	delete this->email;
}

TipoItemArvore::~TipoItemArvore()
{
	delete email;
}

void TipoItemArvore::SetEmail(Email* email)
{
	this->email = email;
}

Email* TipoItemArvore::GetEmail()
{
	return this->email;
}
