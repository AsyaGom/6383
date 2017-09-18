/*******************************************************************************************************
    ����� �. �. 6383 ��, �/� 1, ������� 3.
    �������:
    ������� n �������, ��������������� �� 1 �� n. ��������� ���� ������� ��������� ��������.
    ����������, ����� �� ������� �� ���� ������� �� ������ ��������� ������ � ������ �������� �����.
    ������� ���������� � ������� ������� � ���� ������������������ ��� ����� i � j (i < j � i, j 1..n),
    �����������, ��� i-� � j-� ������ ��������� ��������.
*********************************************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


enum Errors
{
    N_IS_ODD_NUMBER,                // N - �������� �����
    I_IS_NOT_LESS_THAN_J,           // I >= J
    N_IS_NULL,                      // N = 0
    TOWN_IS_GREATER_THAN_N,         // ��������� ����� > n
    INVALID_VALUES_IN_ARRAY,        // ������������ �������� � ��������� �������
    INVALID_VALUES_IN_MY_TOWNS,     // ������������ �������� � �������, ����� �������� ���� ����
    GOOD                            // ��� ��
};

/*  �������, ������� ����������, ���� �� ���� ����� ����� ���������.
    ��� ����� ������� ������ � ������� ������ ����� ���������� ��������� ��� ������ �������. ����� ���������� ������,
    � ����� �� ���������� ��������� ��������� �������� �������
    ������� ������:
        �����������:    n - ����� �������
                        town_i, town_j - ������������ ������
        �����������:    road - ������� ���������
    ���������� 1 ��� 0
*/
bool find_way(unsigned long long n, unsigned long long town_i, unsigned long long town_j, bool** road);

/*  ����������� ������� "����� � �������"
    ����: ��� ������ ������������ ������� ������� ��� ������������ ������� ������� � ��������� ���� ��� ���
    ��������� O(V+E)
    ������� ������:
        �����������:    n - ����� �������
                        top - ������� �������
        �����������:    components - ��������� �� ������ ������� ��������� ��������� ��� ������ �������
                        num_components - ���������� ��������� ��������� �������
                        visited - ��������� �� ������, � ������ �������� ���������� � ��������� ������
                        road - ������� ��������� �� ������� ���������
    ������ �� ����������
*/
void dfs(unsigned long long n, unsigned long long top, unsigned long long* components, unsigned long long& num_components, bool* visited, bool** road);

/*  ������� ����� ������� ������� � ���������� �� � ������� ���������
    ������� ������:
        �����������:    n - ����� �������
        �����������:    road - ��������� �� ������� ��������� ������ - ������� ���������
    ���������� ��������� ������ ��� ����� ������� ( 0 < town < n )
*/
Errors input_and_test_town(unsigned long long n, bool** road,unsigned long long n_max, std::istream& in);

/*  ������� ����� ���������� �������
    ������� ������:
        �����������:    n - ����� �������
    ���������� ��������� ������ ��� ����� n (n > 0)
*/
Errors input_and_test_n(unsigned long long& n, std::istream& in);

