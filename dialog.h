#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setMessage(QString mes);
    ~Dialog();

private slots:
    void on_textBrowser_textChanged();

private:
    Ui::Dialog *ui;
    QString message;
};

#endif // DIALOG_H
