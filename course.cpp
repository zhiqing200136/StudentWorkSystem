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
	cout << "���ڣ�" << this->m_date<<" ";
	cout << "�ڼ��ڿ�ȱ�Σ�" << this->m_num<<" ";
	cout << "�γ����ƣ�" << this->m_cname << " ";
	cout << "ѧ��������" << this->m_sname << " ";
	cout << "ȱ�����ͣ�" << this->type << endl;
}