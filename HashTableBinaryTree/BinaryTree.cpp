﻿#include "BinaryTree.h"
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
TipoNo* BinaryTree::Pesquisa(std::string nome)
{
	return PesquisaRecursiva(raiz, nome);
}

/// <summary>
/// Remove o elemento com a chave recebida da arvore binaria.
/// </summary>
/// <param name="nome">Chave com o nome do elemento a ser removido da arvore.</param>
void BinaryTree::Remove(std::string nome)
{
	RemoveRecursiva(raiz, nome);
}

/// <summary>
/// Imprime a arvore binaria em uma unica linha em ordem alfabetica.
/// </summary>
void BinaryTree::Imprime()
{
	InOrdem(raiz);
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
		p->SetNome(item.GetNome());

		TipoCelula celula = TipoCelula();
		celula.SetDados(item.GetDados());

		p->dadosBinarios->Enfileira(celula);
	}
	else {
		if (item.GetNome() == p->GetNome()) {
			TipoCelula celula = TipoCelula();
			celula.SetDados(item.GetDados());
			p->dadosBinarios->Enfileira(celula);
		}
		else if (VemAntes(item.GetNome(), p->GetNome()))
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
TipoNo* BinaryTree::PesquisaRecursiva(TipoNo*& p, std::string chave)
{
	TipoNo* aux = new TipoNo();

	if (p == nullptr) {
		aux->SetNome("404");
		return aux;
	}
	if (VemAntes(chave, p->GetNome()))
		return PesquisaRecursiva(p->esq, chave);
	else if (VemAntes(p->GetNome(), chave))
		return PesquisaRecursiva(p->dir, chave);
	else
		return p;
}

/// <summary>
/// Metodo auxiliar para remover elemento na arvore.
/// </summary>
/// <param name="p">N� atual a ser verificado</param>
/// <param name="chave">Chave para encontrar o elemento a ser removido.</param>
void BinaryTree::RemoveRecursiva(TipoNo*& p, std::string chave)
{
	if (p == nullptr)
		return;
	if (VemAntes(chave, p->GetNome()))
		RemoveRecursiva(p->esq, chave);
	else if (VemAntes(p->GetNome(), chave))
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
/// Metodo que imprime elementos em ordem.
/// </summary>
/// <param name="p">N� atual para ser impresso e procurar filhos.</param>
void BinaryTree::InOrdem(TipoNo* p)
{
	if (p != nullptr) {
		InOrdem(p->esq);
		p->ImprimeNome();
		InOrdem(p->dir);
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
	q->nome = r->nome;
	q->dadosBinarios = r->dadosBinarios;
	q = r;
	r = r->esq;
	free(q);
}
