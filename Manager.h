#pragma once
#include "GetFile.h"

class Manager :public GetFile,public Identity
{
public:
	Manager() {};
	Manager(string id,string pwd);
	void login_init();
};
