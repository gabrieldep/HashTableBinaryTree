#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Utils.h"
#include "HashTable.h"

using namespace std;

Email* GetEmailFromString(string message, int m) {
	Email* email = new Email();
	string delimiter = " ";
	size_t pos = 0;
	int aux = 0;
	while (true)
	{
		if (aux == 4) {
			string texto = message.substr(0, message.size());
			email->SetMessage(texto);
			message.erase(0, message.size());
		}
		else {
			string palavra = message.substr(0, message.find(delimiter));
			message.erase(0, message.find(delimiter) + delimiter.length());
			if (aux == 1)
				email->SetU(stoi(palavra));
			else if (aux == 2) {
				email->SetE(stoi(palavra));
				email->SetN(email->GetU() % m);
			}
			aux++;
		}
		if ((pos = message.find(delimiter)) == std::string::npos)
			break;
	}
	return email;
}

int* GetIndicesConsulta(string message) {
	int* valores = new int[2];
	string delimiter = " ";
	message.erase(0, message.find(delimiter) + delimiter.length());
	string palavra = message.substr(0, message.find(delimiter));
	message.erase(0, message.find(delimiter) + delimiter.length());
	valores[0] = stoi(palavra);

	palavra = message.substr(0, message.find(delimiter));
	message.erase(0, message.find(delimiter) + delimiter.length());
	valores[1] = stoi(palavra);
	return valores;
}

int main() {
	string line;
	ifstream myfile;
	int u = 0, e = 0, n = 0, m = 0;

	myfile.open("entrada_1.txt");
	myfile >> m;
	getline(myfile, line);
	HashTable* hash = new HashTable(m);

	while (getline(myfile, line)) {
		if (line[0] == 'E') {
			Email* email = GetEmailFromString(line, m);
			BinaryTree* arvore = hash->Pesquisa(email->GetN());
			arvore->Insere(*email);
			string a = "";
		}
		else if (line[0] == 'C') {
			int* valores = GetIndicesConsulta(line);
			cout << hash->Pesquisa(valores[0])->Pesquisa(valores[1])->GetEmail()->GetMessage() << endl;
		}
		else {
			int* valores = GetIndicesConsulta(line);
			hash->Pesquisa(valores[0])->Remove(valores[1]);
		}
	}
	myfile.close();
}