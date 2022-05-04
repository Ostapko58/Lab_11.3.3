#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<string>
using namespace std;


enum Specialnists
{
	computer_science,
	informatics,
	math_a_economics,
	physics_and_informatics,
	labor_education
};

struct Student
{
	char prizv[20];
	//string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};

};


void ToFile(Student& stud, const int N, char* filename);
void Create(Student& stud, const int N, char* filename)
{
	//fstream f("Student1.bit", ios::binary,ios::app);
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " �������: "; /*getline(cin, stud.prizv);*/cin.getline(stud.prizv, 20);
		do
		{
			if (strpbrk(stud.prizv, "0 123456789") != NULL)
			{
				//stud.prizv.erase(0, -1);
				cout << "�� ����� ������ �������, ���������� �����: " << endl;
				cout << " �������: "; cin.getline(stud.prizv, 20);
			}
		} while (strpbrk(stud.prizv, "0 123456789") != NULL);
		cout << " ����: "; cin >> stud.kyrs;
		do
		{
			if (cin.fail() || stud.kyrs < 1 || stud.kyrs>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ ����, ���������� �����: " << endl;
				cout << " ����: "; cin >> stud.kyrs;
			}
		} while (cin.fail() || stud.kyrs < 1 || stud.kyrs>5);

		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialst;
		do
		{
			if (cin.fail() || specialst < 0 || specialst>4)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������������(0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������) : ";
				cin >> specialst;
			}
		} while (cin.fail() || specialst < 0 || specialst>4);
		stud.specialst = (Specialnists)specialst;
		cout << " ������ � ����������: "; cin >> stud.math_grade;
		do
		{
			if (cin.fail() || stud.math_grade < 1 || stud.math_grade>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ � ����������: "; cin >> stud.math_grade;
			}
		} while (cin.fail() || stud.math_grade < 1 || stud.math_grade>5);
		cout << " ������ � ������: "; cin >> stud.physics_grade;
		do
		{
			if (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ � ������: "; cin >> stud.physics_grade;
			}
		} while (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5);
		switch (stud.specialst)
		{
		case computer_science:
			cout << " ������ � ������������� : "; cin >> stud.programing_grade;
			do
			{
				if (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � �������������: "; cin >> stud.programing_grade;
				}
			} while (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5);
			break;
		case informatics:
			cout << " ������ � ��������� ������ : "; cin >> stud.chisel_metod_grade;
			do
			{
				if (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � ��������� ������: "; cin >> stud.chisel_metod_grade;
				}
			} while (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5);
			break;
		default:
			cout << " ������ � ��������� : "; cin >> stud.pedagogic_grade;
			do
			{
				if (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � ���������: "; cin >> stud.pedagogic_grade;
				}
			} while (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5);
			break;
		}
		cout << endl;
		ToFile(stud, N, filename);
	}
	//f.close();

}

void ToFile(Student& stud, const int N, char* filename)
{
	ofstream f(filename, ios::binary | ios::app);
	f.write((char*)&stud, sizeof(Student));
	f.close();
}

void PrintFromFile(Student& stud, const int N, string* List, char* filename)
{
	ifstream f(filename, ios::binary);
	int num = 1;
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| � |     �������     | ���� |      ������������      | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	while (f.read((char*)&stud, sizeof(Student)))
	{
		cout << "| " << setw(1) << right << num++ << " ";
		cout << "| " << setw(17) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(23) << left << List[stud.specialst] << " "
			<< "| " << setw(19) << right << stud.math_grade << " "
			<< "| " << setw(15) << right << stud.physics_grade << " ";
		switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud.chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
	}
	/*for (int j = 0; j < N; j++)
	{
		f.read((char*)&stud, sizeof(Student));
		for (int i = 0; i < N; i++)
		{
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << stud[i].prizv
				<< "| " << setw(4) << right << stud[i].kyrs << " "
				<< "| " << setw(23) << left << List[stud[i].specialst] << " "
				<< "| " << setw(19) << right << stud[i].math_grade << " "
				<< "| " << setw(15) << right << stud[i].physics_grade << " ";
			switch (stud[i].specialst)
			{
			case computer_science:
				cout << "| " << setw(22) << setprecision(2) << fixed << right
					<< stud[i].programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
				break;
			case informatics:
				cout << "| " << setw(24) << setprecision(2) << fixed << right
					<< " |" << setw(27) << right << stud[i].chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
				break;
			default:
				cout << "| " << setw(24) << setprecision(2) << fixed << right
					<< " |" << setw(29) << right << " |" << setw(30) << right << stud[i].pedagogic_grade << " |" << endl;
				break;
			}
		}
	}*/

	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
	f.close();
}

