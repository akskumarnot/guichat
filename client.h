#ifndef CLIENT_H
#define CLIENT_H

#include<QThread>
#include<QTcpSocket>

class client:public QThread
{
Q_OBJECT
public:
client(QString windowname,QString ip);

public slots:
void tookthis(QString);
void dosomething();
public:
QTcpSocket *cli;

signals:
void sendtomain(QString);

protected:
void run();
};

#endif

