#pragma once
#include <string>

using namespace std;
class Email
{
private:
	int e;
	int u;
	int n;
	string message;
public:
	Email(int e, int u, int n, string message);
	Email(int e);
	Email();
	~Email();
	void SetE(int e);
	void SetN(int n);
	void SetU(int u);
	void SetMessage(string message);
	int GetE();
	int GetN();
	int GetU();
	string GetMessage();
};

