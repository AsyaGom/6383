#include <iostream>
#include <fstream>
//#include <stdin.h>
//������� ����� ��� � VS2008

typedef unsigned long long ull;
typedef unsigned int ui;

class Binomial
{
public:
	Binomial();
	~Binomial();
	bool colculate(ui &m, ui &n, ull &res);

private:
	ull **save;		 //�������� ���-��� ���. ����.
	bool NotOverFlow;//���� ������������
	ui Nmax;		 //���c. ������������� n	

	void more(ui n);
	ull binom(ui m, ui n);
};