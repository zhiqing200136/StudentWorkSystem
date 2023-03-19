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
	if (!ifs1.is_open())//1.学生文件不存在
	{
		//初始化
		this->StudentNum = 0;
		this->m_Array = NULL;
		this->IsStudentFileEmpty = true;
		ifs1.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs1 >> ch;
	if (ifs1.eof())
	{
		//文件为空

		this->StudentNum = 0;
		this->m_Array = NULL;
		this->IsStudentFileEmpty = true;
		ifs1.close();
		return;
	}
	//3.文件存在，数据不为空
	int num = this->get_StudentNumber();
	this->StudentNum = num;
	//开辟空间
	this->m_Array = new Student * [this->StudentNum];
	//将文件数据存到数组中
	this->Init_Student();
	ifstream ifs2;
	ifs2.open(FILECOURSE, ios::in);
	if (!ifs2.is_open())//1.课程文件不存在
	{
		//初始化
		this->CourseNum = 0;
		this->m_CourseArray = NULL;
		this->IsCourseFileEmpty = true;
		ifs2.close();
		return;
	}
	//2.文件存在，数据为空
	char ch1;
	ifs2 >> ch1;
	if (ifs2.eof())
	{
		//文件为空

		this->CourseNum = 0;
		this->m_CourseArray = NULL;
		this->IsCourseFileEmpty = true;
		ifs2.close();
		return;
	}
	//3.文件存在，数据不为空
	int num1 = this->get_CourseNumber();
	this->CourseNum = num1;
	//开辟空间
	this->m_CourseArray = new Course * [this->CourseNum];
	//将文件数据存到数组中
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
		cout << "*********欢迎来到学生考勤系统**************" << endl;
		cout << "****     1.添加学生记录或缺课记录     *****" << endl;
		cout << "****	 2.查询学生或考勤信息         *****" << endl;
		cout << "****     3.显示学生信息和缺课信息     *****" << endl;
		cout << "****     4.修改学生信息和缺课信息     *****" << endl;
		cout << "****     5.删除学生信息               *****" << endl;
		cout << "****     6.考勤信息统计功能           *****" << endl;
		cout << "****     7.退出系统                   *****" << endl;
		cout << "*******************************************" << endl;
	}


void managersystem::exitsystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void managersystem::Add()
{
	int choose;
	cout << "请选择您要添加的内容：" << endl;
	cout << "1.学生信息" << endl;
	cout << "2.学生缺勤信息" << endl;
	cin >> choose;
	while (choose > 2 || choose < 1)
	{
		cout << "非法输入！请重新数入：" << endl;
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
	cout << "请选择性别：" << endl;
	cout << "1.男" << endl;
	cout << "2.女" << endl;
	cin >> number;
	while (number > 2 || number < 1)
	{
		cout << "非法输入！请重新输入：" << endl;
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
	cout << "请输入所要添加的学生个数：" << endl;
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
		cout << "请输入学生学号：" << endl;
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
					cout << "学号重复！请重新输入：" << endl;
					cin >> num;
					flag1 = 1;
					break;
				}
			}
		}
		cout << "请输入学生姓名：" << endl;
		string name;
		cin >> name;
		string sex;
		int n = this->GetSex();
		if (n == 1)
		{
			sex = "男";
		}
		else
		{
			sex = "女";
		}
		int age;
		cout << "请输入学生年龄：" << endl;
		cin >> age;
		string cl;
		cout << "请输入学生所在班级：" << endl;
		cin >> cl;
		Student* s1 = new Student(num, name, sex, age, cl);
		s[i] = s1;
		cout << "添加成功！" << endl;
	}

	this->StudentNum = Newsize;
	this->m_Array = s;
	this->GetInStudentFile();
	cout << "已添加" << number << "个学生！" << endl;
}

