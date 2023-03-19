#include<iostream>
#include "managersystem.h"
#include "student.h"
#include<fstream>
#include<iostream>
using namespace std;

managersystem::managersystem()
{
	ifstream ifs1;
	ifs1.open(FILENAME, ios::in);
	if (!ifs1.is_open())//1.ѧ���ļ�������
	{
		//��ʼ��
		this->StudentNum = 0;
		this->m_Array = NULL;
		this->IsStudentFileEmpty = true;
		ifs1.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		//�ļ�Ϊ��

		this->StudentNum = 0;
		this->m_Array = NULL;
		this->IsStudentFileEmpty = true;
		ifs1.close();
		return;
	}
	//3.�ļ����ڣ����ݲ�Ϊ��
	int num = this->get_StudentNumber();
	this->StudentNum = num;
	//���ٿռ�
	this->m_Array = new Student * [this->StudentNum];
	//���ļ����ݴ浽������
	this->Init_Student();
	ifstream ifs2;
	ifs2.open(FILECOURSE, ios::in);
	if (!ifs2.is_open())//1.�γ��ļ�������
	{
		//��ʼ��
		this->CourseNum = 0;
		this->m_CourseArray = NULL;
		this->IsCourseFileEmpty = true;
		ifs2.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch1;
	ifs2 >> ch1;
	if (ifs2.eof())
	{
		//�ļ�Ϊ��

		this->CourseNum = 0;
		this->m_CourseArray = NULL;
		this->IsCourseFileEmpty = true;
		ifs2.close();
		return;
	}
	//3.�ļ����ڣ����ݲ�Ϊ��
	int num1 = this->get_CourseNumber();
	this->CourseNum = num1;
	//���ٿռ�
	this->m_CourseArray = new Course * [this->CourseNum];
	//���ļ����ݴ浽������
	this->Init_Course();
}
managersystem::~managersystem()
{
	if (this->m_Array != NULL)
	{
		delete this->m_Array;
		this->m_Array = NULL;
	}
	if (this->m_CourseArray != NULL)
	{
		delete this->m_CourseArray;
		this->m_CourseArray = NULL;
	}
}
void managersystem::menu()
	{
		cout << "*********��ӭ����ѧ������ϵͳ**************" << endl;
		cout << "****     1.���ѧ����¼��ȱ�μ�¼     *****" << endl;
		cout << "****	 2.��ѯѧ��������Ϣ         *****" << endl;
		cout << "****     3.��ʾѧ����Ϣ��ȱ����Ϣ     *****" << endl;
		cout << "****     4.�޸�ѧ����Ϣ��ȱ����Ϣ     *****" << endl;
		cout << "****     5.ɾ��ѧ����Ϣ               *****" << endl;
		cout << "****     6.������Ϣͳ�ƹ���           *****" << endl;
		cout << "****     7.�˳�ϵͳ                   *****" << endl;
		cout << "*******************************************" << endl;
	}


void managersystem::exitsystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void managersystem::Add()
{
	int choose;
	cout << "��ѡ����Ҫ��ӵ����ݣ�" << endl;
	cout << "1.ѧ����Ϣ" << endl;
	cout << "2.ѧ��ȱ����Ϣ" << endl;
	cin >> choose;
	while (choose > 2 || choose < 1)
	{
		cout << "�Ƿ����룡���������룺" << endl;
		cin >> choose;
	}
	switch (choose)
	{
	case 1:
	{
		this->AddStudent();
		break;
	}
	case 2:
	{
		this->AddRecord();
		break;
	}
	}
}
int managersystem::GetSex()
{
	int number;
	cout << "��ѡ���Ա�" << endl;
	cout << "1.��" << endl;
	cout << "2.Ů" << endl;
	cin >> number;
	while (number > 2 || number < 1)
	{
		cout << "�Ƿ����룡���������룺" << endl;
		cin >> number;
	}
	return number;
}

void managersystem::GetInStudentFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->StudentNum; i++)
	{
		ofs << this->m_Array[i]->m_num << " "
			<< this->m_Array[i]->m_name << " "
			<< this->m_Array[i]->m_sex << " "
			<< this->m_Array[i]->m_age << " "
			<< this->m_Array[i]->m_class << endl;
	}
	ofs.close();
}

