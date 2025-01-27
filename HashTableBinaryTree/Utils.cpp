#include "Utils.h"

bool Utils::VemAntes(std::string primeira, std::string segunda)
{
	int tamanho = primeira.size() > segunda.size() ?
		segunda.size() : primeira.size();

	for (int i = 0; i < tamanho; i++)
		if (primeira[i] != segunda[i])
			return primeira[i] < segunda[i];
	return primeira.size() < segunda.size();
}
