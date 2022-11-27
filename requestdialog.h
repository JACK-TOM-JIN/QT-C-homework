#ifndef REQUESTDIALOG_H
#define REQUESTDIALOG_H

#include <QDialog>
#include "GetFile.h"

namespace Ui {
class RequestDialog;
}

class RequestDialog : public QDialog,public GetFile
{
    Q_OBJECT

public:
    explicit RequestDialog(QWidget *parent = nullptr);
    ~RequestDialog();

private:
    QString m_id;
    QString m_pwd;
    QString m_name;
    QString m_tel;
    QString m_sid;
    QString m_college;
    Ui::RequestDialog *ui;
};

#endif // REQUESTDIALOG_H
