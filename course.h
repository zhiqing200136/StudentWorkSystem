#pragma once
#include<iostream>
#include <string>
using namespace std;

class Course {
public:
	Course(string date, int num, string cname, string sname, string type);


	void ShowCourse();//显示课程信息

	string m_date;
	int m_num;
	string m_cname;
	string m_sname;
	string type;
};