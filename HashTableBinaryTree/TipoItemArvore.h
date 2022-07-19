#pragma once
#include <string>
class TipoItemArvore
{
public:
	TipoItemArvore();
	TipoItemArvore(std::string nome, int id);
	void SetMessage(std::string valor);
	void SetId(int valor);
	std::string GetMessage();
	int GetId();
private:
	int id;
	std::string message;
};