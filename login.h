#ifndef LOGIN_H
#define LOGIN_H
#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTcpSocket>
#include<QProgressBar>

class login:public QWidget
{
Q_OBJECT
public:
login(QWidget *parent=0);

private:
QLineEdit *nickname;
QLineEdit *password;
QLabel *tuxy;
QLabel *nick_lab;
QLabel *pass_lab;
QPushButton *pb;
QProgressBar *prog;

public slots:
void dosomething();
void readyRead();
protected:

void mousePressEvent(QMouseEvent*);
void mouseReleaseEvent(QMouseEvent*);
};
#endif
