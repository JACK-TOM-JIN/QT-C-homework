#include "widget.h"


Widget::Widget(Student* student,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->student = student;
    int* i=new int(0);
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"学院"<<"课程类别"<<"应修学分"<<"本次选课应选学分");
    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"课程"<<"学分"<<"课程类别"<<"开课学院");
    ui->tableWidget_3->setColumnCount(5);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList()<<"学号"<<"我的选课"<<"学分"<<"课程类别"<<"可选学院");
    ui->tableWidget_4->setColumnCount(6);
    ui->tableWidget_4->setHorizontalHeaderLabels(QStringList()<<"学号"<<"课程名称"<<"课程学分"<<"课程类别"<<"开课学院"<<"课程成绩");
    connect(ui->pushButton_exit,&QPushButton::clicked,[=](){
        if(main_credit>0 || core_credit>0)
        {
            if(QMessageBox::question(this,"question","您未完成本次选课要求,是否退出系统",QMessageBox::Ok|QMessageBox::No) == QMessageBox::Ok)
            {
                this->save();
                this->close();
            };
        }
        else
        {
            this->save();
            this->close();
        };
    });
    connect(ui->pushButton_nextpage,&QPushButton::clicked,[=](){
        if(*i>0)
        {
            *i = *i -1;
            ui->tabWidget->setCurrentIndex(*i);
        }
    });
    connect(ui->pushButton_upperpage,&QPushButton::clicked,[=](){
        if(*i<3)
        {
            *i = *i + 1;
            ui->tabWidget->setCurrentIndex(*i);
        }
    });
    connect(ui->pushButton_2_ok,&QPushButton::clicked,[=](){
        if(this->student->coursesInfo.size() == 0)
        {
            QMessageBox::critical(this,"critical","无课程可选");
        }
        else
        {
            int row = -1;
            string course;
            row = ui->tableWidget_2->currentRow();
            course = ui->tableWidget_2->item(row,0)->text().toStdString();
            this->student->selectCoursesInfo[student->m_id].insert(pair<string,list<string>>(course,this->student->coursesInfo[course]));
            this->student->coursesInfo.erase(course);
            this->tableSetValue(this->student);
        }
    });
    connect(ui->pushButton_3_ok,&QPushButton::clicked,[=](){
        if(this->student->selectCoursesInfo[student->m_id].size() == 0)
        {
            QMessageBox::critical(this,"critical","无课程可退");
        }
        else
        {
            int row = -1;
            string course;
            row = ui->tableWidget_3->currentRow();
            course = ui->tableWidget_3->item(row,1)->text().toStdString();
            this->student->coursesInfo.insert(pair<string,list<string>>(course,this->student->selectCoursesInfo[student->m_id][course]));
            this->student->selectCoursesInfo[student->m_id].erase(course);
            this->tableSetValue(this->student);
        }
    });
    connect(ui->pushButton_help,&QPushButton::clicked,[=](){
        QMessageBox::information(this,"information","有事请拨打1xxxxxxx致电教务处咨询");
    });
}

