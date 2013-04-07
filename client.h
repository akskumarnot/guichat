#ifndef CLIENT_H
#define CLIENT_H

#include<QThread>
#include<QTcpSocket>

class client:public QThread
{
Q_OBJECT
QWidget *master;
public:
client(QString windowname,QString ip,QWidget * master);

public slots:
void tookthis(QString);
void dosomething();
public:
QTcpSocket *cli;

signals:
void sendtomain(QString);
void peoplenames(QString);
void peoplenamesedit(QString);
protected:
void run();
};

#endif