void managersystem::AddRecord()
{
	cout << "请输入缺课数量：" << endl;
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
		cout << "请输入缺课日期：" << endl;
		string date;
		cin >> date;
		cout << "请输入第几节课：" << endl;
		int num;
		cin >> num;
		cout << "请输入课程名称：" << endl;
		string cname;
		cin >> cname;
		cout << "请输入学生姓名：" << endl;
		string sname;
		cin >> sname;
		string type;
		int choice = this->GetType();
		switch (choice)
		{
		case 1:
		{
			type = "迟到";
			break;
		}
		case 2:
		{
			type = "早退";
			break;
		}
		case 3:
		{
			type = "请假";
			break;
		}
		case 4:
		{
			type = "旷课";
			break;
		}
		}
		Course* course = new Course(date, num, cname, sname, type);
		c[i] = course;
		cout << "成功添加！" << endl;
	}
	delete[]this->m_CourseArray;
	this->CourseNum = Newsize;
	this->m_CourseArray = c;
	this->GetInCourseFile();
	cout << "已成功添加" << num << "个记录！" << endl;
}


int managersystem::GetType()
{
	cout << "请选择缺课类型：" << endl;
	cout << "1.迟到" << endl;
	cout << "2.早退" << endl;
	cout << "3.请假" << endl;
	cout << "4.旷课" << endl;
	int choice;
	cin >> choice;
	while (choice > 4 || choice < 1)
	{
		cout << "输入有误！请重新输入：" << endl;
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
		cout << "该记录为空！" << endl;
		return;
	}
	cout << "请输入查找方式：" << endl;
	cout << "1.学号" << endl;
	cout << "2.姓名" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		cout << "请输入学号：" << endl;
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
			cout << "未找到该学生！" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "请输入姓名：" << endl;
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
			cout << "未找到该学生！" << endl;
		}
		break;
	}
	}
}


void managersystem::SearchCourse()
{
	if (this->IsCourseFileEmpty)
	{
		cout << "该记录为空！" << endl;
		return;
	}
	cout << "请输入查找方式："<<endl;
	cout << "1.课程名" << endl;
	cout << "2.学生名" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		cout << "请输入课程名称：" << endl;
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
			cout << "未找到该记录！" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "请输入学生名称：" << endl;
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
			cout << "未找到该记录！" << endl;
		}
		break;
	}
	}
}


void managersystem::Search()
{
	cout << "请输入查询的信息类别：" << endl;
	cout << "1.学生信息" << endl;
	cout << "2.课程信息" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "输入有误！请重新输入：" << endl;
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
	ifs.open(FILENAME, ios::in);//打开文件
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
	//关闭文件
	ifs.close();
}

int managersystem::get_CourseNumber()
{
	ifstream ifs;
	ifs.open(FILECOURSE, ios::in);//打开文件
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
	ifs.open(FILECOURSE, ios::in);//打开文件
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
	cout << "所有学生记录如下：" << endl;
	for(int i = 0; i < this->StudentNum; i++)
	{
		this->m_Array[i]->ShowStudent();
	}
	cout << endl << endl;
	cout << "所有考勤记录如下：" << endl;
	for (int i = 0; i < this->CourseNum; i++)
	{
		this->m_CourseArray[i]->ShowCourse();
	}
}

