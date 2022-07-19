#pragma once
#include <string>
class TipoNo
{
public:
	TipoNo();
	~TipoNo();
	void SetMessage(std::string nome);
	void SetId(int valor);
	std::string GetMessage();
	int GetId();
private:
	int id;
	TipoNo* esq;
	TipoNo* dir;
	std::string message;
	friend class BinaryTree;
};

