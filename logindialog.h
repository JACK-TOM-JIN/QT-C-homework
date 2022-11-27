#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "ui_logindialog.h"
#include "Student.h"
#include "Manager.h"
#include "requestdialog.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    QString m_id;
    QString m_pwd;
    QString m_ident;
    Student student;
    Manager manager;
    bool state = false;

    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    int Check(QString id, QString pwd, QString ident);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
