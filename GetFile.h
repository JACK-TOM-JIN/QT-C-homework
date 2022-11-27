#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "Identity.h"
#include "GlobalFile.h"

using namespace std;

class GetFile
{
public:
    GetFile() {};
public:
//学院 <类别，学分>
    map<string, map<string,int>> plan;
//课程，<学分，类别，学院>
    map<string, list<string>> coursesInfo;
//学号，<课程>
    map<string, map<string,list<string>>> selectCoursesInfo;
//学号，<课程，分数,等信息>
    map<string, map<string,list<string>>> coursesScores;
//账号，密码，姓名，学院
    map<string, list<string>> loginAccounts;
};

