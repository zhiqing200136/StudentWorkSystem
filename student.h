#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	Student(string num, string name, string sex, int age, string cl);//����ѧ����Ϣ
	
	void ShowStudent();//��ʾѧ����Ϣ

	//��Ϣ
	string m_num;
	string m_name;
	string m_sex;
	int m_age;
	string m_class;
};