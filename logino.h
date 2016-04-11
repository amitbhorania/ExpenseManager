#ifndef LOGINO_H
#define LOGINO_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class Logino : public QDialog
{
    Q_OBJECT

public:
    Logino(QWidget* parent = 0);
    ~Logino();

private slots:
    void OnQuit();
    void OnLogin();

private:
    void reject();

    QLabel* userLabel;
    QLabel* passLabel;
    QLineEdit* userLineEdit;
    QLineEdit* passLineEdit;
    QPushButton* loginButton;
    QPushButton* quitButton;
};
#endif // LOGINO_H
