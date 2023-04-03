#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialnist { Kn , In , Me, PhI , Tn };
enum Kurs { I = 1, II, III, IV, V, VI };
string specialnistStr[] { "����'����� �����", "�����������" ,  "���������� �� ��������" , "Գ���� �� �����������" , "������� ��������"};

struct Student
{
	string prizv;
	Kurs kurs;
	Specialnist specialnist;
	int physichs;
	int Math;
	union 
	{
		int programming;
		int chusel_methods;
		int pedagog;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int CountMarks(Student* p, const int N);
void PrintPrizv(Student* p, const int N);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int N,g;
	cout << "������ ������� ��������: "; 
	cin >> N;
	
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	g = CountMarks(p, N);
	cout << "ʳ������ ������ ���������� � ������� ��������: " << g << endl;
	PrintPrizv(p, N);

	return 0;
}

void Create(Student* p, const int N)
{
	int specialnist,kurs;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);

		cout << "���� (1-6): ";
		cin >> kurs;
		p[i].kurs = (Kurs)kurs;

		cout << "������ � ������: ";
		cin >> p[i].physichs;

		cout << "������ � ����������: ";
		cin >> p[i].Math;

		cout << " ������������ ( 0 - ����'����� ����� , 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialnist;
		p[i].specialnist = (Specialnist)specialnist;
		switch (p[i].specialnist)
		{
		case Kn:
			cout << " ������ � �������������: "; cin >> p[i].programming;
			break;
		case In:
			cout << " ������ � ��������� ������: "; cin >> p[i].chusel_methods;
			break;
		case Me:
		case PhI:
		case Tn:
			cout << " ������ � ���������: "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==========================================================================================================================="
		<< endl;
	cout << "| � | �������    | ���� |      ������������      | Գ���� | ���������� |  �������������  | ������� ������ | ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(12) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(24) << left << specialnistStr[p[i].specialnist]
			<< "| " << setw(7) << right << p[i].physichs
			<< "| " << setw(11) << right << p[i].Math;

		switch (p[i].specialnist)
		{
		case Kn:
			cout << "| " << setw(15) << p[i].programming << right << " | " << setw(18) << " | " << setw(12) << " |" << endl;
			break;
		case In:
			cout << "| " << setw(18) << " | " << setw(15) << p[i].chusel_methods << right << " | " << setw(12) << " |" << endl;
			break;
		case Me:
		case PhI:
		case Tn:
			cout << "| " << setw(18) << " | " << setw(18) << " | " << setw(10) << p[i].pedagog << right << " |" << endl;
			break;
		}
	}
	cout << "==========================================================================================================================="
		<< endl;
	cout << endl;
}



int CountMarks(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].programming != 0)
		{
			int a[3] = { p[i].physichs,p[i].Math,p[i].programming };
			for (int j = 0; j < 3; j++)
			{
				if (a[j] == 3)
				{
					n++;
				}
			}
		}
		else if (p[i].chusel_methods != 0)
		{
			int a[3] = { p[i].physichs,p[i].Math,p[i].chusel_methods };
			for (int j = 0; j < 3; j++)
			{
				if (a[j] == 3)
				{
					n++;
				}
			}
		}
		else if (p[i].pedagog != 0)
		{
			int a[3] = { p[i].physichs,p[i].Math,p[i].pedagog };
			for (int j = 0; j < 3; j++)
			{
				if (a[j] == 3)
				{
					n++;
				}
			}
		}
	}
	return n;
}


void PrintPrizv(Student* p, const int N)
{
	cout << "������� ��������, �� �������� � � ������ � � ���������� ������ �5� ��� �4�.:" << endl;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].physichs == 5 || p[i].physichs == 4) && (p[i].Math == 5 || p[i].Math == 4))
		{
			cout << setw(3) <<" " << p[i].prizv << endl;
		}
	}
}