#include "Manager.h"

Manager::Manager(string id, string pwd)
{
	this->m_id = id;
	this->m_pwd = pwd;
    this->login_init();


}
void Manager::login_init()
{
    string f_id;
    string f_password;
    string f_name;
    string f_college;
    string f_coursetype;
    string f_credit;
    string f_course;
    string f_score;

    ifstream ifs;
    ifs.open(MANA_LOGIN, ios::in);
    while (ifs >> f_id && ifs >> f_password && ifs >> f_name)
    {
        if (f_id == m_id && f_password == m_pwd)
        {
            this->m_name = f_name;
            list<string> p;
            p.push_back(f_password);
            p.push_back(f_name);
            loginAccounts.insert(pair<string, list<string>>(f_id, p));
            break;
        }
    }
    ifs.close();
//    if (loginAccounts.size() == 1)
//    {
//        ifs.open(COURSES_SCORE, ios::in);
//        while (ifs >> f_id && ifs >> f_course && ifs >> f_score)
//        {
//            if (coursesScores.find(f_id) == coursesScores.end())
//            {
//                map<string, string>p;
//                coursesScores.insert(pair<string, map<string, string>>(f_id, p));
//            }
//            coursesScores[f_id].insert(pair<string, string>(f_course, f_score));
//        }
//        ifs.close();


//        ifs.open(COURSES_INFO, ios::in);
//        while (ifs >> f_course && ifs >> f_credit && ifs >> f_coursetype && ifs >> f_college)
//        {
//            list<string> p;
//            p.push_back(f_credit);
//            p.push_back(f_coursetype);
//            p.push_back(f_college);
//            coursesInfo.insert(pair<string, list<string>>(f_course, p));
//        }
//        ifs.close();


//        ifs.open(COURSES_SELECT, ios::in);
//        {
//            while (ifs >> f_id && ifs >> f_course)
//            {
//                if (selectCoursesInfo.find(f_id) == selectCoursesInfo.end())
//                {
//                    list<string> p;
//                    selectCoursesInfo.insert(pair<string, list<string>>(f_id, p));
//                }
//                selectCoursesInfo[f_id].push_back(f_course);
//            }
//            ifs.close();
//        }


//        ifs.open(CULTIVRATE_PLANE, ios::in);
//        {
//            list<string> p;
//            while (ifs >> f_college && ifs >> f_coursetype && ifs >> f_credit)
//            {
//                if (plan.find(f_college) == plan.end())
//                {
//                    map<string,int> p;
//                    plan.insert(pair<string, map<string, int>>(f_college, p));
//                }
//                if (plan[f_college].find(f_coursetype) == plan[f_college].end())
//                {
//                    plan[f_college].insert(pair<string, int>(f_coursetype, 0));
//                }
//                plan[f_college][f_coursetype] = plan[f_college][f_coursetype] + atoi(f_credit.c_str());

//            }
//        }
//        ifs.close();
//    }
}