/*  ������� ����� �������, ����� ������� ��������� ������ ����
    ������� ������:
        �����������:    n - ����� �������
        �����������:    town - ����� �� �������� ������
    ���������� ��������� ������ ��� ����� town (0 < town < n)
*/
Errors input_and_test_my_towns(unsigned long long n, unsigned long long& town, std::istream& in);
Errors input_and_test_n_max(unsigned long long& n, std::istream& in);

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long long n = 0;               // ���������� �������
    bool **road;                            // ������� ���������
    unsigned long long town_j = 0;          // ����� j
    unsigned long long town_i = 0;          // ����� i
    unsigned long long n_max = 0;           // ��� �������� ������
    cout << "������� ���������� �������: " << endl;
    Errors res_n = input_and_test_n(n, cin);
    /*if (res_n == N_IS_ODD_NUMBER)
    {
        cout << "��������� ���������� ������� �������. ����� ������ ������ ���������� �������." << endl;
        return -1;
    }*/
    if (res_n == N_IS_NULL)
    {
        cout << "�� ����� 0. ����� ������� ������ ���� �������������." << endl;
        return -1;
    }
    cout << "������� ���������� �����: ";
    Errors res_n_max = input_and_test_n(n_max, cin);
    if (res_n_max == N_IS_NULL)
    {
        cout << "�� ����� 0. ����� ������� ������ ���� �������������." << endl;
        return -1;
    }
    road = new bool*[n];
    for (unsigned long long i = 0; i < n; i++)
        road[i] = new bool[n];
    for (unsigned long long i = 0; i < n; i++)
        for (unsigned long long j = 0; j < n; j++)
            road[i][j] = 0;
    cout << "������� ������ �������: " << endl;
    Errors res_towns = input_and_test_town(n, road, n_max, cin);
    if (res_towns == INVALID_VALUES_IN_ARRAY)
    {
        cout << "������� ������� ������� � ������� (����� �� ������� ������ 1<=town<=n)" << endl;
        return -1;
    }
    if (res_towns == I_IS_NOT_LESS_THAN_J)
    {
        cout << "� �������� ���� i < j �� �������. ������!" << endl;
        return -1;
    }
    cout << "������� ������, ����� �������� ����� ������ ������������� ����: " << endl;
    Errors res_town_i = input_and_test_my_towns(n, town_i,  cin);
    cout << endl;
    if (res_town_i == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "C�������� ����� ������ �������." << endl;
        return -1;
    }
    Errors res_town_j = input_and_test_my_towns(n, town_j, cin);
    if (res_town_j == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "�������� ����� ������ �������." << endl;
        return -1;
    }
    cout << "������� ���������: \n";
    for (unsigned long long i = 0; i < n; i++)
    {
        for (unsigned long long j = 0; j < n; j++)
            cout << road[i][j] << " ";
        cout << endl;
    }
    if(find_way(n, town_i, town_j, road))
        cout << "\n���� ����� �������� " << town_i + 1 << " � " << town_j + 1 << " ����������." << endl;
    else
        cout << "\n���� ����� �������� " << town_i + 1 << " � " << town_j + 1 << " �� ����������." << endl;
    for (unsigned long long i = 0; i < n; i++)
        delete [] road[i];
    delete [] road;
    road = NULL;
    return 0;
}

Errors input_and_test_town(unsigned long long n, bool** road, unsigned long long n_max, std::istream& in)
{
    unsigned long long town_i, town_j, k = 2;
    while (k <= n_max * 2)
    {
        in >> town_i;
        in >> town_j;
        if (town_i >= town_j)
            return I_IS_NOT_LESS_THAN_J;
        if ((town_i < 1) || (town_i > n) || (town_j < 1) || (town_j > n))
            return INVALID_VALUES_IN_ARRAY;
        road[town_i - 1][town_j - 1] = true;
        road[town_j - 1][town_i - 1] = true;
        k += 2;
    }
    return GOOD;
}

bool find_way(unsigned long long n, unsigned long long town_i, unsigned long long town_j, bool** road)
{
    bool *visited;                              //  ������ ��������� ������
    unsigned long long *components;             //  ������, � ������� ������� ������ ��������� ��� ������ �������
    unsigned long long num_components = 0;      //  ����� ���������� ��������� ��� �������
    components = new unsigned long long[n];
    visited = new bool[n];
    for (unsigned long long i = 0; i < n; i++)
    {
        visited[i] = false;
        components[i] = 0;
    }
    for (unsigned long long i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(n, i, components, num_components, visited, road);
            num_components++;
        }
    for (unsigned long long i = 0; i < n; i++)
    if (components[town_i] == components[town_j])
        return true;
    else return false;
}

void dfs(unsigned long long n,unsigned long long top, unsigned long long* components, unsigned long long& num_components, bool* visited, bool** road)
{
    components[top] = num_components;
    visited[top] = true;
    for (unsigned long long j = 0; j < n; j++)
        if (road[top][j] != 0)
                if (!visited[j])
                    dfs(n, j, components, num_components, visited, road);
}


Errors input_and_test_n(unsigned long long& n, std::istream& in)
{
    in >> n;
    if (n < 1)
        return N_IS_NULL;
    return GOOD;
}

Errors input_and_test_n_max(unsigned long long& n, std::istream& in)
{
    in >> n;
    if (n < 1)
        return N_IS_NULL;
    if (n % 2 != 0)
        return N_IS_ODD_NUMBER;
    return GOOD;
}

Errors input_and_test_my_towns(unsigned long long n, unsigned long long& town, std::istream& in)
{
    in >> town;
    if (town < 1 || town > n)
        return INVALID_VALUES_IN_MY_TOWNS;
    town--;
    return GOOD;
}
