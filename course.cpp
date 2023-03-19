#include"course.h"

Course::Course(string date, int num, string cname, string sname, string type)
{
	this->m_date = date;
	this->m_cname = cname;
	this->m_num = num;
	this->m_sname = sname;
	this->type = type;
}
void Course::ShowCourse()
{
	cout << "日期：" << this->m_date<<" ";
	cout << "第几节课缺课：" << this->m_num<<" ";
	cout << "课程名称：" << this->m_cname << " ";
	cout << "学生姓名：" << this->m_sname << " ";
	cout << "缺课类型：" << this->type << endl;
}