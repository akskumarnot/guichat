#include"join.h"
#include<QTimer>
#include<QPaintEvent>
#include<QPainter>
#include<QDebug>
#include<QEventLoop>
int n=0;

int startx1,starty1;bool press1=false;
QString req;

join::join(QTcpSocket *soc,QWidget *parent):QWidget(parent)
{

socket =soc;
req+="$signup";
nextb=new QPushButton();
nextb->setIcon(QIcon(":next.png"));
nextb->setIconSize(QSize(40,40));
nextb->setAutoFillBackground(true);
QHBoxLayout *center=new QHBoxLayout();
lab1=new QLabel();
lab1->setPixmap(QPixmap(":su.jpg"));
center->addWidget(lab1);
center->addWidget(nextb);
l=new QLabel("LUGM Chat client is a chat box that unlike social net sites gives you the channel to talk to people you dont know in MU.Continue this dialog by pushing the next button and end it by pushing Tux in the sigin dialog.");
QFont *font=new QFont();
font->setPixelSize(12);
l->setWordWrap(true);
l->setFont(*font);
center->setAlignment(Qt::AlignHCenter);
setFixedSize(310,200);
QPalette pal=palette();
pal.setColor(QPalette::Window,QColor(255,255,255));
this->setPalette(pal);
mainLayout =new QVBoxLayout();
mainLayout->addLayout(center);
mainLayout->addWidget(l);
setLayout(mainLayout);
connect(nextb,SIGNAL(clicked()),this,SLOT(redraw()));
setWindowFlags(Qt::SplashScreen);
connect(this,SIGNAL(adder(QString)),this,SLOT(constructString(QString)));
}


void join::redraw()
{n++;
switch(n)
	{
case 1: make_nick();
	qDebug()<<"made nick";
	break;
case 2:	qDebug()<<"staring fname"; 
	if(le->text()!="" && validator(le->text())==true)
	{emit adder(le->text());
	qDebug()<<"reached here";
	make_fname();}
	else
	{n--;}
	qDebug()<<"staring fname"; 
	break;
case 3:if(le->text()!="")
	{emit adder(le->text());
	make_pass();}
	else
	{n--;}
	break;
	}

}

void join::make_nick()
{
delete mainLayout;
delete l;
delete lab1;
delete nextb;
nextb=new QPushButton();
nextb->setIcon(QIcon(":next.png"));
nextb->setIconSize(QSize(40,40));
nextb->setAutoFillBackground(true);
nextb->setFixedSize(50,50);
//button
lab1=new QLabel();
QPixmap *pix=new QPixmap(QSize(150,125));
pix->load(":nick.jpg");
lab1->setPixmap(*pix);
//label with pic
le=new QLineEdit();
//line edit
mainLayout =new QVBoxLayout();
mainLayout->addWidget(nextb);
mainLayout->addWidget(le);
mainLayout->setAlignment(Qt::AlignHCenter);
lay1=new QHBoxLayout();
lay1->addWidget(lab1);
lay1->addLayout(mainLayout);
setLayout(lay1);
connect(nextb,SIGNAL(clicked()),this,SLOT(redraw()));
setFixedSize(250,170);
}

void join::make_fname()
{
delete mainLayout;
delete nextb;
delete lab1;
delete lay1;
delete le;
update();
nextb=new QPushButton();
nextb->setIcon(QIcon(":n.jpg"));
nextb->setIconSize(QSize(100,100));
nextb->setAutoFillBackground(true);
nextb->setFixedSize(50,50);
le=new QLineEdit();
mainLayout=new QVBoxLayout();
lay1=new QHBoxLayout();
lay1->addWidget(le);
lay1->addWidget(nextb);
mainLayout->addSpacing(45);
mainLayout->addLayout(lay1);
mainLayout->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);
le->setFixedSize(170,40);
setLayout(mainLayout);
connect(nextb,SIGNAL(clicked()),this,SLOT(redraw()));
}

