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

/**
 * 登录
 * @brief MainWindow::on_loginButton_clicked
 */
void MainWindow::on_loginButton_clicked()
{

    User *u = login::auth(this->uid, this->psw);
    if(u)
    {
        Dialog *d = new Dialog();
        d->user = u;
        d->exec();
        qDebug()<<u->getUsername();
    }
    else
    {
        QMessageBox::information(this, "提示", "登陆失败，请检查账号和密码！");
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

/**
 * 注册
 * @brief MainWindow::on_registButton_clicked
 */
void MainWindow::on_registButton_clicked()
{
    User *u = Regist::auth(this->newUsername, this->newPSW, this->againPSW);
    if(u)
    {
        Dialog d;
        d.user = u;
        d.exec();
        qDebug()<<u->getUsername();
    }
    else
    {
        QMessageBox::information(this, "提示", "注册失败！");
    }
}
