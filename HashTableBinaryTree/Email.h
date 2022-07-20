#pragma once
#include <string>

using namespace std;
class Email
{
private:
	int e;
	int u;
	int b;
	string message;
public:
	Email(int e, int u, int n, string message);
	Email(int e);
	Email();
	~Email();
	void SetE(int e);
	void SetB(int n);
	void SetU(int u);
	void SetMessage(string message);
	int GetE();
	int GetB();
	int GetU();
	string GetMessage();
};

