#include "student.h"
#include "managersystem.h"
using namespace std;
Student::Student(string num, string name, string sex, int age, string cl)
{
	this->m_num = num;
	this->m_name = name;
	this->m_sex = sex;
	this->m_age = age;
	this->m_class = cl;
}

void Student::ShowStudent()
{
	cout << "ѧ�ţ�" << m_num << " "
		<< "������" << m_name << " "
		<< "�Ա�" << m_sex << " "
		<< "���䣺" << m_age << " "
		<< "�༶��" << m_class <<endl;
}