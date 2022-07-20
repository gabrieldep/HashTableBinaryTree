#pragma once
#include "TipoNo.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void Insere(Email tipoItem);
	TipoNo* Pesquisa(int chave);
	bool Remove(int chave);
	void Limpa();

private:
	void InsereRecursivo(TipoNo*& p, Email item);
	TipoNo* PesquisaRecursiva(TipoNo*& p, int chave);
	bool RemoveRecursiva(TipoNo*& p, int chave);
	void ApagaRecursivo(TipoNo* p);
	void Antecessor(TipoNo* q, TipoNo*& r);

	TipoNo* raiz;
};

