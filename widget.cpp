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
    int a,b,c,d;
    int tmp=0;
    a = money/500;
    tmp = money%500;
    b = tmp/100;
    tmp = tmp%100;
    c = tmp/50;
    tmp = tmp%50;
    d = tmp/10;


    QString str;
    \
    str = QString("=============Change============\n\ 500won : %1\n\ 100won : %2\n\ 50won : %3\n\ 10won : %4")
                  .arg(QString::number(a),
                       QString::number(b),
                       QString::number(c),
                       QString::number(d));

            QMessageBox::information(nullptr,"Change",str);

    money=0;
    changeMoney(money);



}
