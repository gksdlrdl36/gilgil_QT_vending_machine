#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoke->setEnabled(false);

    ui->pbTea->setEnabled(false);

    ui->pbCoffee->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;

    if(money<100)
    {
        ui->pbCoke->setEnabled(false);

        ui->pbTea->setEnabled(false);

        ui->pbCoffee->setEnabled(false);
    }
    else if(100<=money && money<150)
    {
        ui->pbCoke->setEnabled(false);

        ui->pbTea->setEnabled(false);

        ui->pbCoffee->setEnabled(true);
    }
    else if(150<=money && money<200)
    {
        ui->pbCoke->setEnabled(false);

        ui->pbTea->setEnabled(true);

        ui->pbCoffee->setEnabled(true);

    }
    else if(200<=money)
    {
        ui->pbCoke->setEnabled(true);

        ui->pbTea->setEnabled(true);

        ui->pbCoffee->setEnabled(true);
    }

    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);

}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}



void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    money=0;
    changeMoney(money);
}
