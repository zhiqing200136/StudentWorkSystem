#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	Student(string num, string name, string sex, int age, string cl);//输入学生信息
	
	void ShowStudent();//显示学生信息

	//信息
	string m_num;
	string m_name;
	string m_sex;
	int m_age;
	string m_class;
};