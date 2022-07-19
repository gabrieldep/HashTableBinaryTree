#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Utils.h"
#include "HashTable.h"

using namespace std;

Email GetEmailFromString(string message) {

}

int main()
{
	string line;
	ifstream myfile;

	int u, e, n, m;

	myfile.open("entrada_1.txt");
	myfile >> m;

	HashTable* hash = new HashTable(m);

	while (getline(myfile, line))
	{
		if (line[0] == 'E')
			hash->InsereEmail(&GetEmailFromString(line));
		else if (line[0] == 'C')
			break;
		else
			break;
	}
	myfile.close();
}