void join::make_pass()
{
delete mainLayout;
delete nextb;
delete le;
update();
nextb=new QPushButton();
nextb->setIcon(QIcon(":next.png"));
nextb->setIconSize(QSize(40,40));
nextb->setAutoFillBackground(true);
nextb->setFixedSize(50,50);
lab1=new QLabel();
le=new QLineEdit();
le1=new QLineEdit();
QPixmap *pix=new QPixmap(QSize(150,125));
pix->load(":pass.jpg");
lab1->setPixmap(*pix);
mainLayout=new QVBoxLayout();
mainLayout->addWidget(le);
mainLayout->addWidget(le1);
lay1=new QHBoxLayout();
lay1->addWidget(lab1);
lay1->addLayout(mainLayout);
lay1->addWidget(nextb);
le->setEchoMode(QLineEdit::Password);
le1->setEchoMode(QLineEdit::Password);
setFixedSize(350,170);
setLayout(lay1);
connect(nextb,SIGNAL(clicked()),this,SLOT(emitter()));
}

void join::paintEvent(QPaintEvent *e)
{
if(n==2)
{QPixmap map(":fname.jpg");
QPainter painter;
painter.begin(this);
painter.drawPixmap(0,0,250,170,map);
painter.end();}
}

void join::mousePressEvent(QMouseEvent *e)
{
press1=true;
startx1=e->globalX();
starty1=e->globalY();
}

void join::mouseMoveEvent(QMouseEvent *e)
{
if(press1==true)
 {
int dx=e->globalX()-startx1;
int dy=e->globalY()-starty1;

startx1=e->globalX();
starty1=e->globalY();
move(x()+dx,y()+dy);
 }

}


void join::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press1=false;
}


void join::constructString(QString str)
{
qDebug()<<req;
req+="$"+str;
if(n==3)
{disconnect(this,SIGNAL(adder(QString)),this,SLOT(constructString(QString)));}
}

void join::emitter()
{
	if(le->text()==le1->text() && le->text()!="")
		{connect(this,SIGNAL(adder(QString)),this,SLOT(constructString(QString)));
		emit adder(le->text());
		make_congo();
		reg(req);			
		}
	else
		{
		}

}


void join::make_congo()
{
delete mainLayout;
delete lab1;
delete lay1;
delete le;
delete le1;
delete nextb;
lab1=new QLabel();
QPixmap *pix=new QPixmap(QSize(10,10));
pix->load(":smi.png");
lab1->setPixmap(*pix);
lab1->setFixedSize(300,300);
QStringList abc=req.split("$");
l=new QLabel("<b>Congratulations "+ abc.at(3) +" , sign up complete</b>.<br></br>Have a nice time and make new friends.");
QFont *font=new QFont();
font->setPixelSize(12);
l->setWordWrap(true);
l->setFont(*font);
lay1=new QHBoxLayout();
lay1->addWidget(lab1);
lay1->addWidget(l);
setFixedSize(450,350);
setLayout(lay1);
}


bool join::validator(QString str)
{
QByteArray arr;
arr.append("$check$"+str+"$");
socket->write(arr);
socket->flush();
socket->waitForBytesWritten();
qDebug()<<"wrote";
QEventLoop loop;
connect(socket,SIGNAL(readyRead()),&loop,SLOT(quit()));
loop.exec();

qDebug()<<"pahunch gaya";
QByteArray a=socket->readAll();
	QString lol(a);

	if(lol=="$nonvalidated$")	
		{qDebug()<<false;return false;}
	if(lol=="$validated$")
		{qDebug()<<true;return true;}
qDebug()<<false;
return false;
}	


void join::reg(QString str)
{
connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
QByteArray arr;arr.append(str);
socket->write(arr);
socket->flush();
socket->waitForBytesWritten();
}

void join::readyRead()
{

}
