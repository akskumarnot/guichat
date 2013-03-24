#include"login.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QSpacerItem>
#include<QMouseEvent>
#include<QDebug>
#include"want.h"


extern int n;
QString naam;

QTcpSocket *soc; extern QString req;

login::login(QWidget * parent):QWidget(parent)
{
j=NULL;
setFixedSize(250,380);
tuxy=new QLabel();
//
pb=new QPushButton("Sign in");
connect(pb,SIGNAL(clicked()),this,SLOT(dosomething()));
//
QHBoxLayout *hlay=new QHBoxLayout();
hlay->addWidget(pb);
hlay->setAlignment(Qt::AlignJustify);
pb->setFixedSize(100,23);
pb->setStyleSheet("color:black;background-color:rgb(0,144,255);border-radius:5px;");
tuxy->setPixmap(QPixmap(":a.jpg"));
nick_lab=new QLabel("<p style='color:rgb(0,114,255)'>Nickname</p>");
pass_lab=new QLabel("<p style='color:rgb(0,114,255)'>Password</p>");
nickname=new QLineEdit();
password=new QLineEdit();
password->setEchoMode(QLineEdit::Password);
QVBoxLayout *vlay=new QVBoxLayout();
vlay->addWidget(tuxy);
tuxy->setFixedSize(350,350);
tuxy->setAlignment(Qt::AlignJustify);
tuxy->setMargin(30);
vlay->addWidget(nick_lab);
nick_lab->setIndent(65);
vlay->addWidget(nickname);
vlay->addWidget(pass_lab);
pass_lab->setIndent(65);
vlay->addWidget(password);
vlay->addLayout(hlay);
setLayout(vlay);
setWindowTitle("LUGM-chat client");
QPalette pal=palette();
pal.setColor(QPalette::Window,QColor(255,255,255));
setPalette(pal);
//later
 soc=new QTcpSocket();
	connect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));
	  soc->connectToHost("localhost",9982);
}

void login::mouseReleaseEvent(QMouseEvent* e)
{}

void login::mousePressEvent(QMouseEvent* e)
{
if(e->x()>62.5 && e->x()<187.5)
	{if(e->y()>60 && e->y()<165)
	{
		if(j==NULL)
		{disconnect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));
		j=new join(soc,this);
		j->show();
		}
		else
		{connect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));delete j;n=0;req="";j=NULL;}
	}	

	}
}

void login::dosomething()
	{if(j!=NULL){delete j;j=NULL;}
	person_name=nickname->text();
	 connect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));
	  if(soc->waitForConnected(10000))
  		{qDebug()<<"connected";
		 QByteArray arr;
		 arr.append("$signin$");
		 arr.append(nickname->text()+"$");
		 arr.append(password->text()+"$");
		 qDebug()<<QString(arr);	
		 soc->write(arr);	
		soc->flush();
		soc->waitForBytesWritten();	
		}
	  else
 		{qDebug()<<"not connecting";} 
	}

void login::readyRead()
	{   qDebug()<<"ready read first socket";
      		QByteArray arr=soc->readAll();
		QString str(arr);
                  if(str=="$invalid$")
			{
			   person_name="";
			   //show on label
			}
				
		  else if(str=="$valid$")
			{	naam=person_name;
				this->close();				
				want *w=new want(soc);
				disconnect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));
				w->request();
				w->show();
			}
			
	}



