#include "widget_mana.h"
#include "ui_widget_mana.h"

widget_mana::widget_mana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_mana)
{
    ui->setupUi(this);
    connect(ui->pushButton_exit,&QPushButton::clicked,[=](){
        this->close();
    });
}

widget_mana::~widget_mana()
{
    delete ui;
}