void managersystem::AddStudent()
{
	int number;
	cout << "��������Ҫ��ӵ�ѧ��������" << endl;
	cin >> number;
	int Newsize = this->StudentNum + number;
	Student** s = new Student * [Newsize];
	if (this->m_Array != NULL)
	{
		for (int i = 0; i < this->StudentNum; i++)
		{
			s[i] = this->m_Array[i];
		}
	}

	for (int i = this->StudentNum; i < Newsize; i++)
	{
		cout << "������ѧ��ѧ�ţ�" << endl;
		string num;
		cin >> num;
		int flag1=1;
		while (flag1==1)
		{
			flag1= 0;
			for (int j = 0; j < this->StudentNum; j++)
			{
				if (this->m_Array[j]->m_num == num)
				{
					cout << "ѧ���ظ������������룺" << endl;
					cin >> num;
					flag1 = 1;
					break;
				}
			}
		}
		cout << "������ѧ��������" << endl;
		string name;
		cin >> name;
		string sex;
		int n = this->GetSex();
		if (n == 1)
		{
			sex = "��";
		}
		else
		{
			sex = "Ů";
		}
		int age;
		cout << "������ѧ�����䣺" << endl;
		cin >> age;
		string cl;
		cout << "������ѧ�����ڰ༶��" << endl;
		cin >> cl;
		Student* s1 = new Student(num, name, sex, age, cl);
		s[i] = s1;
		cout << "��ӳɹ���" << endl;
	}

	this->StudentNum = Newsize;
	this->m_Array = s;
	this->GetInStudentFile();
	cout << "�����" << number << "��ѧ����" << endl;
}

void managersystem::AddRecord()
{
	cout << "������ȱ��������" << endl;
	int num;
	cin >> num;
	int Newsize = num + this->CourseNum;
	Course** c = new Course * [Newsize];
	if (this->m_CourseArray != NULL)
	{
		for (int i = 0; i < this->CourseNum; i++)
		{
			c[i] = this->m_CourseArray[i];
		}
	}
	
	for (int i = this->CourseNum; i < Newsize; i++)
	{
		cout << "������ȱ�����ڣ�" << endl;
		string date;
		cin >> date;
		cout << "������ڼ��ڿΣ�" << endl;
		int num;
		cin >> num;
		cout << "������γ����ƣ�" << endl;
		string cname;
		cin >> cname;
		cout << "������ѧ��������" << endl;
		string sname;
		cin >> sname;
		string type;
		int choice = this->GetType();
		switch (choice)
		{
		case 1:
		{
			type = "�ٵ�";
			break;
		}
		case 2:
		{
			type = "����";
			break;
		}
		case 3:
		{
			type = "���";
			break;
		}
		case 4:
		{
			type = "����";
			break;
		}
		}
		Course* course = new Course(date, num, cname, sname, type);
		c[i] = course;
		cout << "�ɹ���ӣ�" << endl;
	}
	delete[]this->m_CourseArray;
	this->CourseNum = Newsize;
	this->m_CourseArray = c;
	this->GetInCourseFile();
	cout << "�ѳɹ����" << num << "����¼��" << endl;
}


