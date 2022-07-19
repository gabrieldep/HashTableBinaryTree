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
	while ((pos = message.find(delimiter)) != std::string::npos)
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

	}
	return email;
}

int main() {
	string line;
	ifstream myfile;

	int u, e, n, m;

	myfile.open("entrada_1.txt");
	myfile >> m;
	getline(myfile, line);
	HashTable* hash = new HashTable(m);

	while (getline(myfile, line)) {
		if (line[0] == 'E') {
			Email* email = GetEmailFromString(line, m);
			hash->InsereEmail(email);
		}
		else if (line[0] == 'C')
			break;
		else
			break;
	}
	myfile.close();
}