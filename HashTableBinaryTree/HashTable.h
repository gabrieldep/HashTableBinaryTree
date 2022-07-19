#pragma once
#include "BinaryTree.h"
#include "Email.h"
class HashTable
{
private:
	BinaryTree* arvore;
	int tamanho;
public:
	HashTable();
	HashTable(int tamanho);
	~HashTable();
	void InsereEmail(Email* email);
	void RemoveEmail(Email* email);
	Email PesquisaEmail(Email* email);
	void Limpa();
};