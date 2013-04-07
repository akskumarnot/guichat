#ifndef LOGIN_H
#define LOGIN_H
#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTcpSocket>
#include"join.h"

class login:public QWidget
{
Q_OBJECT
public:
login(QWidget *parent=0);

private:
QString person_name;
QLineEdit *nickname;
QLineEdit *password;
QLabel *tuxy;
QLabel *nick_lab;
QLabel *title;
QLabel *pass_lab;
QPushButton *pb;
join *j;
public slots:
void dosomething();
void readyRead();
protected:

void mousePressEvent(QMouseEvent*);
void mouseReleaseEvent(QMouseEvent*);
void mouseMoveEvent(QMouseEvent *e);
};
#endif