int managersystem::GetType()
{
	cout << "��ѡ��ȱ�����ͣ�" << endl;
	cout << "1.�ٵ�" << endl;
	cout << "2.����" << endl;
	cout << "3.���" << endl;
	cout << "4.����" << endl;
	int choice;
	cin >> choice;
	while (choice > 4 || choice < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	return choice;
}

void managersystem::GetInCourseFile()
{
	ofstream ofs;
	ofs.open(FILECOURSE, ios::out);
	for (int i = 0; i < this->CourseNum; i++)
	{
		ofs << this->m_CourseArray[i]->m_date << " "
			<< this->m_CourseArray[i]->m_num << " "
			<< this->m_CourseArray[i]->m_cname << " "
			<< this->m_CourseArray[i]->m_sname << " "
			<< this->m_CourseArray[i]->type << endl;
	}
	ofs.close();
}

void managersystem::SearchStudent()
{	
	if (this->IsStudentFileEmpty)
	{
		cout << "�ü�¼Ϊ�գ�" << endl;
		return;
	}
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.����" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		cout << "������ѧ�ţ�" << endl;
		string num;
		cin >> num;
		int flag = 0;
		for (int i = 0; i < this->StudentNum; i++)
		{
			if (this->m_Array[i]->m_num == num)
			{
				this->m_Array[i]->ShowStudent();
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ���ѧ����" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < this->StudentNum; i++)
		{
			if (this->m_Array[i]->m_name == name)
			{
				this->m_Array[i]->ShowStudent();
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ���ѧ����" << endl;
		}
		break;
	}
	}
}


void managersystem::SearchCourse()
{
	if (this->IsCourseFileEmpty)
	{
		cout << "�ü�¼Ϊ�գ�" << endl;
		return;
	}
	cout << "��������ҷ�ʽ��"<<endl;
	cout << "1.�γ���" << endl;
	cout << "2.ѧ����" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		cout << "������γ����ƣ�" << endl;
		string cname;
		cin >> cname;
		int flag = 0;
		for (int i = 0; i < this->CourseNum; i++)
		{
			if (this->m_CourseArray[i]->m_cname==cname)
			{
				this->m_CourseArray[i]->ShowCourse();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ��ü�¼��" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "������ѧ�����ƣ�" << endl;
		string sname;
		cin >> sname;
		int flag = 0;
		for (int i = 0; i < this->CourseNum; i++)
		{
			if (this->m_CourseArray[i]->m_sname == sname)
			{
				this->m_CourseArray[i]->ShowCourse();
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "δ�ҵ��ü�¼��" << endl;
		}
		break;
	}
	}
}


void managersystem::Search()
{
	cout << "�������ѯ����Ϣ���" << endl;
	cout << "1.ѧ����Ϣ" << endl;
	cout << "2.�γ���Ϣ" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		this->SearchStudent();
		break;
	}
	case 2:
	{
		this->SearchCourse();
		break;
	}
	}
}

int managersystem::get_StudentNumber()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	string num;
	string name;
	string sex;
	int age;
	string cl;
	int Index = 0;
	while (ifs >> num && ifs >> name && ifs >> sex&&ifs>>age&&ifs>>cl)
	{
		Index++;
	}
	return Index;
}

void managersystem::Init_Student()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string num;
	string name;
	string sex;
	int age;
	string cl;
	int Index = 0;
	while (ifs >>num  && ifs >>name  && ifs >>sex&&ifs>>age&&ifs>>cl )
	{
		Student* s = new Student(num, name, sex, age, cl);
		this->m_Array[Index] = s;
		Index++;
	}
	//�ر��ļ�
	ifs.close();
}

int managersystem::get_CourseNumber()
{
	ifstream ifs;
	ifs.open(FILECOURSE, ios::in);//���ļ�
	string date;
	int num;
	string cname;
	string sname;
	string type;
	int Index = 0;
	while (ifs >> date && ifs >> num && ifs >> cname && ifs >> sname && ifs >> type)
	{
		Index++;
	}
	return Index;
}

void managersystem::Init_Course()
{
	ifstream ifs;
	ifs.open(FILECOURSE, ios::in);//���ļ�
	string date;
	int num;
	string cname;
	string sname;
	string type;
	int Index = 0;
	while (ifs >> date && ifs >> num && ifs >> cname && ifs >> sname && ifs >> type)
	{
		Course* course = new Course(date, num, cname, sname, type);
		this->m_CourseArray[Index] = course;
		Index++;
	}
}


