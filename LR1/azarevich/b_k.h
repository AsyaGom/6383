#include <iostream>
#include <fstream>

typedef unsigned long long ull;
typedef unsigned int ui;

class b_k
{
private:
	ull **save;		//�������� ���-��� ���. ����.

public:
	bool isOverFlow;//���� ������������
	ui Nmax;		//���c. ������������� n

	b_k();
	~b_k();

	void more(ui n);
	ull binom(ui m, ui n);
};