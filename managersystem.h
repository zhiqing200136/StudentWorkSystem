#pragma once
#include"course.h"
#include "student.h"
#include<iostream>
#include<string>
#include<fstream>
#define FILENAME "student.txt"
#define FILECOURSE "course.txt"
using namespace std;


class managersystem {
public:
	managersystem();
	~managersystem();
	void menu();//菜单

	void exitsystem();//退出系统

	void Add();//添加学生

	int GetSex();//获取性别

	void GetInStudentFile();//输出到学生文件

	void AddStudent();//添加学生

	void AddRecord();//添加缺勤信息

	int GetType();//获取缺勤信息

	void GetInCourseFile();//输出到课程文件

	void SearchStudent();//查询学生信息

	void SearchCourse();//查询课程信息

	void Search();//查询信息

	int get_StudentNumber();//获取学生数量

	int get_CourseNumber();//获取课程数量

	void Init_Student();//初始化学生信息

	void Init_Course();//初始化课程信息

	void ShowMessage();//显示所有信息

	void ChangeMessage();//修改信息

	void DeleteMessage();//删除信息

	void Count();//统计功能

	int StudentNum;
	Student ** m_Array;
	Course** m_CourseArray;
	int CourseNum;
	bool IsStudentFileEmpty;
	bool IsCourseFileEmpty;
};