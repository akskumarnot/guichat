#include"client.h"
#include<QDebug>
#include<QByteArray>
#include<QDataStream>


client::client(QString ip)
{
cli=new QTcpSocket(this);
cli->connectToHost(ip,9982);

if(cli->waitForConnected(10000))
  {
connect(cli,SIGNAL(readyRead()),this,SLOT(dosomething()));
this->start();}
else
 {qDebug()<<"not connecting";}
}



void client::run()
{
qDebug()<<"hurrah got connection!!!";
exec();
}


void client::tookthis(QString str)
{  qDebug()<<str;
   cli->flush();
   QByteArray arr;
   arr.append(str);
  cli->write(arr);
   cli->flush();
 cli->waitForBytesWritten();
  
}


void client::dosomething()
{
QByteArray arr=cli->readAll();
QString str(arr);
emit sendtomain(str);
cli->flush();
}



