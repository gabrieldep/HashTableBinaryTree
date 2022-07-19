#pragma once
#include "TipoNo.h"
#include "TipoItemArvore.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void Insere(TipoItemArvore tipoItem);
	TipoNo* Pesquisa(int chave);
	void Remove(int chave);
	void Limpa();

private:
	void InsereRecursivo(TipoNo*& p, TipoItemArvore item);
	TipoNo* PesquisaRecursiva(TipoNo*& p, int chave);
	void RemoveRecursiva(TipoNo*& p, int chave);
	void ApagaRecursivo(TipoNo* p);
	void Antecessor(TipoNo* q, TipoNo*& r);

	TipoNo* raiz;
};

