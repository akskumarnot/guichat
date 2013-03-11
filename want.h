#ifndef WANT_H
#define WANT_H
#include<QWidget>
#include<QPushButton>
#include<QListView>
#include<QTcpSocket>
#include"ui.h"

class want:public QWidget
{
Q_OBJECT
public:
want(QTcpSocket * soc,QWidget *parent=0);
void request();
void arrange(QString);
public slots:
void readyRead();
void clearAll();
void dothehonors();
void ui_closing();
private:
QPushButton *choose;
QPushButton *update;
QTcpSocket *socket;
QListView *view;
ui **bit;
};
#endif
