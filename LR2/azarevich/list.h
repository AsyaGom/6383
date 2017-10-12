#include <iostream>
#include <fstream>

using namespace std;

namespace h_list
{
	typedef char base;	// ������� ��� ��������� (������)
	struct s_expr;

	struct  two_ptr
	{
		s_expr *head; //��������� �� ������
		s_expr *tail; //��������� �� �����
	};

	struct s_expr 
	{
		bool tag; // true: atom, false: pair
		union  
		{
			base atom;	 //�������
			two_ptr pair;//��������� �� ������ � �����
		} 
		node;	
	};			

	typedef s_expr *list;

	// ������� �������:
	list head (const list s);
	list tail (const list s);
	list cons (const list h, const list t);
	list make_atom (const base x);
	bool isAtom (const list s);
	bool isNull (const list s);

	void destroy (list s);//�������� ������

	// ������� �����(�������� ������):
	void read_list ( list& y, istream &in);			// ��������
	void read_s_expr (base prev, list &y, istream &in); 
	void read_seq ( list& y, istream &in); 

	// ������� ������:
	void write_list (const list x);		// ��������
	void write_seq (const list x);  

	list copy_list (const list x);
}