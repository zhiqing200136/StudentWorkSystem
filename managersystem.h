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
	void menu();//�˵�

	void exitsystem();//�˳�ϵͳ

	void Add();//���ѧ��

	int GetSex();//��ȡ�Ա�

	void GetInStudentFile();//�����ѧ���ļ�

	void AddStudent();//���ѧ��

	void AddRecord();//���ȱ����Ϣ

	int GetType();//��ȡȱ����Ϣ

	void GetInCourseFile();//������γ��ļ�

	void SearchStudent();//��ѯѧ����Ϣ

	void SearchCourse();//��ѯ�γ���Ϣ

	void Search();//��ѯ��Ϣ

	int get_StudentNumber();//��ȡѧ������

	int get_CourseNumber();//��ȡ�γ�����

	void Init_Student();//��ʼ��ѧ����Ϣ

	void Init_Course();//��ʼ���γ���Ϣ

	void ShowMessage();//��ʾ������Ϣ

	void ChangeMessage();//�޸���Ϣ

	void DeleteMessage();//ɾ����Ϣ

	void Count();//ͳ�ƹ���

	int StudentNum;
	Student ** m_Array;
	Course** m_CourseArray;
	int CourseNum;
	bool IsStudentFileEmpty;
	bool IsCourseFileEmpty;
};