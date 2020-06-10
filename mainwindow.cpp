#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QToolBar>
#include <QMenuBar>
#include <QLabel>
#include <QStatusBar>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    utils::connMysql();
    QMenuBar * menu = menuBar();
    setMenuBar(menu);
    QMenu * fileMenu = menu->addMenu("文件");

    fileMenu->addAction("打开");
//    fileMenu->addSeparator();
//    fileMenu->addAction("新建");
    QToolBar *bar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, bar);
    bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    bar->setFloatable(false);
    QAction *friends = bar->addAction("好友列表");


    //状态类
    QStatusBar *statuBar = statusBar();

    QLabel *label1 = new QLabel("JuneChat 1.0.0", this);
    label1->setText("JuneChat 1.0.0");
    statuBar->addWidget(label1);
    QLabel *label = new QLabel("Power By QT", this);
    label->setText("Power By QT");
    statuBar->addPermanentWidget(label);
    setStatusBar(statuBar);


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{

    User *u = login::auth(this->uid, this->psw);
    if(u)
    {
        qDebug()<<u->getUsername();
    }
    else
    {
        qDebug()<<"登陆失败！";
    }
}

void MainWindow::on_uidEdit_textEdited(const QString &arg1)
{
    this->uid = arg1;
}

void MainWindow::on_pswEdit_textEdited(const QString &arg1)
{
    this->psw = arg1;
}

void MainWindow::on_newUsername_textEdited(const QString &arg1)
{
    this->newUsername = arg1;
}

void MainWindow::on_newPSW_textEdited(const QString &arg1)
{
    this->newPSW = arg1;
}

void MainWindow::on_againPSW_textEdited(const QString &arg1)
{
    this->againPSW = arg1;
}

void MainWindow::on_registButton_clicked()
{

}