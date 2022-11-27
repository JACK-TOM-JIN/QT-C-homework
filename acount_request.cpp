#include "acount_request.h"
#include "ui_acount_request.h"

acount_request::acount_request(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::acount_request)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Mechanical");
    ui->comboBox->addItem("Art");
    ui->comboBox->addItem("Physics");
}

acount_request::~acount_request()
{
    delete ui;
}
