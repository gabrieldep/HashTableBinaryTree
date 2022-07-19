#include "HashTable.h"

HashTable::HashTable(int tamanho)
{
	this->tamanho = tamanho;
	this->arvore = (BinaryTree**)malloc(tamanho * sizeof(BinaryTree*));
	for (size_t i = 0; i < tamanho; i++)
		this->arvore[i] = new BinaryTree();
}

HashTable::~HashTable()
{
}

void HashTable::Insere(BinaryTree* tree)
{

}

void HashTable::Remove(BinaryTree* email)
{
}

BinaryTree* HashTable::Pesquisa(int id)
{
	return arvore[id];
}

void HashTable::Limpa()
{
}