void fWrite(fstream& f, const int i, Student x)
{
	f.seekp(i * (long)sizeof(Student)); // ���������� ��������
	f.write((char*)&x, sizeof(Student)); // �������� ��������
}

Student fRead(fstream& f, const int i)
{
	Student tmp;
	//char x;
	f.seekg(i * (long)sizeof(Student)); // ���������� ��������
	f.read((char*)&tmp, sizeof(Student)); // ��������� ��������
	return tmp;
}

void fChange(fstream& f, const int i, const int j)
{
	Student x = fRead(f, i);
	Student y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void Sort(Student& stud, const int N, char* filename)
{
	fstream f(filename, ios::binary | ios::in | ios::out);
	for (int i0 = 0; i0 < N - 1; i0++)
	{
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			Student a = fRead(f, i1);
			Student b = fRead(f, i1 + 1);
			if ((a.specialst > b.specialst)
				||
				(a.specialst == b.specialst &&
					a.math_grade < b.math_grade)
				||
				(a.specialst == b.specialst &&
					a.math_grade == b.math_grade &&
					a.prizv[0] > b.prizv[0])
				||
				(a.specialst == b.specialst &&
					a.math_grade == b.math_grade &&
					a.prizv[0] == b.prizv[0] &&
					a.prizv[1] == b.prizv[1]))
			{
				fChange(f, i1, i1 + 1);
			}
		}
	}
	f.seekp(0, ios::end);
}


int BinSearch(Student& stud1, const int N, string prizv, Specialnists special, int math_grade, char* filename)
{
	Student stud;
	fstream f(filename, ios::binary | ios::out | ios::in);
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		stud = fRead(f, m);
		if (stud.prizv == prizv && stud.specialst == special && stud.math_grade == math_grade)
			return m;
		if ((stud.math_grade < math_grade)
			||
			(stud.math_grade == math_grade &&
				stud.specialst < special) ||
			(stud.math_grade == math_grade &&
				stud.specialst == special &&
				stud.prizv < prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	/*f.seekg(m * (long)sizeof(Student));
	while (f.read((char*)&stud, sizeof(Student)))
	{

	}*/
	/*int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (stud.prizv == prizv && stud.specialst == special && stud.math_grade == math_grade)
			return m;
		if ((stud.math_grade < math_grade)
			||
			(stud.math_grade == math_grade &&
				stud.specialst < special) ||
			(stud.math_grade == math_grade &&
				stud.specialst == special &&
				stud.prizv < prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);*/
	return -1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string List[] = {
	"��������� �����",
	"�����������",
	"���������� �� ��������",
	"Գ���� �� �����������",
	"������� ��������"
	};
	Student stud;
	Specialnists special;
	char prizv[20];
	char fname[60];
	cout << "������ ��'� �����: "; cin.getline(fname, 60);
	int N,spec, math_grade,num;
	cout << "������ N: "; cin >> N;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "�� ����� ����� ���, ���������� �����: " << endl;
			cout << "������ N: "; cin >> N;
		}
	} while (cin.fail());

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(stud, N, fname);
			Sort(stud, N, fname);
			break;
		case 2:
			PrintFromFile(stud, N, List, fname);
			break;
		case 3:
			cin.get(); cin.sync();
			cout << " �������: "; cin.getline(prizv, 20);
			do
			{
				if (strpbrk(prizv, "0 123456789") != NULL)
				{
					cout << "�� ����� ������ �������, ���������� �����: " << endl;
					cout << " �������: "; cin.getline(prizv, 20);
				}
			} while (strpbrk(prizv, "0 123456789") != NULL);

			cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
			cin >> spec;
			if (cin.fail() || spec < 0 || spec>4)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ������ �����, ���������� �����: " << endl;
					cout << " ������������(0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������) : ";
					cin >> spec;
				} while (cin.fail() || spec < 0 || spec>4);
			}
			special = (Specialnists)spec;
			cout << " ������ � ����������: "; cin >> math_grade;
			if (cin.fail() || math_grade < 1 || math_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � ����������: "; cin >> math_grade;
				} while (cin.fail() || math_grade < 1 || math_grade>5);
			}

			num = BinSearch(stud, N, prizv, special, math_grade, fname);
			if (num == -1)
			{
				cout << "������ �������� ���� � ������" << endl;
			}
			else
			{
				cout << "���, ����� ������� ���� �� " << num + 1 << " � ������" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ������ ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0); 

	return 0;
}