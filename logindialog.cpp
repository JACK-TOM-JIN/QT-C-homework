#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->radioButton_stud->setChecked(1);

    this->m_ident = "Student";
    connect(ui->pushButton_login,&QPushButton::clicked,[=](){
        m_id = ui->lineEdit_id->text();
        m_pwd = ui->lineEdit_pwd->text();
        if(this->Check(this->m_id, this->m_pwd, this->m_ident)==0)
        {
            QMessageBox::critical(this,"critical","信息输入有误");
        }
        else
        {
            this->close();
        }
    });
    connect(ui->pushButton_exit,&QPushButton::clicked,[=](){
        this->close();
    });
    connect(ui->radioButton_stud,&QPushButton::clicked,[=](){
         this->m_ident =  "Student";
    });
    connect(ui->radioButton_mana,&QPushButton::clicked,[=](){
         this->m_ident =  "Manager";
    });
    connect(ui->pushButton_request,&QPushButton::clicked,[=](){
        RequestDialog* a = new RequestDialog(this);
        a->exec();



    });
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

int LoginDialog::Check(QString id, QString pwd, QString ident)
{
    if(ident == "Student")
    {
        student = Student(id.toStdString(),pwd.toStdString());
        state = student.loginAccounts.size();
        return state;

    }
    else if(ident == "Manager")
    {
        cout<<"manager"<<endl;
        manager = Manager(id.toStdString(),pwd.toStdString());
        state = manager.loginAccounts.size();
        cout<<manager.loginAccounts.size()<<endl;
        return state;

    }
    else
    {
        QMessageBox::critical(this,"critical","信息选择登录身份");
        return 0;
    }
}