void managersystem::ShowMessage()
{
	cout << "����ѧ����¼���£�" << endl;
	for(int i = 0; i < this->StudentNum; i++)
	{
		this->m_Array[i]->ShowStudent();
	}
	cout << endl << endl;
	cout << "���п��ڼ�¼���£�" << endl;
	for (int i = 0; i < this->CourseNum; i++)
	{
		this->m_CourseArray[i]->ShowCourse();
	}
}

void managersystem::ChangeMessage()
{
	cout << "�����������޸ĵ���Ϣ��" << endl;
	cout << "1.ѧ����Ϣ" << endl;
	cout << "2.������Ϣ" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		if (this->IsStudentFileEmpty)
		{
			cout << "�ü�¼Ϊ�գ�" << endl;
			return;
		}
		for (int i = 0; i < this->StudentNum; i++)
		{
			cout <<"["<< i << "]";
			this->m_Array[i]->ShowStudent();
		}
		cout << "�����������޸ĵ�������ţ�" << endl;
		int num;
		cin >> num;
		while (num > this->StudentNum||num<0)
		{
			cout << "����Ƿ�������������" << endl;
		}
		cout << "�����������޸ĵ�������ţ�"<<endl;
		cout << "[1]" << this->m_Array[num]->m_num << endl;
		cout << "[2]" << this->m_Array[num]->m_name << endl;
		cout << "[3]" << this->m_Array[num]->m_sex << endl;
		cout << "[4]" << this->m_Array[num]->m_age << endl;
		cout << "[5]" << this->m_Array[num]->m_class << endl;
		int number;
		cin >> number;
		while (number > 5 || number < 1)
		{
			cout << "�Ƿ����룡���������룺" << endl;
			cin >> number;
		}
		switch (number)
		{
		case 1:
		{
			cout << "�������޸ĺ�����ݣ�" << endl;
			string NewNumber;
			cin >> NewNumber;
			this->m_Array[num]->m_num = NewNumber;
			break;
		}
		case 2:
		{
			cout << "�������޸ĺ�����ݣ�" << endl;
			string NewName;
			cin >> NewName;
			this->m_Array[num]->m_name = NewName;
			break;
		}
		case 3:
		{
			int aws=this->GetSex();
			if (aws == 1)
			{
				this->m_Array[num]->m_sex = "��";
			}
			if (aws == 2)
			{
				this->m_Array[num]->m_sex = "Ů";
			}
			break;
		}
		case 4:
		{
			cout << "�������޸ĺ�����ݣ�" << endl;
			int NewAge;
			cin >> NewAge;
			this->m_Array[num]->m_age = NewAge;
			break;
		}
		case 5:
		{
			cout << "�������޸ĺ�����ݣ�" << endl;
			string cl;
			cin >> cl;
			this->m_Array[num]->m_class = cl;
		}
		}
		this->GetInStudentFile();
		break;
	}
	case 2:
	{
		if (this->IsCourseFileEmpty)
		{
			cout << "�ü�¼Ϊ�գ�" << endl;
			return;
		}
		for (int i = 0; i < this->CourseNum; i++)
		{
			cout <<"[" << i << "]";
			this->m_CourseArray[i]->ShowCourse();
		}
		cout << "�����������޸ĵ�������ţ�" << endl;
		int n;
		cin >> n;
		while (n > this->CourseNum || n < 0)
		{
			cout << "�Ƿ����룡���������룺" << endl;
			cin >> n;
		}
		cout << "[1]" << this->m_CourseArray[n]->m_date<<endl;
		cout << "[2]" << this->m_CourseArray[n]->m_num << endl;
		cout << "[3]" << this->m_CourseArray[n]->m_cname << endl;
		cout << "[4]" << this->m_CourseArray[n]->m_sname << endl;
		cout << "[5]" << this->m_CourseArray[n]->type << endl;
		cout << "�����������޸ĵ�������ţ�" << endl;
		int nn;
		cin >> nn;
		while (nn > 5 || nn < 1)
		{
			cout << "�Ƿ����룡���������룺" << endl;
			cin >> nn;
		}
		switch (nn)
		{
		case 1:
		{
			string NewDate;
			cin >> NewDate;
			this->m_CourseArray[n]->m_date = NewDate;
			break;
		}
		case 2:
		{
			int NewNum;
			cin >> NewNum;
			this->m_CourseArray[n]->m_num = NewNum;
			break;
		}
		case 3:
		{
			string NewCname;
			cin >> NewCname;
			this->m_CourseArray[n]->m_cname = NewCname;
			break;
		}
		case 4:
		{
			string NewSname;
			cin >> NewSname;
			this->m_CourseArray[n]->m_sname = NewSname;
			break;
		}
		case 5:
		{
			int nnn = this->GetType();
			if (nnn == 1)
			{
				this->m_CourseArray[n]->type = "�ٵ�";
			}
			if (nnn == 2)
			{
				this->m_CourseArray[n]->type = "����";
			}
			if (nnn == 3)
			{
				this->m_CourseArray[n]->type = "���";
			}
			if (nnn == 4)
			{
				this->m_CourseArray[n]->type = "����";
			}
			break;
		}
		}
		this->GetInCourseFile();
		break;
	}
	}
	cout << "�޸ĳɹ���" << endl;
}