void Widget::tableSetValue(Student* student)
{

    main_credit = 0 ;
    core_credit = 0 ;
    int row = 0,i = 0,j = 0;
    row = student->plan[student->m_college].size();
    ui->tableWidget->setRowCount(row);
    for (map<string, int>::iterator it = student->plan[student->m_college].begin(); it != student->plan[student->m_college].end(); it++)
    {
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::fromStdString(student->m_college)));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(it->first)));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(it->second,10)));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString::number(it->second-student->credit[it->first],10)));
        if(it->first == "Maincourse"){ main_credit = it->second-student->credit[it->first]; }
        else if(it->first == "Corecourse"){ core_credit = it->second-student->credit[it->first]; }
        i++;
    }

    i = 0;
    row = student->coursesInfo.size();
    ui->tableWidget_2->setRowCount(row);
    for (map<string, list<string>>::iterator it = student->coursesInfo.begin(); it != student->coursesInfo.end(); it++)
    {
        ui->tableWidget_2->setItem(i,0, new QTableWidgetItem(QString::fromStdString(it->first)));
        j = 1;
        for (list<string>::const_iterator its = it->second.begin(); its != it->second.end(); its++)
        {
            ui->tableWidget_2->setItem(i,j, new QTableWidgetItem(QString::fromStdString(*its)));
            j++;
        }
        i++;
    }

    i = 0;
    row = student->selectCoursesInfo[student->m_id].size();
    cout<<row<<endl;
    ui->tableWidget_3->setRowCount(row);
    for (map<string, list<string>>::iterator it = student->selectCoursesInfo[student->m_id].begin(); it != student->selectCoursesInfo[student->m_id].end(); it++)
    {
        ui->tableWidget_3->setItem(i,0, new QTableWidgetItem(QString::fromStdString(student->m_id)));
        ui->tableWidget_3->setItem(i,1, new QTableWidgetItem(QString::fromStdString(it->first)));

        if(ListAt(it->second,1) == "Maincourse")
        {
            main_credit =main_credit - atoi(ListAt(it->second,0).c_str());
        }
        else if(ListAt(it->second,1) == "Corecourse")
        {
            core_credit =core_credit - atoi(ListAt(it->second,0).c_str());
        }

        j = 2;
        for (list<string>::const_iterator its = it->second.begin(); its != it->second.end(); its++)
        {
            ui->tableWidget_3->setItem(i,j, new QTableWidgetItem(QString::fromStdString(*its)));
            j++;
        }
        i++;
    }
    if(main_credit<=0)
    {
        ui->lineEdit_main->setText(QString::number(main_credit)+"  Done");
    }
    else
    {
        ui->lineEdit_main->setText(QString::number(main_credit));
    }
    if(core_credit<=0)
    {
        ui->lineEdit_core->setText(QString::number(core_credit)+"  Done");
    }
    else
    {
        ui->lineEdit_core->setText(QString::number(core_credit));
    }

    i = 0;
    row = student->coursesScores[student->m_id].size();
    ui->tableWidget_4->setRowCount(row);
    for (map<string, list<string>>::iterator it = student->coursesScores[student->m_id].begin(); it != student->coursesScores[student->m_id].end(); it++)
    {
        ui->tableWidget_4->setItem(i,0, new QTableWidgetItem(QString::fromStdString(student->m_id)));
        ui->tableWidget_4->setItem(i,1, new QTableWidgetItem(QString::fromStdString(it->first)));
        j = 2;
        for (list<string>::const_iterator its = it->second.begin(); its != it->second.end(); its++)
        {
            ui->tableWidget_4->setItem(i,j, new QTableWidgetItem(QString::fromStdString(*its)));
            j++;
        }
        i++;
    }
}

Widget::~Widget()
{
    delete ui;
}

string Widget::ListAt(list<string> L,int index)
{
    int i = 0;
    for (list<string>::const_iterator it = L.begin(); it != L.end(); it++) {
        if(i == index)
        {
            return *it;
        }
        i++;
    }
    return "0";
}

void Widget::save()
{
    string f_id;
    string f_college;
    string f_coursetype;
    string f_credit;
    string f_course;

    ifstream ifs;
    ifs.open(COURSES_SELECT, ios::in);
    list<list<string>> txtfile;
    while (ifs >> f_id && ifs >> f_course && ifs >> f_credit && ifs >> f_coursetype && ifs >> f_college)
    {
        if(f_id != this->student->m_id)
        {
            list<string> temp;
            temp.push_back(f_id);
            temp.push_back(f_course);
            temp.push_back(f_credit);
            temp.push_back(f_coursetype);
            temp.push_back(f_college);
            txtfile.push_back(temp);
        }
    }

    cout<<"txtfile.size()"<<txtfile.size()<<endl;

    ifs.close();
    ofstream ofs;
    ofs.open(COURSES_SELECT, ios::trunc);
    for (list<list<string>>::const_iterator it = txtfile.begin(); it != txtfile.end(); it++) {
        for (list<string>::const_iterator its = it->begin(); its != it->end(); its++) {
            ofs<<" ";
            ofs << *its;
        }
        ofs <<endl;
    }

    cout<<"this->student->m_id"<<this->student->selectCoursesInfo[this->student->m_id].size()<<endl;

    for (map<string,list<string>>::iterator it = this->student->selectCoursesInfo[this->student->m_id].begin();it != this->student->selectCoursesInfo[this->student->m_id].end();it++)
    {
        ofs<<this->student->m_id<<endl;
        ofs<<" ";
        ofs<<it->first;
        for(list<string>::const_iterator its = it->second.begin();its != it->second.end();its++)
        {
            ofs<<" ";
            ofs<<*its;
        }
        ofs<<endl;
    }
    ofs.close();
}
