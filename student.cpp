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
	cout << "学号：" << m_num << " "
		<< "姓名：" << m_name << " "
		<< "性别：" << m_sex << " "
		<< "年龄：" << m_age << " "
		<< "班级：" << m_class <<endl;
}