void managersystem::DeleteMessage()
{
	if (this->IsStudentFileEmpty)
	{
		cout << "�ü�¼Ϊ�գ�" << endl;
		return;
	}
	cout << "����ѧ����¼���£�" << endl;
	for (int i = 0; i < this->StudentNum; i++)
	{
		cout << "[" << i << "]";
		this->m_Array[i]->ShowStudent();
	}
	cout << "��ѡ����Ҫɾ���ļ�¼��ţ�" << endl;
	int choice;
	cin >> choice;
	while (choice<0 || choice>=this->StudentNum)
	{
		cout << "�Ƿ����룡���������룺" << endl;
		cin >> choice;
	}
	delete this->m_Array[choice];
	for (int i = choice; i < this->StudentNum-1; i++)
	{
		this->m_Array[i] = this->m_Array[i + 1];
	}
	this->StudentNum--;
	this->GetInStudentFile();
	cout << "ɾ���ɹ���" << endl;
}

void managersystem::Count()
{
	if (this->IsCourseFileEmpty)
	{
		cout << "�ü�¼Ϊ��!" << endl;
		return;
	}
	cout << "��ѡ��ͳ�ƵĲ�����" << endl;
	cout << "1.�γ���" << endl;
	cout << "2.����" << endl;
	int c;
	cin >> c;
	while (c<1||c>2)
	{
		cout << "�Ƿ����룡���������룺" << endl;
		cin >> c;
	}
	switch (c)
	{
	case 1:
	{

		for (int i = 0; i < this->CourseNum; i++)
		{
			cout << "[" << i << "]";
			cout<<this->m_CourseArray[i]->m_cname<<endl;
		}
		cout << "������ѡ�" << endl;
		int n;
		cin >> n;
		while (n >= this->CourseNum || n < 0)
		{
			cout << "�Ƿ����룡���������룺" << endl;
			cin >> n;
		}
		for (int i = 0; i < this->CourseNum; i++)
		{
			if (this->m_CourseArray[i]->m_cname == this->m_CourseArray[n]->m_cname)
			{
				this->m_CourseArray[i]->ShowCourse();
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < this->CourseNum; i++)
		{
			cout << "[" << i << "]";
			cout << this->m_CourseArray[i]->m_sname << endl;
		}
		cout << "������ѡ�" << endl;
		int n;
		cin >> n;
		while (n >= this->CourseNum || n < 0)
		{
			cout << "�Ƿ����룡���������룺" << endl;
			cin >> n;
		}
		for (int i = 0; i < this->CourseNum; i++)
		{
			if (this->m_CourseArray[i]->m_sname == this->m_CourseArray[n]->m_sname)
			{
				this->m_CourseArray[i]->ShowCourse();
			}
		}
		break;
	}
	}
}