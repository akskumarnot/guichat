#include "pm.h"
#include<QKeyEvent>
#include<QTime>

bool press4;int startx4,starty4;extern QString naam;extern QString baba;
pm::pm(QString gpname,QString per,int mode,QString id,QWidget *parent):QWidget(parent)
	{
	socket=NULL;
	this->gpname=gpname;
	this->person=per;
	setWindowTitle(id);
	this->mode=mode;
	title = new QLabel("|"+ person + "|");
	title->setStyleSheet(QString("color:rgb(0,255,70);"));
	setWindowFlags(Qt::SplashScreen);
	setStyleSheet(QString("background:black;"));
	setWindowOpacity(0.8);
	setFixedSize(280,360);
	arrange();
	setUp();
	}

void pm::arrange()
	{
		le=new QLineEdit();
		te=new QTextEdit();
		te->zoomOut(2);
		le->setFixedSize(260,40);
		te->setFixedSize(260,250);
		te->setStyleSheet(QString("border:2px solid rgb(0,255,70);color:rgb(0,255,70);border-radius:10px;"));
		te->setReadOnly(true);
		mainLayout = new QVBoxLayout();
		title->setAlignment(Qt::AlignHCenter);
		le->setStyleSheet(QString("border:2px solid rgb(0,255,70);color:rgb(0,255,70);border-radius:10px;"));
		mainLayout->addWidget(title);
		mainLayout->addWidget(te);
		mainLayout->addWidget(le);
		setLayout(mainLayout);
	}



void pm::setUp(){
if(socket == NULL)
	{socket = new QTcpSocket();
	socket->connectToHost(baba,9982);
	qDebug()<<"got the connection for private";
	if(socket->waitForConnected(5000))
		{
			qDebug()<<"trying connection for private";
			connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
			QByteArray arr;

			if(mode==0)
				{arr.append("$pm$request$"+gpname+"$"+naam+"$"+person);}
			else
				{arr.append("$pm$addthisbox$"+windowTitle());}
				qDebug()<<"$pm$addthisbox$"<<windowTitle();
			socket->write(arr);
			socket->flush();
			socket->waitForBytesWritten();
			qDebug()<<"should have sent request";
		}
	}
}

void pm::readyRead()
	{
		QString str=socket->readAll();
		QStringList abc=str.split("$");
		if(str.left(7)=="$pm$id$")		
			{
				setWindowTitle(abc.at(3));
				return;
			}
			
			qDebug()<<"maybe for displayinhhh";
		if(str.left(12)=="$pm$message$")
			{
				te->append(QTime::currentTime().toString("h:m:s ap")+"  "+person+"  : "+abc.at(3)+"\n");
			}
		
	}


void pm::mouseReleaseEvent(QMouseEvent *e){
Q_UNUSED(e);
press4=false;
}

void pm::mousePressEvent(QMouseEvent *e){
Q_UNUSED(e);
press4=true;
starty4=e->globalY();
startx4=e->globalX();

}

void pm::mouseMoveEvent(QMouseEvent *e){

	if(press4==true)
	{
	int dx=e->globalX()-startx4;
	int dy=e->globalY()-starty4;
	starty4=e->globalY();
	startx4=e->globalX();
	move(x()+dx,y()+dy);
	}
}

void pm::keyPressEvent(QKeyEvent *e)
	{
		if((le->hasFocus()==true) && (e->key()==Qt::Key_Return) && le->text()!="")
			{
								
				te->append(QTime::currentTime().toString("h:m:s ap")+"  Me :  "+le->text()+"\n");
				if(windowTitle()!="")
				{sendData(le->text());}
				le->setText("");	
			}
	}



void pm::sendData(QString str){

	QByteArray arr;
	arr.append("$pm$message$"+naam+"$"+person+"$"+str);
	socket->write(arr);
	socket->flush();
	socket->waitForBytesWritten();
}


void pm::closeEvent(QCloseEvent *e)
	{
		
	}


