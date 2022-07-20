#include "Email.h"

Email::Email(int e, int u, int n, string message)
{
	this->e = e;
	this->b = n;
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
	this->b = -1;
	this->message = "";
}

Email::~Email()
{
}

void Email::SetE(int e)
{
	this->e = e;
}

void Email::SetB(int n)
{
	this->b = n;
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

int Email::GetB()
{
	return this->b;
}

int Email::GetU()
{
	return this->u;
}

string Email::GetMessage()
{
	return this->message;
}
