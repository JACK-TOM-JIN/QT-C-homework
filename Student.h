#pragma once
#include "GetFile.h"

class Student:public GetFile,public Identity
{
public:
    map<string,int> credit;
	Student() {};
    Student(string id, string pwd);
	void login_init();
};
