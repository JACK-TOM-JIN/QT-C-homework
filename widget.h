#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "ui_widget.h"
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    int main_credit = 0 ;
    int core_credit = 0 ;
    Widget(Student* student,QWidget *parent = nullptr);
    ~Widget();
    void tableSetValue(Student* student);
    Student* student;
    string ListAt(list<string> L,int index);
    void save();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
