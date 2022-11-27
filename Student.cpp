#include "Student.h"

Student::Student(string id,string pwd)
{
	this->m_id = id;
	this->m_pwd = pwd;
	this->login_init();
	this->Login = loginAccounts.size();
}

void Student::login_init()
{
	string f_id;
	string f_password;
	string f_name;
	string f_college;
	string f_coursetype;
	string f_credit;
	string f_course;
	string f_score;

    credit.insert(pair<string,int>("Maincourse",0));
    credit.insert(pair<string,int>("Corecourse",0));

	ifstream ifs;
	ifs.open(STUD_LOGIN, ios::in);
	while (ifs >> f_id && ifs >> f_password && ifs >> f_name && ifs >> f_college)
	{

        if (f_id == m_id && f_password == m_pwd)
		{
			this->m_name = f_name;
			this->m_college = f_college;
			list<string> p;
			p.push_back(f_password);
			p.push_back(f_name);
			p.push_back(f_college);
            loginAccounts.insert(pair<string, list<string>>(m_id, p));
			break;
		}
	}
	ifs.close();
	if (loginAccounts.size() == 1)
	{
		ifs.open(COURSES_SCORE, ios::in);
        map<string,list<string>> course;
        while (ifs >> f_id && ifs >> f_course && ifs >> f_credit && ifs >> f_coursetype && ifs >> f_college && ifs >> f_score)
		{
			if (f_id == m_id)
			{
                list<string> p;
                p.push_back(f_credit);
                p.push_back(f_coursetype);
                p.push_back(f_college);
                p.push_back(f_score);
                credit[f_coursetype] += atoi(f_credit.c_str());
                course.insert(pair<string,list<string>>(f_course,p));

			}
		}
        coursesScores.insert(pair<string, map<string,list<string>>>(m_id, course));
		ifs.close();

		ifs.open(COURSES_SELECT, ios::in);
        {
            map<string,list<string>> q;
            while (ifs >> f_id && ifs >> f_course && ifs >> f_credit && ifs >> f_coursetype && ifs >> f_college)
			{
				if (f_id == m_id)
				{
                    list<string> p;
                    p.push_back(f_credit);
                    p.push_back(f_coursetype);
                    p.push_back(f_college);
                    q.insert(pair<string,list<string>>(f_course,p));
				}
			}
            selectCoursesInfo.insert(pair<string, map<string,list<string>>>(m_id, q));
			ifs.close();
		}

        ifs.open(COURSES_INFO, ios::in);
        while (ifs >> f_course && ifs >> f_credit && ifs >> f_coursetype && ifs >> f_college)
        {
            if (f_college == m_college && (selectCoursesInfo[m_id].find(f_course) == selectCoursesInfo[m_id].end()))
            {
                list<string> p;
                p.push_back(f_credit);
                p.push_back(f_coursetype);
                p.push_back(f_college);
                coursesInfo.insert(pair<string, list<string>>(f_course, p));
            }
        }
        ifs.close();

        ifs.open(CULTIVRATE_PLANE, ios::in);
		{
			list<string> p;
			while (ifs >> f_college && ifs >> f_coursetype && ifs >> f_credit)
			{
				if (f_college == m_college)
				{
					if (plan.find(f_college) == plan.end())
					{
						map<string, int> p;
                        plan.insert(pair<string, map<string, int>>(f_college, p));
					}
					if (plan[f_college].find(f_coursetype) == plan[f_college].end())
					{
						plan[f_college].insert(pair<string, int>(f_coursetype, 0));
					}
					plan[f_college][f_coursetype] = plan[f_college][f_coursetype] + atoi(f_credit.c_str());
				}
			}
		}
		ifs.close();
	}
}
