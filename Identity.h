#pragma once
#include <iostream>
#include <string>
#include <map>
#include "GetFile.h"
using namespace std;

class Identity
{
public:
	string m_name;
	string m_id;
	string m_pwd;
    string m_college;
	bool Login =false;
    virtual void login_init(){};
};
