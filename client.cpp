#include"client.h"
#include<QDebug>
#include<QByteArray>
#include<QDataStream>

extern QString naam;
client::client(QString windowname,QString ip)
{
cli=new QTcpSocket(this);
cli->connectToHost(ip,9982);

if(cli->waitForConnected(10000))
  {
connect(cli,SIGNAL(readyRead()),this,SLOT(dosomething()));
this->start();

QByteArray a;
a.append("$room$"+windowname+"$"+naam+"$");
cli->write(a);
cli->flush();
cli->waitForBytesWritten();
}
else
 {qDebug()<<"not connecting";}
}



void client::run()
{
qDebug()<<"hurrah got connection!!!";
exec();
}


void client::tookthis(QString str)
{ 
   QByteArray arr;
   arr.append("$message"+str);
  cli->write(arr);
   cli->flush();
 cli->waitForBytesWritten();
  
}


void client::dosomething()
{
qDebug()<<"got it here...yeah babydksjakdjksajdklasjkdjaskjlkdjklasjkldjlkas";
QByteArray arr=cli->readAll();
QString str(arr);
emit sendtomain(str);
cli->flush();
}





