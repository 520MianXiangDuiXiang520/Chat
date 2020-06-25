#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QApplication>
#include "login.h"
#include "user.h"
#include "regist.h"
#include "dialog.h"
#include "listen.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_uidEdit_textEdited(const QString &arg1);

    void on_pswEdit_textEdited(const QString &arg1);

    void on_newUsername_textEdited(const QString &arg1);

    void on_newPSW_textEdited(const QString &arg1);

    void on_againPSW_textEdited(const QString &arg1);

    void on_registButton_clicked();

private:
    Ui::MainWindow *ui;
    QString uid;
    QString psw;
    QString newUsername;
    QString newPSW;
    QString againPSW;
    static void clean_child_process(int sig_number);
};
#endif // MAINWINDOW_H
