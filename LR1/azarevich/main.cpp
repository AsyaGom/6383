//
// ������������ ������ �1
// main.cpp
// �������� ����, ������ 6383
// 18.09.2017
//
// ��������� ��� ���������� ������������ �������������

#include "b_k.h"
using namespace std;


void f(ui &m, ui &n, Binomial &koef);


void main()
{
	setlocale(0, "");
	Binomial koef;
	ui m, n;

	//������ �� �������� ������ �� ����� test.txt
	ifstream fin ("test.txt");
	if ( fin.is_open() )
	{
		cout << "������ ���� � �������\n\n";
		while ( !fin.eof() )
		{
			fin >> m;
			fin >> n;

			cout << "m= " <<m<<";	n= "<<n<<";	";

			f(m, n, koef);
		}

		cout <<"������ ��������� ����� ��������\n\n\n";
		fin.close();
	}

	while (true)
	{
		cout << "m= ";
		cin  >> m;
		cout << "n= ";
		cin	 >> n;

		f(m, n, koef);
	}

}


void f(ui &m, ui &n, Binomial &koef)
{
	ull res = 0;

	if ( koef.colculate(m, n, res) )
		cout << "���. ����.= "<<res << endl;
	
	else
		cout << "��������� ������������\n";
}