#include "HashTable.h"

HashTable::HashTable()
{
}

HashTable::HashTable(int tamanho)
{
	this->tamanho = tamanho;
}

HashTable::~HashTable()
{
}

void HashTable::InsereEmail(Email* email)
{
	arvore->Insere(*email);
}

void HashTable::RemoveEmail(Email* email)
{
}

Email HashTable::PesquisaEmail(Email* email)
{
	return *email;;
}

void HashTable::Limpa()
{
}
