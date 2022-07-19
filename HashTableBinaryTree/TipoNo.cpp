#include "TipoNo.h"
#include <iostream>

TipoNo::TipoNo(int e, int n, int u, string message)
{
	email = new Email(e, u, n, message);
}

TipoNo::TipoNo(int e)
{
	this->email = new Email(e);
}

TipoNo::TipoNo(Email e)
{
	this->email = new Email(e);
}

TipoNo::~TipoNo()
{
	delete email;
}

void TipoNo::SetEmail(Email email)
{
	this->email = &email;
}
