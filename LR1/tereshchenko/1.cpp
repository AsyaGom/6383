// ������������ ������ �1
// 1.cpp
// ��������� ��������, ������ 6383
// 18.09.17
// ������� 21
// ��������� �������������� ���������� ��� ������� ������.
// 		������::=����������|�������
//		����������::=[[����������] (�������)]|B 
//		�������::=((�������) [����������])|A
// c - ������� ������ ������� ������

#include <iostream>
#include <fstream>

using namespace std ;
bool Brackets(ifstream &f);
bool Round (ifstream &f, char c);
bool Square (ifstream &f, char c);
void Error (short n);

int main ( )
{
	setlocale (LC_ALL,""); 
	ifstream f ("input.txt");
	if (!f.is_open()) { 
    	cout << "���� �� ����� ���� ������ ��� �� ������"; 
		return 1; 
	}
	bool a = Brackets (f);
	if (a) cout << "��, ��� ������" << endl;
	else cout << "���, ��� �� ������" << endl;
	system("pause");
	return 0;
}

bool Round (ifstream &f, char c)
{ 
	if (c == 'A')
		return true;
	else 
		if (c == '(')	{ 
		f >> c;
		if (Round (f, c)) 
			f >> c;
		else return false; 
		if (Square (f, c)) {
			f >> c;
			return (c == ')');
		}
		else return false;
	}
	else return false;
}

bool Square (ifstream &f, char c) 
{ 
	if (c == 'B') 
		return true;
	else if (c == '[') { 
		f >> c;
	if (Square (f, c))
			f >> c;
	else return false; 
	if (Round (f, c)) { 
		f >> c;
		return (c == ']');
	}
	else return false;
	}
	else return false;
}

bool Brackets(ifstream &f)
{ 
	char c;
	bool a;
	a = false;
	if (f >> c) {
		if ((c == 'B') || (c == '[')) a = Square (f, c);
		else if ((c == 'A') || (c == '(')) a = Round (f, c);
		else Error(1); 
	}
	else Error (0); 
	return a;
}

void Error (short n)
{
	cout << "err �" << n << endl;
	switch (n) {
		case 0: cout << "������ ������" << endl; 
		break; 
		case 1: cout << "������������ ��������� ������" << endl; 
		break; 
		default: 
		break; 
	};
}
