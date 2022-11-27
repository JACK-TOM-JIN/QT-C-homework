#include "requestdialog.h"
#include "ui_requestdialog.h"

RequestDialog::RequestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestDialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Mechanical");
    ui->comboBox->addItem("Art");
    connect(ui->pushButton,&QPushButton::clicked,[=](){

        cout<<"ccccccccc"<<endl;
        this->m_id   = ui->lineEdit->text();
        this->m_pwd  = ui->lineEdit_2->text();
        this->m_name = ui->lineEdit_3->text();
        this->m_tel  = ui->lineEdit_4->text();
        this->m_sid  = ui->lineEdit_5->text();
        this->m_college = ui->comboBox->currentText();

        ofstream ofs;
        ofs.open(ACOUNT_REQUEST, ios::app);
        ofs<<this->m_id.toStdString();
        ofs<<" ";
        ofs<<this->m_pwd.toStdString();
        ofs<<" ";
        ofs<<this->m_name.toStdString();
        ofs<<" ";
        ofs<<this->m_tel.toStdString();
        ofs<<" ";
        ofs<<this->m_sid.toStdString();
        ofs<<" ";
        ofs<<this->m_college.toStdString();
        ofs<<"\n";


        ofs.close();
        this->close();

    });
        connect(ui->pushButton_2,&QPushButton::clicked,[=](){
            this->close();
        });
}

RequestDialog::~RequestDialog()
{
    delete ui;
}
