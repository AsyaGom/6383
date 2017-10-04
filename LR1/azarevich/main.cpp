//
// ������������ ������ �1
// main.cpp
// �������� ����, ������ 6383
// 18.09.2017
//
// ��������� ��� ���������� ������������ �������������


#include "b_k.h"
using namespace std;


void main()
{
	setlocale(0, "");
	unsigned int m, n;
	bool isOverflow = false;

	unsigned long long res = 0;

	ifstream fin ("test.txt");
	ofstream fout("out.txt");
	
	b_k koef;

	//������ �� �������� ������ �� ����� test.txt
	if ( fin.is_open() )
	{
		cout << "������ ���� � �������\n\n";
		fout << "������ ���� � �������\n\n";
		while ( !fin.eof() )
		{
			fin >> m;
			fin >> n;

			cout << "m= " <<m<<";	n= "<<n<<";	";
			fout << "m= " <<m<<";	n= "<<n<<";	";

			if ( m>n )
			{
				cout << "���. ����.= 0" << endl;
				fout << "���. ����.= 0" << endl;
			}
			else 
			{
				if (n >= koef.Nmax) koef.more(n);

				res = koef.binom(m, n);
				if (koef.isOverFlow)
					{
					cout << "���. ����.= "<<res << endl;
					fout << "���. ����.= "<<res << endl;
				}
				else 
				{
					cout << "��������� ������������\n";
					fout << "��������� ������������\n";
				}

			}
		}
		fout <<"������ ��������� ����� ��������\n\n\n";
		cout <<"������ ��������� ����� ��������\n\n\n";

		fin.close();
	}

	while (true)
	{
		cout << "m= ";
		cin  >> m;
		cout << "n= ";
		cin	 >> n;

		fout << "m= " <<m<<";	n= "<<n<<";	";

		if ( m>n )
			{
				cout << "���. ����.= 0" << endl;
				fout << "���. ����.= 0" << endl;
			}
			else
			{
				if (n >= koef.Nmax) koef.more(n);

				res = koef.binom(m, n);
				if (koef.isOverFlow)
					{
					cout << "���. ����.= "<<res << endl;
					fout << "���. ����.= "<<res << endl;
				}
				else 
				{
					cout << "��������� ������������\n";
					fout << "��������� ������������\n";
				}
			}
		

	}
	
}