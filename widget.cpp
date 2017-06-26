#include "widget.h"
#include "ui_widget.h"
#include "DBProcess.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CDBProcess db("sqlite");

    bool isOrcal=false;
    isOrcal = db.openDB("192.168.0.102","数据库名","用户名", "密码");
    if(!isOrcal)
    {
        QMessageBox::information(this,"f","失败");
    }
    else
    {
        QMessageBox::information(this,"f","成功");
    }
}

Widget::~Widget()
{
    delete ui;
}
