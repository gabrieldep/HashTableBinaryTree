#include "BinaryTree.h"
#include "TipoItemArvore.h"
#include "Utils.h"
#include <iostream>

using namespace Utils;

BinaryTree::BinaryTree()
{
	raiz = nullptr;
}

BinaryTree::~BinaryTree()
{
	Limpa();
}

/// <summary>
/// Insere um elemento na ArvoreBinaria
/// </summary>
/// <param name="tipoItem">Item a ser adicionado</param>
void BinaryTree::Insere(TipoItemArvore tipoItem)
{
	InsereRecursivo(raiz, tipoItem);
}

/// <summary>
/// Pesquisa na arvore binaria algum elemento que possui a chave igual � chave recebida
/// </summary>
/// <param name="nome">Chave com o nome a ser procurado na arvore binaria</param>
/// <returns></returns>
TipoNo* BinaryTree::Pesquisa(int chave)
{
	return PesquisaRecursiva(raiz, chave);
}

/// <summary>
/// Remove o elemento com a chave recebida da arvore binaria.
/// </summary>
/// <param name="nome">Chave com o nome do elemento a ser removido da arvore.</param>
void BinaryTree::Remove(int chave)
{
	RemoveRecursiva(raiz, chave);
}

/// <summary>
/// Remove todos os elementos da arvore.
/// </summary>
void BinaryTree::Limpa()
{
	ApagaRecursivo(raiz);
	raiz = nullptr;
}

/// <summary>
/// Metodo auxiliar para adicionar elemento � arvore de maneira ordenada
/// </summary>
/// <param name="p">N� atual a ser verificado.</param>
/// <param name="item">Item a ser adicionado.</param>
void BinaryTree::InsereRecursivo(TipoNo*& p, TipoItemArvore item)
{
	if (p == nullptr) {
		p = new TipoNo();
		p->SetMessage(item.GetMessage());
	}
	else {
		if (item.GetId() < p->GetId())
			InsereRecursivo(p->esq, item);
		else
			InsereRecursivo(p->dir, item);
	}
}

/// <summary>
/// Metodo auxiliar para pesquisar elemento na arvore.
/// </summary>
/// <param name="p">N� atual a ser verificado</param>
/// <param name="chave">Chave para encontrar o elemento.</param>
/// <returns>TipoNo correspondente a chave recebida</returns>
TipoNo* BinaryTree::PesquisaRecursiva(TipoNo*& p, int chave)
{
	TipoNo* aux = new TipoNo();

	if (p == nullptr) {
		aux->SetMessage("");
		return aux;
	}
	if (chave < p->GetId())
		return PesquisaRecursiva(p->esq, chave);
	else if (p->GetId() < chave)
		return PesquisaRecursiva(p->dir, chave);
	else
		return p;
}

/// <summary>
/// Metodo auxiliar para remover elemento na arvore.
/// </summary>
/// <param name="p">N� atual a ser verificado</param>
/// <param name="chave">Chave para encontrar o elemento a ser removido.</param>
void BinaryTree::RemoveRecursiva(TipoNo*& p, int chave)
{
	if (p == nullptr)
		return;
	if (chave < p->GetId())
		RemoveRecursiva(p->esq, chave);
	else if (p->GetId() < chave)
		RemoveRecursiva(p->dir, chave);
	else {
		if (p->esq == nullptr)
			p = p->dir;
		else if (p->dir == nullptr)
			p = p->esq;
		else
			Antecessor(p, p->esq);
	}
}

/// <summary>
/// Metodo auxiliar para pesquisar elemento na arvore.
/// </summary>
/// <param name="p">N� atual a ser deletado</param>
void BinaryTree::ApagaRecursivo(TipoNo* p)
{
	if (p != nullptr) {
		ApagaRecursivo(p->esq);
		ApagaRecursivo(p->dir);
		delete p;
	}
}

/// <summary>
/// M�todo que reconstroi a arvore caso algum elemento seja retirado.
/// </summary>
/// <param name="q">Elemento removido</param>
/// <param name="r">Elemento que vai ocupar o lugar.</param>
void BinaryTree::Antecessor(TipoNo* q, TipoNo*& r)
{
	if (r->dir != nullptr) {
		Antecessor(q, r->dir);
		return;
	}
	q->message = r->message;
	q = r;
	r = r->esq;
	free(q);
}
