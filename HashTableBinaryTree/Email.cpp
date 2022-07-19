#include "Email.h"

Email::Email(int e, int u, int n, string message)
{
	this->e = e;
	this->n = n;
	this->u = u;
	this->message = message;
}

Email::Email(int e)
{
	this->e = e;
}

Email::Email()
{
	this->e = -1;
	this->u = -1;
	this->n = -1;
	this->message = "";
}

Email::~Email()
{
}

void Email::SetE(int e)
{
	this->e = e;
}

void Email::SetN(int n)
{
	this->n = n;
}

void Email::SetU(int u)
{
	this->u = u;
}

void Email::SetMessage(string message)
{
	this->message = message;
}

int Email::GetE()
{
	return this->e;
}

int Email::GetN()
{
	return this->n;
}

int Email::GetU()
{
	return this->u;
}

string Email::GetMessage()
{
	return this->message;
}
