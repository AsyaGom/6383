//
// ������������ ������ �1
// lab1.cpp
// ���������� ���������, ������ 6383
// 18.09.17
//
// ��������� ��� ������ ���� ������������ ��������

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// ������� ������ x � y �������
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// ����������� ������� ��������� ���� ��������� ������������ ������
void next(int k, char *A, const int n, bool toFile) {
	if (k == n)
	{
		for (int i = 0; i < n; i++)
				cout << A[i];

		if (!toFile)
			cout << endl;
		else
			cout << endl;
		return;
	}

	for (int i = k; i < n; i++)
	{
		//cout << k << " " << i << endl;
		swap(A[k], A[i]);
		next(k + 1, A, n, toFile);
		swap(A[k], A[i]);
	}
}

// ������� ����
void Menu() {
	cout << "���� �� ������ ������ ������� �� ������� - ������� 1." << endl;
	cout << "���� �� ������ ������� ������� �� ����� - ������� 2." << endl;
	cout << "���� �� ������ ����� - ������� 3." << endl;
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int m; 
	Menu();
	cout << "\n������� ����� ��������: ";
	cin >> m;
	while (true) {
		switch (m) { 
		case 1: { 
			system("cls");
			char A[1000] = {};
			int n;
			cout << "������� ���������� �������� ��������: ";
			cin >> n;
			while (n <= 0) {
				cout << "���������� �������� ������ ���� �������������. ���������� ��� ���." << endl;
				cin >> n;
			}
			cout << "\n������� �������: ";
			cin >> A;
			while (n != strlen(A)) {
				cout << "�������� ���������� ��������. ���������� ��� ���: " << endl;
				cout << "\n������� �������: ";
				cin >> A;
			}
			next(0, A, n, false);
			Menu();
			cout << "\n������� ����� ��������: ";
			cin >> m;
			break;
		}
		case 2: {
			system("cls");
			ifstream in;
			in.open("in.txt"); 
			if (!in) {
				cout << "����� � ������� �� ����������. ������� ������� � �������." << endl << "\n";
				cout << "\n������� 1: ";
				cin >> m;
				break;
			}
			char A[1000];
			int n;
			in >> n;
			for (int i = 0; i < n; i++)
				in >> A[i];
			next(0, A, n, true);
			Menu();
			cout << "\n������� ����� ��������: ";
			cin >> m;
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		default:
			cout << "\n�������� ����. ���������� ��� ���." << endl; 
			Menu();
			cout << "\n������� ����� ��������: ";
			cin >> m;
			break;
		}
	}
}