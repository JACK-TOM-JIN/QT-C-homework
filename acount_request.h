#ifndef ACOUNT_REQUEST_H
#define ACOUNT_REQUEST_H

#include <QWidget>

namespace Ui {
class acount_request;
}

class acount_request : public QWidget
{
    Q_OBJECT

public:
    explicit acount_request(QWidget *parent = nullptr);
    ~acount_request();

private:
    Ui::acount_request *ui;
};

#endif // ACOUNT_REQUEST_H
