#include"login.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QSpacerItem>
#include<QMouseEvent>
#include<QDebug>
#include"want.h"


extern int n;
QString naam;int startx3,starty3;bool press3;

QTcpSocket *soc; extern QString req;

login::login(QWidget * parent):QWidget(parent)
{


setWindowFlags(Qt::SplashScreen);

j=NULL;
setFixedSize(250,400);
tuxy=new QLabel();
//
pb=new QPushButton("Sign in");
connect(pb,SIGNAL(clicked()),this,SLOT(dosomething()));
//
//color
	setWindowOpacity(0.9);
	QPalette pal=palette();	
	pal.setColor(QPalette::Window,QColor(0,0,0));
	pal.setColor(QPalette::WindowText,QColor(0,255,70));
	setPalette(pal);
//

	title=new QLabel("LUGM's Radium");
	title->setAlignment(Qt::AlignHCenter);
	title->setStyleSheet(QString("QLabel{color:rgb(0,255,70);background:black;}"));
QHBoxLayout *hlay=new QHBoxLayout();
hlay->addWidget(pb);
hlay->setAlignment(Qt::AlignJustify);
pb->setFixedSize(100,23);
pb->setStyleSheet("color:rgb(0,255,70);background-color:black;border:1px solid rgb(0,255,70);");
tuxy->setPixmap(QPixmap(":a.jpg"));
nick_lab=new QLabel("<p style='color:rgb(0,255,70)'>Nickname</p>");
pass_lab=new QLabel("<p style='color:rgb(0,255,70)'>Password</p>");
nickname=new QLineEdit();
nickname->setStyleSheet(QString("background:black;border:2px solid green;color:rgb(0,255,70);"));
password=new QLineEdit();
password->setEchoMode(QLineEdit::Password);
password->setStyleSheet(QString("background:black;border:2px solid green;color:rgb(0,255,70);"));
QVBoxLayout *vlay=new QVBoxLayout();
vlay->addWidget(title);
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

//later
 soc=new QTcpSocket();
	connect(soc,SIGNAL(readyRead()),this,SLOT(readyRead()));
	  soc->connectToHost("localhost",9982);
}

//move code start


void login::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press3=false;
}


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



press3=true;
startx3=e->globalX();
starty3=e->globalY();

}




void login::mouseMoveEvent(QMouseEvent *e)
{
if(press3==true)
 {
int dx=e->globalX()-startx3;
int dy=e->globalY()-starty3;

startx3=e->globalX();
starty3=e->globalY();
move(x()+dx,y()+dy);
 }

}




//move code over

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



