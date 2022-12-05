#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conversion.h"

//using namespace Ui;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_4->setAlignment(Qt::AlignCenter);

    QPalette palette;

    palette.setColor(ui->label_4->backgroundRole(), Qt::green);

    ui->label_4->hide();

    ui->label_2->setBuddy(ui->lineEdit_2);
    ui->label_3->setBuddy(ui->lineEdit_3);

    //const_cast<>

    ui->lineEdit->setValidator(new QIntValidator(0, 1000000, this));
    ui->lineEdit_2->setValidator(new QIntValidator(0, 1000000, this));
    ui->lineEdit_3->setValidator(new QIntValidator(0, 1000000, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    const QString str(conversion(ui));
    ui->label_4->setText(str);
    ui->label_4->setFrameShadow(QFrame::Sunken);
    ui->label_4->show();
}

