#pragma once
#include<iostream>
#include <string>
using namespace std;

class Course {
public:
	Course(string date, int num, string cname, string sname, string type);


	void ShowCourse();//��ʾ�γ���Ϣ

	string m_date;
	int m_num;
	string m_cname;
	string m_sname;
	string type;
};