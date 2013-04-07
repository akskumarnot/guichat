#include"client.h"
#include<QDebug>
#include<QByteArray>
#include<QDataStream>
#include<QStringList>
#include"pm.h"

extern QString naam;
client::client(QString windowname,QString ip,QWidget *master)
{
this->master=master;
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
QByteArray arr=cli->readAll();
QString str(arr);

if(str.left(6)=="$room$")
{
	QStringList abc=str.split("$");
	emit sendtomain(abc.at(2));
	emit peoplenamesedit(abc.at(2));
	return;
}

if(str.left(7)=="$names$")
	{
	emit peoplenames(str);
	return;
	}

if(str.left(12)=="$pm$openbox$")
	{	
		QStringList abc=str.split("$");
		pm *p=new pm(abc.at(4),abc.at(5),1,abc.at(3),this->master);
		p->show();
		return;
	}

emit sendtomain(str);
cli->flush();
}





