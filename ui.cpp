#include"ui.h"
#include<QScrollArea>
#include<QVBoxLayout>
#include<QSizePolicy>
#include<QKeyEvent>
#include<QDebug>


extern QString naam; 


int startx,starty;bool press=false;

ui::ui(QWidget *parent):QWidget(parent){}

ui::ui(QString str,QWidget *parent):QWidget(parent)
{
close1=new QPushButton();
QIcon *ic=new QIcon("close.png");
close1->setIconSize(QSize(60,60));
close1->setIcon(*ic);
close1->setStyleSheet("border-radius:10px");
connect(close1,SIGNAL(clicked()),this,SLOT(bye()));

ic=new QIcon("ref.png");
ref=new QPushButton();
ref->setIconSize(QSize(60,60));
ref->setIcon(*ic);
ref->setStyleSheet("border-radius:10px");
connect(ref,SIGNAL(clicked()),this,SLOT(newavatar()));
te=new QTextEdit(this);
te->setHtml("<h6 style='background:yellow;'></h6>");
te->setReadOnly(true);
le=new QLineEdit("default");
sender=NULL;
arrange();
policy();
setFixedSize(500,400);
setWindowTitle(str);
setWindowFlags(Qt::SplashScreen);
setWindowOpacity(0.9);
setWindowTitle(str);
//connect
sender=new client(windowTitle(),"localhost");
connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
}

void ui::arrange()
{
QVBoxLayout *lay=new QVBoxLayout(this);
QHBoxLayout *hlay=new QHBoxLayout();
hlay->addWidget(ref);
ref->setFixedSize(40,30);
hlay->addWidget(close1);
close1->setFixedSize(40,30);
hlay->setAlignment(Qt::AlignRight);
QVBoxLayout *vlay=new QVBoxLayout();
vlay->addWidget(te);
vlay->addWidget(le);
vlay->setAlignment(le,Qt::AlignHCenter);

lay->addLayout(hlay);
lay->addLayout(vlay);
setLayout(lay);
}

void ui::policy()
{
le->setFixedSize(450,30);
}

void ui::keyPressEvent(QKeyEvent *e)
{
if((le->hasFocus()==true) && (e->key()==Qt::Key_Return))
 { QString str=le->text();
   if(str.left(8)=="$connect") 
    {int i;
    	 for(i=8;(i<str.length()) && (str[i]==' ');i++);
      		ip=str.mid(i,str.length());
    		 if(ip=="")
      			 {te->append("\nthere dosent seem to be anything");
    			 le->setText("");
                         }
     		 else 
    		 {
       			/*if(sender==NULL)
        			 { sender=new client(ip);
				   connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
                                   connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
                                  }
      			 else
         			{te->append("\nalready connected to server");}*/
                 }

       le->setText("");
    }



  else{
   QColor color(te->textColor());
   QColor c(0,114,255);
   te->setTextColor(c);
   te->append("\nMe:"+le->text());
   te ->setTextColor(color);
    if(sender!=NULL)
     {
     QString str=le->text();
      str.prepend("$"+windowTitle()+"$"+naam+"$");
      str.append("$");	
	qDebug()<<str;
      emit takethis(str);
     } 
   le->setText(""); 
  }      
 }

}

void ui::rAtMain(QString str)
{
qDebug()<<"reached here wow my name is Khan and i am not a terrorist";
QColor color(te->textColor());
QColor c(255,46,0);
te->setTextColor(c);
te->append("\n" + str);
te->setTextColor(color);
}



void ui::mousePressEvent(QMouseEvent *e)
{
press=true;
startx=e->globalX();
starty=e->globalY();
}

void ui::mouseMoveEvent(QMouseEvent *e)
{
if(press==true)
 {
int dx=e->globalX()-startx;
int dy=e->globalY()-starty;

startx=e->globalX();
starty=e->globalY();
move(x()+dx,y()+dy);
 }

}


void ui::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press=false;
}

void ui::bye()
{
this->close();
}

void ui::closeEvent(QCloseEvent *e){
emit closing();
qDebug()<<"request for delete";
QByteArray c;
c.append("$bye$"+ windowTitle()+"$"+ naam+"$");
qDebug()<<"$bye$"+ windowTitle()+"$"+ naam+"$";
sender->cli->write(c);
sender->cli->flush();
sender->cli->waitForBytesWritten();
}


void ui::newavatar()
{
delete sender;
te->append("reconnecting..");
sender=new client(windowTitle(),"localhost");
connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
te->append("Hurrah !!! reconnected");
}

