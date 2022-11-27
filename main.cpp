#include "widget.h"
#include "logindialog.h"
#include "widget_mana.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    string m_id;
    string m_ident;
    string m_college;
    QApplication a(argc, argv);
    LoginDialog *b = new LoginDialog();
    b->exec();
    cout<<"b-state"<<b->state<<endl;
    if(!b->state)
    {
        return 0;
    }
    m_id = b->m_id.toStdString();
    m_ident = b->m_ident.toStdString();
    if(m_ident == "Student")
    {
        Student* student = & b->student;
        Widget w(student);
        w.tableSetValue(student);
        w.show();
        return a.exec();

    }
    else if(m_ident == "Manager")
    {
        Manager* manager = & b->manager;
        widget_mana w;
        w.show();
        return a.exec();
    }
    return a.exec();
}