void managersystem::ChangeMessage()
{
	cout << "请输入您想修改的信息：" << endl;
	cout << "1.学生信息" << endl;
	cout << "2.考勤信息" << endl;
	int choice;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		if (this->IsStudentFileEmpty)
		{
			cout << "该记录为空！" << endl;
			return;
		}
		for (int i = 0; i < this->StudentNum; i++)
		{
			cout <<"["<< i << "]";
			this->m_Array[i]->ShowStudent();
		}
		cout << "请输入您想修改的内容序号：" << endl;
		int num;
		cin >> num;
		while (num > this->StudentNum||num<0)
		{
			cout << "输入非法！请重新输入" << endl;
		}
		cout << "请输入您想修改的内容序号："<<endl;
		cout << "[1]" << this->m_Array[num]->m_num << endl;
		cout << "[2]" << this->m_Array[num]->m_name << endl;
		cout << "[3]" << this->m_Array[num]->m_sex << endl;
		cout << "[4]" << this->m_Array[num]->m_age << endl;
		cout << "[5]" << this->m_Array[num]->m_class << endl;
		int number;
		cin >> number;
		while (number > 5 || number < 1)
		{
			cout << "非法输入！请重新输入：" << endl;
			cin >> number;
		}
		switch (number)
		{
		case 1:
		{
			cout << "请输入修改后的内容：" << endl;
			string NewNumber;
			cin >> NewNumber;
			this->m_Array[num]->m_num = NewNumber;
			break;
		}
		case 2:
		{
			cout << "请输入修改后的内容：" << endl;
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
				this->m_Array[num]->m_sex = "男";
			}
			if (aws == 2)
			{
				this->m_Array[num]->m_sex = "女";
			}
			break;
		}
		case 4:
		{
			cout << "请输入修改后的内容：" << endl;
			int NewAge;
			cin >> NewAge;
			this->m_Array[num]->m_age = NewAge;
			break;
		}
		case 5:
		{
			cout << "请输入修改后的内容：" << endl;
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
			cout << "该记录为空！" << endl;
			return;
		}
		for (int i = 0; i < this->CourseNum; i++)
		{
			cout <<"[" << i << "]";
			this->m_CourseArray[i]->ShowCourse();
		}
		cout << "请输入您想修改的内容序号：" << endl;
		int n;
		cin >> n;
		while (n > this->CourseNum || n < 0)
		{
			cout << "非法输入！请重新输入：" << endl;
			cin >> n;
		}
		cout << "[1]" << this->m_CourseArray[n]->m_date<<endl;
		cout << "[2]" << this->m_CourseArray[n]->m_num << endl;
		cout << "[3]" << this->m_CourseArray[n]->m_cname << endl;
		cout << "[4]" << this->m_CourseArray[n]->m_sname << endl;
		cout << "[5]" << this->m_CourseArray[n]->type << endl;
		cout << "请输入您想修改的内容序号：" << endl;
		int nn;
		cin >> nn;
		while (nn > 5 || nn < 1)
		{
			cout << "非法输入！请重新输入：" << endl;
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
				this->m_CourseArray[n]->type = "迟到";
			}
			if (nnn == 2)
			{
				this->m_CourseArray[n]->type = "早退";
			}
			if (nnn == 3)
			{
				this->m_CourseArray[n]->type = "请假";
			}
			if (nnn == 4)
			{
				this->m_CourseArray[n]->type = "旷课";
			}
			break;
		}
		}
		this->GetInCourseFile();
		break;
	}
	}
	cout << "修改成功！" << endl;
}

void managersystem::DeleteMessage()
{
	if (this->IsStudentFileEmpty)
	{
		cout << "该记录为空！" << endl;
		return;
	}
	cout << "所有学生记录如下：" << endl;
	for (int i = 0; i < this->StudentNum; i++)
	{
		cout << "[" << i << "]";
		this->m_Array[i]->ShowStudent();
	}
	cout << "请选择您要删除的记录序号：" << endl;
	int choice;
	cin >> choice;
	while (choice<0 || choice>=this->StudentNum)
	{
		cout << "非法输入！请重新输入：" << endl;
		cin >> choice;
	}
	delete this->m_Array[choice];
	for (int i = choice; i < this->StudentNum-1; i++)
	{
		this->m_Array[i] = this->m_Array[i + 1];
	}
	this->StudentNum--;
	this->GetInStudentFile();
	cout << "删除成功！" << endl;
}

void managersystem::Count()
{
	if (this->IsCourseFileEmpty)
	{
		cout << "该记录为空!" << endl;
		return;
	}
	cout << "请选择统计的参数：" << endl;
	cout << "1.课程名" << endl;
	cout << "2.姓名" << endl;
	int c;
	cin >> c;
	while (c<1||c>2)
	{
		cout << "非法输入！请重新输入：" << endl;
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
		cout << "请输入选项：" << endl;
		int n;
		cin >> n;
		while (n >= this->CourseNum || n < 0)
		{
			cout << "非法输入！请重新输入：" << endl;
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
		cout << "请输入选项：" << endl;
		int n;
		cin >> n;
		while (n >= this->CourseNum || n < 0)
		{
			cout << "非法输入！请重新输入：" << endl;
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