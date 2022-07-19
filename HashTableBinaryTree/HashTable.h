#pragma once
#include "BinaryTree.h"
#include "Email.h"
class HashTable
{
private:
	BinaryTree** arvore;
	int tamanho;
public:
	HashTable(int tamanho);
	~HashTable();
	void Insere(BinaryTree* tree);
	void Remove(BinaryTree* tree);
	BinaryTree* Pesquisa(int id);
	void Limpa();
};